void buttonDrawLoops()
{
  // TOP
  tft.drawRect(w - 60, h / 2 - 50, 50, 100, WHITE);
  tft.drawLine(w - 20, h / 2, w - 50, h / 2, WHITE);
  tft.drawLine(w - 20, h / 2, w - 25, h / 2 - 5, WHITE);
  tft.drawLine(w - 20, h / 2, w - 25, h / 2 + 5, WHITE);
  // BOTTOM
  tft.drawRect(10, h / 2 - 50, 50, 100, WHITE);
  tft.drawLine(20, h / 2, 50, h / 2, WHITE);
  tft.drawLine(20, h / 2, 25, h / 2 - 5, WHITE);
  tft.drawLine(20, h / 2, 25, h / 2 + 5, WHITE);
  // RIGHT
  tft.drawRect(w / 2 - 50, h - 60, 100, 50, WHITE);
  tft.drawLine(w / 2, h - 20, w / 2, h - 50, WHITE);
  tft.drawLine(w / 2, h - 20, w / 2 - 5, h - 25, WHITE);
  tft.drawLine(w / 2, h - 20, w / 2 + 5, h - 25, WHITE);
  // LEFT
  tft.drawRect(w / 2 - 50, 10, 100, 50, WHITE);
  tft.drawLine(w / 2, 20, w / 2, 50, WHITE);
  tft.drawLine(w / 2, 20, w / 2 - 5, 25, WHITE);
  tft.drawLine(w / 2, 20, w / 2 + 5, 25, WHITE);
  //PLUS
  tft.drawRect(w - 55, 15, 40, 40, WHITE);
  tft.drawLine(w - 25, 35, w - 45, 35, WHITE);
  tft.drawLine(w - 35, 45, w - 35, 25, WHITE);
  //MINUS
  tft.drawRect(w - 55, 65, 40, 40, WHITE);
  tft.drawLine(w - 35, 95, w - 35, 75, WHITE);
  // CENTER
  tft.drawRect(15, 15, 40, 40, WHITE);
  tft.drawCircle(35, 35, 10, WHITE);
  tft.fillTriangle(27, 41, 52, 34, 45, 25, WHITE);
}

