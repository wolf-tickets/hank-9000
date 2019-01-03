#define trigPinFwd 7
#define echoPinFwd 8
#define trigPinRight 2
#define echoPinRight 3
#define leftFwdPin 6
#define leftBackPin 5
#define rightFwdPin 10
#define rightBackPin 9

long getDistanceFwd() {
  long duration;
  digitalWrite(trigPinFwd, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPinFwd, LOW);
  return (((pulseIn(echoPinFwd, HIGH)) / 2) / 29.1);

}

long getDistanceRight() {
  long duration;
  digitalWrite(trigPinRight, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPinRight, LOW);
  return (((pulseIn(echoPinRight, HIGH)) / 2) / 29.1);

}

void goForward() {
  digitalWrite(leftFwdPin, HIGH);
  digitalWrite(rightFwdPin, HIGH);

}

void turnRight() {
  digitalWrite(leftFwdPin, LOW);
  digitalWrite(rightFwdPin, LOW);

  digitalWrite(rightBackPin, LOW);

  digitalWrite(rightFwdPin, HIGH);
  digitalWrite(leftBackPin, HIGH);

}
void turnLeft() {
  digitalWrite(rightFwdPin, LOW);
  digitalWrite(leftFwdPin, LOW);

  digitalWrite(leftBackPin, LOW);

  digitalWrite(leftFwdPin, HIGH);
  digitalWrite(rightBackPin, HIGH);
}


void setup() {
  pinMode(trigPinFwd, OUTPUT);
  pinMode(trigPinRight, OUTPUT);

  pinMode(leftFwdPin, OUTPUT);
  pinMode(leftBackPin, OUTPUT);
  pinMode(rightFwdPin, OUTPUT);
  pinMode(rightBackPin, OUTPUT);

  pinMode(echoPinFwd, INPUT);
  pinMode(echoPinRight, INPUT);
  digitalWrite(trigPinFwd, LOW);
  digitalWrite(trigPinRight, LOW);

  digitalWrite(leftFwdPin, LOW);
  digitalWrite(leftBackPin, LOW);
  digitalWrite(rightFwdPin, LOW);
  digitalWrite(rightBackPin, LOW);
  delay(5000);
  digitalWrite(rightFwdPin, HIGH);
  digitalWrite(leftBackPin, HIGH);

  delay(3000);

  digitalWrite(leftBackPin, LOW);


}

void loop() {

  goForward();

  if ((getDistanceFwd() <= 20) && (getDistanceRight() <= 10)) {

    while ((getDistanceFwd() <= 20) || (getDistanceRight() <= 10))  {
      turnLeft();
    }


  } else if (getDistanceRight() <= 10) {

    while (getDistanceRight() <= 10) {
      turnLeft();
    }
  } else if (getDistanceFwd() <= 20) {

    while (getDistanceFwd() <= 20)  {

      turnRight();
    }
  }

  digitalWrite(leftBackPin, LOW);
  digitalWrite(rightBackPin, LOW);



}
