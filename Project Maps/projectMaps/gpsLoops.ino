void gpsLoops()
{
  checkIfGpsNotUsingInterrupt();
  checkIfGpsReceivedNewNMEA();
  checkIfGpsTimerIsGreaterThanMillis();
  checkIfGpsMillisMinusTimerIsGreaterThan2000();
}

void checkIfGpsNotUsingInterrupt()
{
  if (!usingInterrupt)
  {
    ifGpsNotUsingInterrupt();
  }
}

void ifGpsNotUsingInterrupt()
{
  char c = GPS.read();
  if (GPSECHO)
  {
    ifGpsEcho(c);
  }
}

void ifGpsEcho(char c)
{
  if (c)
  {
    tft.print(c);
  }
}

void checkIfGpsReceivedNewNMEA()
{
  if (GPS.newNMEAreceived())
  {
    ifGpsReceivednewNMEA();
  }
}

void ifGpsReceivednewNMEA()
{
  if (!GPS.parse(GPS.lastNMEA()))
  {
    return;
  }
}

void checkIfGpsTimerIsGreaterThanMillis()
{
  if (timer > millis()) 
  {
    timer = millis();
  }
}

void checkIfGpsMillisMinusTimerIsGreaterThan2000()
{
  if (millis() - timer > 2000)
  {
    timer = millis();
    printGpsNonFixInformation();
    if (GPS.fix)
    {
      firstGpsFix();
      printGpsFixInformation();
    }
  }
}

void printGpsNonFixInformation()
{
  /*tft.print("\nTime: ");
  tft.print(GPS.hour, DEC);
  tft.print(':');
  tft.print(GPS.minute, DEC);
  tft.print(':');
  tft.print(GPS.seconds, DEC);
  tft.print('.');
  tft.println(GPS.milliseconds);
  tft.print("Date: ");
  tft.print(GPS.day, DEC);
  tft.print('/');
  tft.print(GPS.month, DEC);
  tft.print("/20");
  tft.println(GPS.year, DEC);
  tft.print("Fix: ");
  tft.print((int)GPS.fix);
  tft.print(" quality: ");
  tft.println((int)GPS.fixquality);*/
}

bool firstFix = true;
Position GpsPosition;

void firstGpsFix()
{
  if (firstFix)
  {
    cPos.x = 0;
    cPos.y = 0;
    firstFix = false;
    GpsPosition.x = GPS.latitude / 100.0;
    GpsPosition.y = GPS.longitude / 100.0;
  }
}

void printGpsFixInformation()
{
  /*tft.print("Location: ");
  tft.print(GPS.latitude / 100.0, 4);
  tft.print(GPS.lat);
  tft.print(", ");
  tft.print(GPS.longitude / 100.0, 4);
  tft.println(GPS.lon);
  tft.print("X(m): ");
  tft.println((GPS.latitude / 100.0 - GpsPosition.x) * 111000);
  tft.print("Y(m): ");
  tft.println((GPS.longitude / 100.0 - GpsPosition.y) * 111000);
  tft.print("Speed (knots): ");
  tft.println(GPS.speed);
  tft.print("Angle: ");
  tft.println(GPS.angle);
  tft.print("Altitude: ");
  tft.println(GPS.altitude);
  tft.print("Satellites: ");
  tft.println((int)GPS.satellites);*/
  cPos.x = (GPS.latitude / 100.0 - GpsPosition.x) * 111000;
  cPos.y = (GPS.longitude / 100.0 - GpsPosition.y) * 111000;
}

