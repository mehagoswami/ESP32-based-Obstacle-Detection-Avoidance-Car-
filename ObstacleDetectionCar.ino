#include <ESP32Servo.h>

#define IN1 14
#define IN2 27
#define IN3 26
#define IN4 25

#define TRIG 33
#define ECHO 32

Servo myServo;

int getDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH, 20000);
  int d = duration * 0.034 / 2;

  if (d < 3 || d > 200)
    return 100;

  return d;
}

void forwardSlow() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  delay(60);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  delay(40);
}

void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void reverseShort() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  delay(250);

  stopCar();
}

void setup() {
  Serial.begin(115200);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  myServo.attach(13);
  myServo.write(90);

  Serial.println("Obstacle Avoiding Car Started");
}

void loop() {

  forwardSlow();

  int front = getDistance();

  Serial.print("Front Distance: ");
  Serial.println(front);

  if (front < 30) {

    stopCar();
    delay(150);

    reverseShort();
    delay(150);

    // Scan Left
    myServo.write(180);
    delay(400);
    int leftDist = getDistance();

    // Scan Right
    myServo.write(0);
    delay(400);
    int rightDist = getDistance();

    // Center Servo
    myServo.write(90);
    delay(150);

    Serial.print("Left Distance: ");
    Serial.println(leftDist);

    Serial.print("Right Distance: ");
    Serial.println(rightDist);

    bool goLeft = (leftDist > rightDist);

    if (goLeft) {
      left();
      delay(400);
    } else {
      right();
      delay(400);
    }

    stopCar();
    delay(200);

    int frontCheck = getDistance();

    if (frontCheck < 30) {

      if (goLeft) {
        left();
        delay(250);
      } else {
        right();
        delay(250);
      }

      stopCar();
      delay(200);
    }
  }
}
