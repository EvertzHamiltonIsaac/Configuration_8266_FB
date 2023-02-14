#define D0 16
#define D1 5
#define D2 4
#define D3 0
#define D4 2

void setup() {
  // put your setup code here, to run once:
  pinMode(D4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(D4,LOW);
  delay(1000);
  digitalWrite(D4,HIGH);
  delay(1000);
}
