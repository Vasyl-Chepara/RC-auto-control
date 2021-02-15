/*
  HC05 - Bluetooth AT-Command mode
  modified on 10 Feb 2019
  by Saeed Hosseini
  https://electropeak.com/learn/
*/
#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial MyBlue(2, 3); // RX | TX
Servo servo_1;
int angle, turn, move_, value;
String value_m, value_t;
void setup()
{
  Serial.begin(9600);
  MyBlue.begin(9600);
  servo_1.attach(6);
  Serial.println("Ready to connect\nDefualt password is 1234 or 000");
   pinMode(7, OUTPUT);  
  pinMode(8, OUTPUT);
  pinMode(11, OUTPUT);
}
void loop()
{
   int output = analogRead(A0);

  value = map(output, 0, 1023, 0, 255);
    digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  analogWrite(11, value);
  Serial.println(value);
//servo_1.write(90);
//  
//  if (MyBlue.available()) {
//    char move_array[3];
//    char turn_array[3];
//    char s = MyBlue.read();
//    
//    if (s == 'M') {
////      move_array[0] = s;
//      for (int i = 0; i < 3; i++) {
////        delay(5);
//        char q = MyBlue.read();
////        Serial.println(q);
//        if (q == '#') {
//          break;
//        }
//        move_array[i] = q;
//      }
//    }
//
//    if (s == 'T') {
////      turn_array[0] = s;
//      for (int i = 0; i < 3; i++) {
////        delay(5);
//        char q = MyBlue.read();
//        if (q == '#') {
//          break;
//        }
//        turn_array[i] = q;
//      }
//    }
//
//    //Serial.println(ch_array);
//        value_m = String(move_array[0]) + String(move_array[1]) + String(move_array[2]);
//        value_t = String(turn_array[0]) + String(turn_array[1]) + String(turn_array[2]);
//        move_ = value_m.toInt();
//        turn = value_t.toInt();
//        Serial.println(turn);
//        servo_1.write(turn);
//    
//
//    //
//    delay(50);
//  }
}
