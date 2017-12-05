void buttonTouchLoops()
{
  digitalWrite(13, HIGH);
  TSPoint p = ts.getPoint();
  digitalWrite(13, LOW);
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  if (p.z > MINPRESSURE && p.z < MAXPRESSURE)
  {
    if (!buttonPressed)
    {
      ifTouching(p);
    }
  }
  else
  {
    if (buttonPressed)
    {
      checkWhichButtonHasBeenReleased();
      initializeButtons();
    }
  }
}

void checkWhichButtonHasBeenReleased()
{
  switch (buttonState)
  {
    case TOP:
      topButtonReleased();
      break;
    case BOTTOM:
      bottomButtonReleased();
      break;
    case RIGHT:
      rightButtonReleased();
      break;
    case LEFT:
      leftButtonReleased();
      break;
    case PLUS:
      plusButtonReleased();
      break;
    case MINUS:
      minusButtonReleased();
      break;
    case CENTER:
      centerButtonReleased();
      break;
  }
}

void topButtonReleased()
{
  tft.fillRect(w - 60, h / 2 - 50, 50, 100, BLACK);
  tft.drawRect(w - 60, h / 2 - 50, 50, 100, WHITE);
  tft.drawLine(w - 20, h / 2, w - 50, h / 2, WHITE);
  tft.drawLine(w - 20, h / 2, w - 25, h / 2 - 5, WHITE);
  tft.drawLine(w - 20, h / 2, w - 25, h / 2 + 5, WHITE);
}

void bottomButtonReleased()
{
  tft.fillRect(10, h / 2 - 50, 50, 100, BLACK);
  tft.drawRect(10, h / 2 - 50, 50, 100, WHITE);
  tft.drawLine(20, h / 2, 50, h / 2, WHITE);
  tft.drawLine(20, h / 2, 25, h / 2 - 5, WHITE);
  tft.drawLine(20, h / 2, 25, h / 2 + 5, WHITE);
}

void rightButtonReleased()
{
  tft.fillRect(w / 2 - 50, h - 60, 100, 50, BLACK);
  tft.drawRect(w / 2 - 50, h - 60, 100, 50, WHITE);
  tft.drawLine(w / 2, h - 20, w / 2, h - 50, WHITE);
  tft.drawLine(w / 2, h - 20, w / 2 - 5, h - 25, WHITE);
  tft.drawLine(w / 2, h - 20, w / 2 + 5, h - 25, WHITE);
}

void leftButtonReleased()
{
  tft.fillRect(w / 2 - 50, 10, 100, 50, BLACK);
  tft.drawRect(w / 2 - 50, 10, 100, 50, WHITE);
  tft.drawLine(w / 2, 20, w / 2, 50, WHITE);
  tft.drawLine(w / 2, 20, w / 2 - 5, 25, WHITE);
  tft.drawLine(w / 2, 20, w / 2 + 5, 25, WHITE);
}

void plusButtonReleased()
{
  tft.fillRect(w - 55, 15, 40, 40, BLACK);
  tft.drawRect(w - 55, 15, 40, 40, WHITE);
  tft.drawLine(w - 25, 35, w - 45, 35, WHITE);
  tft.drawLine(w - 35, 45, w - 35, 25, WHITE);
}

void minusButtonReleased()
{
  tft.fillRect(w - 55, 65, 40, 40, BLACK);
  tft.drawRect(w - 55, 65, 40, 40, WHITE);
  tft.drawLine(w - 35, 95, w - 35, 75, WHITE);
}

void centerButtonReleased()
{
  tft.fillRect(15, 15, 40, 40, BLACK);
  tft.drawRect(15, 15, 40, 40, WHITE);
  tft.drawCircle(35, 35, 10, WHITE);
  tft.fillTriangle(27, 41, 52, 34, 45, 25, WHITE);
}

/*TSPoint initializeTouchLoop()
{
  

  return p;
}

void checkIfTouching(TSPoint p)
{
  
}*/

