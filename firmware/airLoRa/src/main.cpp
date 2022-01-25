
#include "jobsMints.h"
#include "devicesMints.h"
#include "loRaMints.h"
#include "LoRaWan.h"

// ADD LORA APP KEY HERE 
char* keyIn = "0E6CFA52EEAB76D3921F02E4675DDABC";

uint8_t powerMode = 10 ;
uint8_t rebootPin = 0 ;

uint8_t numOfTries = 20; 
uint8_t numOfCycles = 0; 

bool GPGGALROnline;
TinyGPSPlus gpggalr;

bool BME280Online;
BME280 bme280; // I2C

bool SCD30Online;
SCD30 scd;
uint16_t SCD30ReadTime = 30;

bool IPS7100Online;
IpsSensor ips_sensor;
uint32_t IPS7100ResetTime = 30;

bool MGS001Online;

bool initial = true;

void setup()
{ 
  initializeSerialMints();

  loraInitMints(keyIn,powerMode,rebootPin);

  IPS7100Online =  initializeIPS7100Mints();
  BME280Online  = initializeBME280Mints();
  SCD30Online   =  initializeSCD30Mints(SCD30ReadTime);
  MGS001Online  =  initializeMGS001Mints();
  GPGGALROnline  = initializeGPGGALRMints();

  resetIPS7100Mints(IPS7100ResetTime);
  resetLoRaMints(numOfTries,powerMode);
  delay(5000);
}



void loop()
{
  readIPS7100MintsMax();
  delay(2000);

  readBME280MintsMax();
  delay(2000);

  readSCD30MintsMax();
  delay(2000);

  readMGS001MintsMax();
  delay(2000);

  readGPGGALRMintsMax();
  delay(2000);

}


