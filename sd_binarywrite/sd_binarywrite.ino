#include <SPI.h>
#include <SD.h>

const int chipSelect = 4;
File dataFile;

void setup()
{
  Serial.begin(9600);
   while (!Serial) {
    ; 
   }


  Serial.print("Initializing SD card...");
  pinMode(SS, OUTPUT);
  
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    while (1) ;
  }
  Serial.println("card initialized.");
  
  dataFile = SD.open("datalog.datLE_WRITE);
  
  if (! dataFile) {
    Serial.println("error opening datalog.txt");
    while (1) ;
  }
}


void loop()
{

  /*struct datastore myData;
    myData.adc1 = analogRead(0);
    myData.adc2 = analogRead(1);
    myData.voltage = myData.adc1 / 1023.0 * 5.0;
    myData.current = myData.adc2 / 10000.0 * 23.4429;
    dataFile.write((const uint8_t *)&myData, sizeof(myData));
    delay(50);
 */
  
  String dataString = "";

  for (int analogPin = 0; analogPin < 3; analogPin++) {
    int sensor = analogRead(analogPin);
    dataString += String(sensor);
    if (analogPin < 2) {
      dataString += ","; 
    }
  }

  dataFile.println(dataString);

  Serial.println(dataString);
  
  // The following line will 'save' the file to the SD card after every line of data - this will use more power and slow down how much data
  // you can read but it's safer! If you want to speed up the system, remove the call to flush() and it
  // will save the file only every 512 bytes - every time a sector on the SD card is filled with data.
  dataFile.flush();
  
  // Take 1 measurement every 500 milliseconds
  delay(500);
}



