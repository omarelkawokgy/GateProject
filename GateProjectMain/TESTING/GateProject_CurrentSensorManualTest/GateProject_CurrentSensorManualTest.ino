void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(A3, OUTPUT);
pinMode(A4, OUTPUT);
pinMode(A5, OUTPUT);
pinMode(A6, INPUT);
pinMode(A7, INPUT);
pinMode(9, INPUT);
}
typedef unsigned short uint16_T;
typedef unsigned char uint8_T;

uint16_T leftMotor = 0;
uint16_T rightMotor = 0;

void loop() {
  // put your main code here, to run repeatedly:
  int btn;
  btn == digitalRead(9);
  
//  if(btn == HIGH)
  { 
    digitalWrite(A3, HIGH);
    digitalWrite(A4, HIGH);
    digitalWrite(A5, HIGH);
  }
//  else
//  {
//    digitalWrite(A3, LOW);
//    digitalWrite(A4, LOW);
//    digitalWrite(A5, LOW);
//  }
leftMotor = analogRead(A7);
rightMotor = analogRead(A6);

Serial.print("Left Motor: ");
Serial.print(leftMotor);
Serial.print("            Right Motor: ");
Serial.println(rightMotor);

delay(10);
}
