/* File: RobotArm.ino
 * Controls a robot arm using keyboard input
 * Please make sure to run KeyPress.pde in Processing to read key input
 * Author: Antony Nguyen & Ysabelle Lam!
 */

#include <Servo.h>

// Declare a value to receive from Serial
char val;

// Declare values for constraints
int lowerConstraint = 10;
int upperConstraint = 170;

// TODO: Declare three servo objects

Servo servo1; //Servos
Servo servo2;
Servo servo3;

// Declare three angles
int bottomArmAngle, middleArmAngle, topArmAngle;

void setup() {

  // TODO: Attach the servos to three pins

  servo1.attach(5);
  //servo2.attach(6);
  //servo3.attach(9);

  // Set the default angle to 90
  bottomArmAngle = middleArmAngle = topArmAngle = 90;

  Serial.begin(9600);
}

void loop() {

  // Constrain the angles to be between certain angles
  bottomArmAngle = constrain(bottomArmAngle, lowerConstraint, upperConstraint);
  //middleArmAngle = constrain(middleArmAngle, lowerConstraint, upperConstraint);
  //topArmAngle = constrain(topArmAngle, lowerConstraint, upperConstraint);

  // Write each servos to the angles

  servo1.write(bottomArmAngle);
 // servo2.write(middleArmAngle);
 // servo3.write(topArmAngle);

  // Read the Serial input into val

  if(Serial.available()) {
    val = Serial.read();
  }

  // Check if the value is equal to keys, incrementing angles by 20 each time

  if (val == 'a'){
      bottomArmAngle+=20;
    }
    else if (val=='d'){
      bottomArmAngle-=20;
    }
    else if (val=='w'){
      middleArmAngle+=20;
    }
    else if (val=='s'){
      middleArmAngle-=20;
    }
    else if (val=='q'){
      topArmAngle+=20;
    }
    else if (val=='e'){
      topArmAngle-=20;
    }


  // Reset the value to 0 after it's read
  val = 0;
}
