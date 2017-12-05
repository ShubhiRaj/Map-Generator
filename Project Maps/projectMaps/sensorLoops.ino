void sensorLoops()
{
    frontLoop();
    rightLoop();
    rightBackLoop();
    leftBackLoop();
    leftLoop();
    //printPixels();
}

const float scale = 0.08;
const float sg = scale * 100;
const int m240 = 240;
const int m160 = 160;
const int wL = 300;
const int minW = 100;
bool initbool = 1;

void frontLoop()
{
    int distance, d, l1;
    //uint8_t a = 44;
  
    digitalWrite(TRIG_PIN_FRONT, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN_FRONT, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN_FRONT, LOW);
    distance = pulseIn(ECHO_PIN_FRONT, HIGH) * 0.034 / 2;
    //tft.fillScreen(BLACK);
    //tft.setCursor(0, 0);
    //tft.print(distance);
    if (distance <= 300 && distance >= minW&&initbool)
    {
      /*d = distance * 0.8;
      l1 = b * ((400 - d) * 800 + 400);
      sdFile = SD.open("datalog.dat", FILE_WRITE);
      sdFile.seek(l1);
      sdFile.write((const uint8_t *)&a, sizeof(a));
      sdFile.close();
      distance = 160 - d;
      tft.fillScreen(RED);
      delay(3000);*/
      distance = 160 - distance * scale;
      tft.drawLine(distance  + cPos.y * sg, m240 + wL + cPos.x * sg, distance  + cPos.y * sg, m240 - wL + cPos.x * sg, RED);
      initbool = 0;
      //delay(2000);
    }
}

void printPixels()
{
  /*bool a;
  sdFile = SD.open("datalog.dat", FILE_READ);
  for (int i = 240; i < 560; ++i)
  {
    for (int j = 160; j <  640; ++j)
    {
      sdFile.read((char*)&a, sizeof(a));
      tft.print(a);
      tft.print(" ");
      if (j % 300 == 0)
      {
        tft.fillScreen(BLACK);
        tft.setCursor(0, 0);
      }
      if (a)
      {
        tft.drawPixel(i - 240, j - 160, RED);
      }
    }
  }
  sdFile.close();*/
  uint8_t *a = 77;
  *a = 88;
  tft.println("START");
  tft.setCursor(0, 0);
  sdFile = SD.open("datalog.dat", FILE_READ);
  for (int i = 240; i < 800; ++i)
  {
    for (int j = 160; j <  800; ++j)
    {
      sdFile.read((uint8_t *)&a, sizeof(a));
      if (*a == 44)
      {
        tft.fillScreen(BLACK);
        tft.println("SUCESSSSSSSSSS");
        tft.print("i: ");
        tft.println(i);
        tft.print("j: ");
        tft.println(j);
        delay(10000);
        tft.fillScreen(BLACK);
      }
    }
    tft.print(*a);
      if (i % 300 == 0)
      {
        tft.fillScreen(BLACK);
        tft.setCursor(0, 0);
      }
  }
  sdFile.close();
  tft.println("END");
}

void rightLoop()
{
    int distance;
  
    digitalWrite(TRIG_PIN_RIGHT, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN_RIGHT, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN_RIGHT, LOW);
    distance = pulseIn(ECHO_PIN_RIGHT, HIGH) * 0.034 / 2;
    if (distance <= 300)
    {
      distance = 240 - distance * scale;
      tft.drawLine(m160 + wL, distance, m160 - wL, distance, RED);
      //delay(2000);
    }
}

void rightBackLoop()
{
    int distance;
  
    digitalWrite(TRIG_PIN_RIGHT_BACK, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN_RIGHT_BACK, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN_RIGHT_BACK, LOW);
    distance = pulseIn(ECHO_PIN_RIGHT_BACK, HIGH) * 0.034 / 2;
    if (distance <= 300  && distance >= minW)
    {
      distance = SQRT_2_OVER_2 * scale * distance;
      tft.drawLine(m160 + distance - wL, 240 - distance - wL, m160 + distance + wL, m240 - distance + wL, RED);
      //delay(2000);
    }
}

void leftBackLoop()
{
    int distance;
  
    digitalWrite(TRIG_PIN_LEFT_BACK, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN_LEFT_BACK, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN_LEFT_BACK, LOW);
    distance = pulseIn(ECHO_PIN_LEFT_BACK, HIGH) * 0.034 / 2;
    if (distance <= 300  && distance >= minW)
    {
      distance = SQRT_2_OVER_2 * scale * distance;
      tft.drawLine(m160 + distance + wL, m240 + distance - wL, m160 + distance - wL, m240 + distance + wL, RED);
      //delay(2000);
    }
}

void leftLoop()
{
    int distance;
  
    digitalWrite(TRIG_PIN_LEFT, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN_LEFT, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN_LEFT, LOW);
    distance = pulseIn(ECHO_PIN_LEFT, HIGH) * 0.034 / 2;
    if (distance <= 300  && distance >= minW)
    {
      distance = 240 + distance * scale;
      tft.drawLine(m160 + wL, distance, m160 - wL, distance, RED);
      //delay(2000);
    }
}
