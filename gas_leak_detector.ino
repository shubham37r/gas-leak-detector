// Gas Leak Detector - Arduino UNO
// Reads analog gas sensor (e.g. MQ-2), lights an LED and sounds a
// passive buzzer when the reading crosses a threshold.

int Input = A0;
int R_LED = 2;
int Buzzer = 4;
int val;
int MAX = 150;

void setup() {
  Serial.begin(9600);
  pinMode(Input, INPUT);
  pinMode(R_LED, OUTPUT);
  pinMode(Buzzer, OUTPUT);
}

void loop() {
  val = analogRead(A0);
  Serial.println(val); // helps you see gas level in Serial Monitor

  if (val >= MAX) {
    digitalWrite(R_LED, HIGH);
    tone(Buzzer, 1000);     // passive buzzer needs tone()
    Serial.println("GAS LEAKING");
  }
  else {
    digitalWrite(R_LED, LOW);
    noTone(Buzzer);          // passive buzzer needs noTone()
    Serial.println("NORMAL");
  }
}
