/*
*************************************
* This is Project Maps Source Code! *
*************************************

Please read this code carefully and
use it as you wish on your Arduino
Mega 2560 with Adafruit Ultimate GPS,
HCSR04 sensors, tft touch screen,
MPU6050 accelerometer and SD card
reader. This is not a release version.
 */
#include "projectMaps.h"

MCUFRIEND_kbv tft;
HardwareSerial mySerial = Serial1;
Adafruit_GPS GPS(&Serial1);
boolean usingInterrupt = false;
void useInterrupt(boolean);
uint32_t timer = millis();
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
bool buttonPressed;
ButtonState buttonState;
int w, h;
Position cPos;
Sd2Card card;
SdVolume volume;
SdFile root;
File sdFile;
int b = sizeof(bool);
bool t = true;

void setup()
{
  sensorSetup();
  screenSetup();
  touchScreenSetup();
  setInitialBeforePopUpFontAndColor();
  startPopUpScreen();
  setInitialFontAndColor();
  gpsSetup();
  //sdCardSetup();
  buttonDrawLoops();
}

void loop()
{
  //loopInit();
  gpsLoops();
  sensorLoops();
  buttonDrawLoops();
  buttonTouchLoops();
  loopEnd();
}
