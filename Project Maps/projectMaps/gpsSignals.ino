SIGNAL(TIMER0_COMPA_vect)
{
  char c = GPS.read();
  #ifdef UDR0
    checkGpsEcho(c);
  #endif
}

void checkGpsEcho(char c)
{
  if (GPSECHO)
  {
    checkGpsC(c);
  }
}

void checkGpsC(char c)
{
  if (c) 
  {
    UDR0 = c;
  }
}

void useInterrupt(boolean v)
{
  if (v)
  {
    ifGpsV();
  }
  else
  {
    ifNotGpsV();
  }
}

void ifGpsV()
{
  OCR0A = 0xAF;
  TIMSK0 |= _BV(OCIE0A);
  usingInterrupt = true;
}

void ifNotGpsV()
{
  TIMSK0 &= ~_BV(OCIE0A);
  usingInterrupt = false;
}

