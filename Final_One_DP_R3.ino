// Define motor control pins for L298N Motor Driver 1 Water Pump & Cooling Fan 
const int IN1A = 2;
const int IN2A = 3;
const int IN3A = 4;
const int IN4A = 5;

// Define motor control pins for L298N Motor Driver 2 Front Wheels
const int ENA3 = A0;
const int IN1C = A1;
const int IN2C = A2;
const int ENB3 = A3;
const int IN3C = A4;
const int IN4C = A5;

//Define relay pin
//Sweeping Roller
const int relayPin1 = 13;
//Mopping Disk
const int relayPin2 = 10;

// Define signal of Bluetooth controller
char data;

void setup() {
  // Initialize motor control pins as outputs
  Serial.begin(9600);
  pinMode(IN1A, OUTPUT);
  pinMode(IN2A, OUTPUT);
  pinMode(IN3A, OUTPUT);
  pinMode(IN4A, OUTPUT);

  pinMode(ENA3, OUTPUT);
  pinMode(IN1C, OUTPUT);
  pinMode(IN2C, OUTPUT);
  pinMode(ENB3, OUTPUT);
  pinMode(IN3C, OUTPUT);
  pinMode(IN4C, OUTPUT);

  pinMode(relayPin1, OUTPUT);
  digitalWrite(relayPin1, LOW);
  pinMode(relayPin2, OUTPUT);
  digitalWrite(relayPin2, LOW);
}

void loop() {
  // Check if there is any data received from the Bluetooth module
  if (Serial.available() >0) {
    // Read the incoming data
    data = Serial.read();

    // Print the received data to the serial monitor
    if (data == 'R') {
      Serial.println("Forward");
      moveForward();
    } 
    else if (data == 'G') {
      Serial.println("Backward");
      moveBackward();
    } 
    else if (data == 'B') {
      Serial.println("Turn_Right");
      turnRight();
    } 
    else if (data == 'Y') {
      Serial.println("Turn_Left");
      turnLeft();
    } 
    else if (data == 'D') {
      Serial.println("Start All");
      startAllMotors();
    }
    else if (data == 'C') {
      Serial.println("Cooling_Fan_On");
      coolingFan();
    }
    else if (data == 'c') {
      Serial.println("Cooling_Fan_Off");
      coolingFanOff();
    }
    else if (data == 'S') {
      Serial.println("Sweeping_Roller_On");
      sweepingRoller();
    }
    else if (data == 's') {
      Serial.println("Sweeping_Roller_Off");
      sweepingRollerOff();
    }
    else if (data == 'W') {
      Serial.println("Water_Pump_On");
      waterPump();
    }
    else if (data == 'w') {
      Serial.println("Waater_Pump_Off");
      waterPumpOff();
    }
    else if (data == 'T') {
      Serial.println("Mopping_Disk_On");
      moppingDisk();
    }
    else if (data == 't') {
      Serial.println("Mopping_Disk_Off");
      moppingDiskOff();
    }
    else if (data == 'A') {
      Serial.println("Autonomous Mode");
      //autonomousMode = !autonomousMode; // Toggle autonomous mode
    }
    else if (data == 'a') {
      Serial.println("Autonomous Mode Off");
      //autonomousMode = !autonomousMode; // Toggle autonomous mode
    }
    else if ((data == 'r') || (data == 'g') || (data == 'b') || (data == 'y')) {
      Serial.println("Stop All Wheels");
      stopAllWheels();
    }
    /*else if ((data == 'a') || (data == 'c') || (data == 's') || (data == 'w') || (data == 't')) {
      Serial.println("Stop All");
      stopAllMotors();
    }*/
    else if (data == 'd') {
      Serial.println("Stop All");
      stopAllMotors();
    }
  }
}

void moveForward(){
  // Motor Driver 2
  digitalWrite(IN1C, HIGH);
  digitalWrite(IN2C, LOW);
  analogWrite(ENA3, 255);
  
  digitalWrite(IN3C, HIGH);
  digitalWrite(IN4C, LOW);
  analogWrite(ENB3, 255);
}

