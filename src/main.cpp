#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <CmdMessenger.h>

#define MAX_TEMP 60
#define MIN_TEMP 0

#define NUM_LED 12
#define PIN 1

CmdMessenger cmdMessenger = CmdMessenger(Serial);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LED, PIN, NEO_GRB + NEO_KHZ800);
enum
{
  kSetLED,
};

void setLed(double temp)
{
  double rgb[3];
  double nbr_led = (temp / MAX_TEMP) * NUM_LED;
  rgb[1] = 0;
  for(int i=0; i < nbr_led; i++) {
    strip.setPixelColor(10, strip.Color(0, 0, 0));
  }
}

void OnSetLed()
{
  Serial.println("OnTemperure");
  int i;
  double temp = cmdMessenger.readDoubleArg();
  setLed(temp);
  Serial.print("temperature : ");
  Serial.println(i);
}

void setup()
{
  Serial.begin(115200);
  strip.begin();
  strip.setBrightness(40);
  strip.show();
  cmdMessenger.attach(kSetLED, OnSetLed);
}

void loop()
{
  cmdMessenger.feedinSerialData();
}
