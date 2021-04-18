#include <Adafruit_NeoPixel.h>
#include <Wire.h>

char lights_array[4];

#define led_pin 5
#define led_count 8
char t;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(led_count, led_pin, NEO_GRB + NEO_KHZ800);

void turn_to(char16_t direct)
{
  byte f, b;
  if (direct == "l")
  {
    f = 1;
    b = 4;
  }
  else if (direct == "r")
  {
    f = 2;
    b = 6;
  }
  strip.setPixelColor(f, 255, 90, 0);
  strip.setPixelColor(b, 255, 90, 0);
  strip.show();
  delay(500);
  strip.setPixelColor(f, 0, 0, 0);
  strip.setPixelColor(b, 0, 0, 0);
  strip.show();
  delay(500);
}

void avariyka() {
  strip.setPixelColor(1, 255, 90, 0);
  strip.setPixelColor(4, 255, 90, 0);
  strip.setPixelColor(2, 255, 90, 0);
  strip.setPixelColor(6, 255, 90, 0);
  strip.show();
  delay(500);
  strip.setPixelColor(1, 0, 0, 0);
  strip.setPixelColor(4, 0, 0, 0);
  strip.setPixelColor(2, 0, 0, 0);
  strip.setPixelColor(6, 0, 0, 0);
  strip.show();
  delay(500);
}

void lights(bool state)
{
  int br = 235;
  if (state)
  {
    strip.setPixelColor(0, br, br, br);
    strip.setPixelColor(3, br, br, br);
    strip.setPixelColor(5, br, 0, 0);
    strip.setPixelColor(7, br, 0, 0);
    strip.show();
  }
  else
  {
    strip.setPixelColor(0, 0, 0, 0);
    strip.setPixelColor(1, 0, 0, 0);
    strip.setPixelColor(2, 0, 0, 0);
    strip.setPixelColor(3, 0, 0, 0);
    strip.show();
  }
}

void position_lights(bool state)
{
  int br = 235;
  if (state)
  {
    strip.setPixelColor(1, br, br, br);
    strip.setPixelColor(2, br, br, br);
    strip.setPixelColor(4, br, 0, 0);
    strip.setPixelColor(6, br, 0, 0);
    strip.show();
  }
  else
  {
    strip.setPixelColor(1, 0, 0, 0);
    strip.setPixelColor(2, 0, 0, 0);
    strip.setPixelColor(4, 0, 0, 0);
    strip.setPixelColor(6, 0, 0, 0);
    strip.show();
  }
}

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  strip.begin();
  strip.setBrightness(200);
  strip.show();
}

void loop()
{
position_lights(true);
lights(true);
//  if (Serial.available())
//  {
//    t = Serial.read();
//    Serial.println(t);
//    if (t == 'B') {
//      lights_array[0] = Serial.read();
//      lights_array[1] = Serial.read();
//      lights_array[2] = Serial.read();
//      lights_array[3] = Serial.read();
//    }
//     
//  }

}