void startAllMotors(){
  //Motion of the front
  //Motor Driver 1 
  digitalWrite(IN1A, HIGH);
  digitalWrite(IN2A, LOW);
  
  digitalWrite(IN3A, HIGH);
  digitalWrite(IN4A, LOW);

  //Relay
  digitalWrite(relayPin1, HIGH);
  digitalWrite(relayPin2, HIGH);
}

void moveBackward(){
  //Backward movement
  // Motor Driver 1
  digitalWrite(IN1A, LOW);
  digitalWrite(IN2A, LOW);
  
  digitalWrite(IN3A, LOW);
  digitalWrite(IN4A, LOW);

  // Motor Driver 2
  digitalWrite(IN1C, LOW);
  digitalWrite(IN2C, HIGH);
  analogWrite(ENA3, 255);
  
  digitalWrite(IN3C, LOW);
  digitalWrite(IN4C, HIGH);
  analogWrite(ENB3, 255);

  //Relay
  digitalWrite(relayPin1, LOW);
  digitalWrite(relayPin2, LOW);
}

void turnRight(){
  //Turn right side
  // Motor Driver 1
  digitalWrite(IN1A, LOW);
  digitalWrite(IN2A, LOW);
  
  digitalWrite(IN3A, LOW);
  digitalWrite(IN4A, LOW);

  // Motor Driver 2
  digitalWrite(IN1C, HIGH);
  digitalWrite(IN2C, LOW);
  //analogWrite(ENA3, 0);
  
  digitalWrite(IN3C, LOW);
  digitalWrite(IN4C, HIGH);
  //analogWrite(ENB3, 0);

  //Relay
  digitalWrite(relayPin1, LOW);
  digitalWrite(relayPin2, LOW);
}

void turnLeft(){
  //Turn right side
  // Motor Driver 1
  digitalWrite(IN1A, LOW);
  digitalWrite(IN2A, LOW);
  
  digitalWrite(IN3A, LOW);
  digitalWrite(IN4A, LOW);

  // Motor Driver 2
  digitalWrite(IN1C, LOW);
  digitalWrite(IN2C, HIGH);
  //analogWrite(ENA3, 0);
  
  digitalWrite(IN3C, HIGH);
  digitalWrite(IN4C, LOW);
  //analogWrite(ENB3, 0);

  //Relay
  digitalWrite(relayPin1, LOW);
  digitalWrite(relayPin2, LOW);
}

void stopAllWheels(){
  //Stop All Wheels
  // Motor Driver 2
  digitalWrite(IN1C, LOW);
  digitalWrite(IN2C, LOW);
  //analogWrite(ENA3, 0);
  
  digitalWrite(IN3C, LOW);
  digitalWrite(IN4C, LOW);
  //analogWrite(ENB3, 0);
}

void stopAllMotors(){
  //Stop All
  // Motor Driver 1
  digitalWrite(IN1A, LOW);
  digitalWrite(IN2A, LOW);
  
  digitalWrite(IN3A, LOW);
  digitalWrite(IN4A, LOW);

  // Motor Driver 2
  digitalWrite(IN1C, LOW);
  digitalWrite(IN2C, LOW);
  //analogWrite(ENA3, 0);
  
  digitalWrite(IN3C, LOW);
  digitalWrite(IN4C, LOW);
  //analogWrite(ENB3, 0);

  //Relay
  digitalWrite(relayPin1, LOW);
  digitalWrite(relayPin2, LOW);
}

void coolingFan() {
  digitalWrite(IN1A, HIGH);
  digitalWrite(IN2A, LOW);
}

void coolingFanOff() {
  digitalWrite(IN1A, LOW);
  digitalWrite(IN2A, LOW);
}

void sweepingRoller() {
  digitalWrite(relayPin1, HIGH);
}

void sweepingRollerOff() {
  digitalWrite(relayPin1, LOW);
}

void waterPump() {
  digitalWrite(IN3A, HIGH);
  digitalWrite(IN4A, LOW);
}

void waterPumpOff() {
  digitalWrite(IN3A, LOW);
  digitalWrite(IN4A, LOW);
}

void moppingDisk() {
  digitalWrite(relayPin2, HIGH);
}

void moppingDiskOff() {
  digitalWrite(relayPin2, LOW);
}
