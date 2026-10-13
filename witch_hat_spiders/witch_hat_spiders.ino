
/*
  Witch Hat - Continuous Spider Movement

  Author: Alexis Evans
  
  Arduino Nano
  TB6612FNG Motor Driver
  Pololu 50:1 MP 6V Motor
  5:1 Printed Gear Reduction
  4 Spools on Shared Shaft
*/

const int PWM_PIN = 5;
const int AIN1_PIN = 6;
const int AIN2_PIN = 7;
const int STBY_PIN = 8;

// Adjustable settings
const int MOTOR_SPEED = 70;           // PWM: 0-255
const unsigned long DOWN_TIME = 6000; // 5 seconds
const unsigned long UP_TIME = 6000;   // 5 seconds
const unsigned long REVERSAL_DELAY = 200; // milliseconds

bool movingDown = true;
unsigned long lastChange = 0;

enum MotorState {
  MOVING,
  REVERSING
};

MotorState state = MOVING;

void motorForward() {
  analogWrite(PWM_PIN, 0);
  digitalWrite(AIN1_PIN, HIGH);
  digitalWrite(AIN2_PIN, LOW);
  analogWrite(PWM_PIN, MOTOR_SPEED);
}

void motorReverse() {
  analogWrite(PWM_PIN, 0);
  digitalWrite(AIN1_PIN, LOW);
  digitalWrite(AIN2_PIN, HIGH);
  analogWrite(PWM_PIN, MOTOR_SPEED);
}

void motorStop() {
  analogWrite(PWM_PIN, 0);
  digitalWrite(AIN1_PIN, LOW);
  digitalWrite(AIN2_PIN, LOW);
}

void setup() {
  pinMode(PWM_PIN, OUTPUT);
  pinMode(AIN1_PIN, OUTPUT);
  pinMode(AIN2_PIN, OUTPUT);
  pinMode(STBY_PIN, OUTPUT);

  motorStop();
  digitalWrite(STBY_PIN, HIGH);

  Serial.begin(9600);
  Serial.println("Witch Hat Spiders Starting!");

  movingDown = true;
  motorForward();
  lastChange = millis();
}

void loop() {
  unsigned long currentTime = millis();

  if (state == MOVING) {
    unsigned long travelTime =
        movingDown ? DOWN_TIME : UP_TIME;

    if (currentTime - lastChange >= travelTime) {
      motorStop();
      state = REVERSING;
      lastChange = currentTime;
    }
  }
  else if (state == REVERSING) {
    if (currentTime - lastChange >= REVERSAL_DELAY) {
      movingDown = !movingDown;

      if (movingDown) {
        motorForward();
        Serial.println("Spiders lowering");
      } else {
        motorReverse();
        Serial.println("Spiders raising");
      }

      state = MOVING;
      lastChange = currentTime;
    }
  }
}
