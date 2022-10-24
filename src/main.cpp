
#include <string.h>
#include <EEPROM.h>
#include <Arduino.h>

long id;

byte simpl_uuid[32];



void pretty_uuid()
{
  char b[8];

  memset(b, 0, 8);
  memset(simpl_uuid, 0, 32);

  snprintf(b, 8, "%lX",(long)EEPROM.read(0));  //read a single byte from EEPROM, interpret as ul (4 bytes), write to b
  strcpy((char*)simpl_uuid, b);               //copy b into simpl_uuid
  memset(b, 0, 8);                             //clear b
  snprintf(b, 8, "%lX",(long)EEPROM.read(1));  //read a single byte from EEPROM, interpret as ul (4 bytes), write to b
  strcat((char*)simpl_uuid, b);               //concat b onto simpl_uuid
  memset(b, 0, 8);                             //clear b
  snprintf(b, 8, "%lX",(long)EEPROM.read(2));  //read a single byte from EEPROM, interpret as ul (4 bytes), write to b
  strcat((char*)simpl_uuid, b);               //concat b onto simpl_uuid
  memset(b, 0, 8);                             //clear b
  snprintf(b, 8, "%lX",(long)EEPROM.read(3));  //read a single byte from EEPROM, interpret as ul (4 bytes), write to b
  strcat((char*)simpl_uuid, b);               //concat b onto simpl_uuid
} 



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
    pretty_uuid();
    Serial.print((char *)(simpl_uuid));
  
  Serial.println();
  // Ethernet.begin(mac, ip);
  
}


  void loop()
  {
   // exit(0);
  
  }

