void gpsSetup()
{
  GPS.begin(9600);
  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);
  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);
  GPS.sendCommand(PGCMD_ANTENNA);
  useInterrupt(true);
  delay(1000);
  mySerial.println(PMTK_Q_RELEASE);
}

void setInitialBeforePopUpFontAndColor()
{
  tft.setTextSize(2);
  tft.setRotation(1);
  tft.setTextColor(BLACK);
}

void setInitialFontAndColor()
{
  tft.setTextColor(WHITE);
  tft.fillScreen(BLACK);
  tft.setRotation(0);
}

void startPopUpScreen()
{
  tft.fillScreen(RED);
  tft.print("\n\n\n\n\n   Welcome to Project Maps Second Demo!");
  tft.drawRect(w / 2 - 100 + 50, h / 2 - 50 + 30, 100, 100, WHITE);
  tft.drawRect(w / 2 - 100 + 50 + 25, h / 2 - 50 + 55, 100, 100, WHITE);
  delay(3000);
}

void screenSetup()
{
  tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(identifier);
  w = tft.width(), h = tft.height();
}

void touchScreenSetup()
{
  pinMode(13, OUTPUT);
  initializeButtons();
}

void sensorSetup()
{
  Serial.begin(9600);
  pinMode(TRIG_PIN_FRONT, OUTPUT);
  pinMode(ECHO_PIN_FRONT, INPUT);
  pinMode(TRIG_PIN_RIGHT, OUTPUT);
  pinMode(ECHO_PIN_RIGHT, INPUT);
  pinMode(TRIG_PIN_RIGHT_BACK, OUTPUT);
  pinMode(ECHO_PIN_RIGHT_BACK, INPUT);
  pinMode(TRIG_PIN_LEFT_BACK, OUTPUT);
  pinMode(ECHO_PIN_LEFT_BACK, INPUT);
  pinMode(TRIG_PIN_LEFT, OUTPUT);
  pinMode(ECHO_PIN_LEFT, INPUT);
}

void sdCardSetup()
{
  pinMode(SS, OUTPUT);
  while (!card.init(SPI_HALF_SPEED, 10, 11, 12, 13)) 
  {
    tft.print("Initializing SD card . . .");
    tft.fillScreen(BLACK);
  }  
  tft.print("SD card initialized!");
  delay(500);
  tft.fillScreen(BLACK);
  sdFile = SD.open("datalog.dat", FILE_WRITE);
  uint8_t bob = 33;
  uint8_t *a = &bob;
  for (int i = 0; i < 800; ++i)
  {
    for (int j = 0; j <  800; ++j)
    {
      //sdFile.write((char*)&a, sizeof(a));
      sdFile.write((const uint8_t *)&bob, sizeof(a));
    }
    tft.print(i);
    if (i % 150 == 0)
    {
      tft.fillScreen(BLACK);
      tft.setCursor(0, 0);
    }
  }
  tft.print("Array created !");
  delay(3000);
  tft.fillScreen(BLACK);
  sdFile.close();
  tft.setCursor(0, 0);
  /*tft.println("PRINT PIXELS IN SETUP");
  delay(2000);
  printPixels();
  tft.fillScreen(BLACK);
  tft.println("END OF PRINT PIXELS IN SETUP");
  delay(2000);
  tft.fillScreen(BLACK);*/
  /*sdFile = SD.open("datalog.dat", FILE_READ);
  for (int i = 0; i < 800; ++i)
  {
    for (int j = 0; j <  800; ++j)
    {
      sdFile.read((uint8_t *)&a, sizeof(a));
    }
    tft.print(a);
      if (i % 300 == 0)
      {
        tft.fillScreen(BLACK);
        tft.setCursor(0, 0);
      }
  }
  sdFile.close();*/
}

