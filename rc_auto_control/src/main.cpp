#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#include <SoftwareSerial.h>
#define baudrate 9600
#include <Wire.h>
#include <Servo.h>


Servo servo_1;

byte speed = 0;
int new_angle;
int move_ = 100;
int old_angle = 83;
char move_array[3];
char turn_array[3];
char lights_array[5];
String value_m, value_t, lights_state, lights_state_old;
SoftwareSerial hc05(2, 3); // RX | TX

#define led_pin 5
#define led_count 8
char t;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(led_count, led_pin, NEO_GRB + NEO_KHZ800);

void setup()
{
  // Pins D3 and D11 - PWM frequency 31.4 кГц
  TCCR2B = 0b00000001; // x1
  TCCR2A = 0b00000001; // phase correct
  Serial.begin(9600);
  Wire.begin();
  servo_1.attach(6);
  delay(1000);
  servo_1.write(83);
  strip.begin();
  strip.setBrightness(100);
  strip.show();
  hc05.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(11, OUTPUT);
}

// right angle --> 44
// center angle --> 84
// left angle --> 143
// motor pwm --> 9, logic 8,7
void loop()
{

  if (hc05.available())
  {
    char s = hc05.read();
    if (s == 'M')
    {
      move_array[0] = hc05.read();
      move_array[1] = hc05.read();
      move_array[2] = hc05.read();
    }

    if (s == 'T')
    {
      turn_array[0] = hc05.read();
      turn_array[1] = hc05.read();
      turn_array[2] = hc05.read();
    }

    if (s == 'B')
    {
      lights_array[0] = hc05.read();
      lights_array[1] = hc05.read();
      lights_array[2] = hc05.read();
      lights_array[3] = hc05.read();
    }

    
  }

  lights_state = "B" + String(lights_array[0]) + String(lights_array[1]) + String(lights_array[2]) + String(lights_array[3]);
    Serial.println(lights_state);
    value_m = String(move_array[0]) + String(move_array[1]) + String(move_array[2]);
    value_t = String(turn_array[0]) + String(turn_array[1]) + String(turn_array[2]);
    move_ = value_m.toInt();
    new_angle = value_t.toInt();
  if (old_angle != new_angle)
  {
    servo_1.write(new_angle);
    old_angle = new_angle;
  }

  if (move_ < 105 && move_ > 95)
  {
    analogWrite(11, 0);
  }
  if (move_ > 105)
  {
    speed = map(move_, 105, 200, 0, 250);

    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    analogWrite(11, speed);
  }
  if (move_ < 95)
  {
    speed = map(move_, 95, 0, 0, 250);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    analogWrite(11, speed);
  }

  if (lights_state != lights_state_old)
  {
    Serial.write(lights_array);
    lights_state_old = lights_state;
  }
}