void ifTouching(TSPoint p)
{
    p.x = p.x + p.y;       
    p.y = p.x - p.y;            
    p.x = p.x - p.y;
    p.x = map(p.x, TS_MINX, TS_MAXX, tft.width(), 0);
    p.y = tft.height() - (map(p.y, TS_MINY, TS_MAXY, tft.height(), 0));
    buttonMap(p);
}

void initializeButtons()
{
  buttonPressed = false;
}

void buttonMap(TSPoint p)
{
  if (p.x >= w - 60 && p.x <= w - 10 && p.y >= h / 2 - 50 && p.y <= h / 2 + 50)
  {
    topButtonPressed();
  }
  else if (p.x >= 10 && p.x <= 60 && p.y >= h / 2 - 50 && p.y <= h / 2 + 50)
  {
    bottomButtonPressed();
  }
  else if (p.x >= w / 2 - 50 && p.x <= w / 2 + 50 && p.y >= h - 60 && p.y <= h - 10)
  {
    rightButtonPressed();
  }
  else if (p.x >= w / 2 - 50 && p.x <= w / 2 + 50 && p.y >= 10 && p.y <= 60)
  {
    leftButtonPressed();
  }
  else if (p.x >= w - 55 && p.x <= w - 15 && p.y >= 15 && p.y <= 55)
  {
    plusButtonPressed();
  }
  else if (p.x >= w - 55 && p.x <= w - 15 && p.y >= 65 && p.y <= 105)
  {
    minusButtonPressed();
  }
  else if (p.x >= 15 && p.x <= 55 && p.y >= 15 && p.y <= 55)
  {
    centerButtonPressed();
  }
}

void topButtonPressed()
{
  buttonPressed = true;
  buttonState = TOP;
  tft.fillRect(w - 60, h / 2 - 50, 50, 100, WHITE);
  tft.drawLine(w - 20, h / 2, w - 50, h / 2, BLACK);
  tft.drawLine(w - 20, h / 2, w - 25, h / 2 - 5, BLACK);
  tft.drawLine(w - 20, h / 2, w - 25, h / 2 + 5, BLACK);
}

void bottomButtonPressed()
{
  buttonPressed = true;
  buttonState = BOTTOM;
  tft.fillRect(10, h / 2 - 50, 50, 100, WHITE);
  tft.drawLine(20, h / 2, 50, h / 2, BLACK);
  tft.drawLine(20, h / 2, 25, h / 2 - 5, BLACK);
  tft.drawLine(20, h / 2, 25, h / 2 + 5, BLACK);
}

void rightButtonPressed()
{
  buttonPressed = true;
  buttonState = RIGHT;
  tft.fillRect(w / 2 - 50, h - 60, 100, 50, WHITE);
  tft.drawLine(w / 2, h - 20, w / 2, h - 50, BLACK);
  tft.drawLine(w / 2, h - 20, w / 2 - 5, h - 25, BLACK);
  tft.drawLine(w / 2, h - 20, w / 2 + 5, h - 25, BLACK);
}

void leftButtonPressed()
{
  buttonPressed = true;
  buttonState = LEFT;
  tft.fillRect(w / 2 - 50, 10, 100, 50, WHITE);
  tft.drawLine(w / 2, 20, w / 2, 50, BLACK);
  tft.drawLine(w / 2, 20, w / 2 - 5, 25, BLACK);
  tft.drawLine(w / 2, 20, w / 2 + 5, 25, BLACK);
}

void plusButtonPressed()
{
  buttonPressed = true;
  buttonState = PLUS;
  tft.fillRect(w - 55, 15, 40, 40, WHITE);
  tft.drawLine(w - 25, 35, w - 45, 35, BLACK);
  tft.drawLine(w - 35, 45, w - 35, 25, BLACK);
}

void minusButtonPressed()
{
  buttonPressed = true;
  buttonState = MINUS;
  tft.fillRect(w - 55, 65, 40, 40, WHITE);
  tft.drawLine(w - 35, 95, w - 35, 75, BLACK);
}

void centerButtonPressed()
{
  buttonPressed = true;
  buttonState = CENTER;
  tft.fillRect(15, 15, 40, 40, WHITE);
  tft.drawCircle(35, 35, 10, BLACK);
  tft.fillTriangle(27, 41, 52, 34, 45, 25, BLACK);
}
