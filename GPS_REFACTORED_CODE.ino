/*Arduino code to run a GPS Module*/


//#include <TinyGPSPlus.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>


int rxPin = 4;
int txPin = 5;

int GPSBaud = 115200;

TinyGPSPlus gps;
SoftwareSerial neoGps(rxPin, txPin);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  neoGps.begin(GPSBaud);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(neoGps.available() <= 0 ){
    Serial.print("No GPS detected");
    Serial.println(" ");
    delay(2000);
  }
  while(neoGps.available()> 0){
    gps.encode(neoGps.read());
    if(gps.location.isUpdated()){
      Serial.print("Latitude = ");
      Serial.print(gps.location.lat(),6);
      Serial.print("Longitude = ");
      Serial.print(gps.location.lng(),6);
    }
   
  }
 

}
