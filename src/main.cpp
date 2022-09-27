
#include <string.h>
#include <EEPROM.h>
#include <Arduino.h>

long id;


void setup()
{
    // Open serial communications and wait for port to open:
    Serial.begin(9600);
    Serial.print("Generating new unitId: ");

    randomSeed(analogRead(7)*analogRead(6)*analogRead(5)+micros());
    long unitId = random();
    long notunitId = -unitId;
     EEPROM.write(0, unitId >> 24 & 0xFF);
     EEPROM.write(1, unitId >> 16 & 0xFF);
     EEPROM.write(2, unitId >> 8  & 0xFF);
     EEPROM.write(3, unitId     & 0xFF);
     EEPROM.write(4, notunitId >> 24 & 0xFF);
     EEPROM.write(5, notunitId >> 16 & 0xFF);
     EEPROM.write(6, notunitId >> 8  & 0xFF);
     EEPROM.write(7, notunitId     & 0xFF);

    Serial.print("Generated new unitId: ");
    Serial.print(unitId, HEX);
  
  Serial.println();
  // Ethernet.begin(mac, ip);
  
}

  void loop()
  {
    //
  
  }

