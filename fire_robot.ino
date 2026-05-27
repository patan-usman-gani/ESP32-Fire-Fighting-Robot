#define FLAME_SENSOR 34
#define PUMP 26
#define MOTOR1 18
#define MOTOR2 19

void setup() {
  pinMode(PUMP, OUTPUT);
  pinMode(MOTOR1, OUTPUT);
  pinMode(MOTOR2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int flame = analogRead(FLAME_SENSOR);

  Serial.println(flame);

  if(flame < 1000) {
    digitalWrite(PUMP, HIGH);

    digitalWrite(MOTOR1, LOW);
    digitalWrite(MOTOR2, LOW);

    Serial.println("Fire Detected");
  }
  else {
    digitalWrite(PUMP, LOW);

    digitalWrite(MOTOR1, HIGH);
    digitalWrite(MOTOR2, HIGH);

    Serial.println("No Fire");
  }

  delay(500);
}