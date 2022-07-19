#include <SoftwareSerial.h>
#include <TinyGPSPlus.h>

#define rxPin 4
#define txPin 5
//SoftwareSerial gpsSerial(rxPin,txPin);
SoftwareSerial neogps(1); 

TinyGPSPlus gps;

void setup()
{
  //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(115200);
  
  //Begin serial communication with Arduino and SIM800L
  neogps.begin(9600);

  Serial.println("Initializing...");
  delay(1000);
}

void loop(){
   boolean gpsData = false;
   for (unsigned long start = millis(); millis() - start <1000;){
     while(neogps.available()){
      if(gps.encode(neogps.read())){
        gpsData = true;
      }
    }
  }
  if (gpsData == true){
    gpsData = false;
    Serial.println(gps.satellites.value());
  }
  else {
    Serial.print("No data available");
  }
  print_data();
}

int print_data(){
  String gpsLatitude, gpsLongitude, gpsSpeed,gpsSatellites,gpsAltitude;
  
  gpsLatitude = String(gps.location.lat(),6);
  gpsLongitude = String(gps.location.lng(),6);
  gpsSpeed = String (gps.speed.kmph());
  gpsSatellites = String(gps.satellites.value());
  gpsAltitude = String(gps.altitude.meters(),0);

  
  if (gps.location.isValid() == 1){
    Serial.print("LAT: ");
    Serial.println(gpsLatitude);
    Serial.println("\n");
    Serial.print("LONG: ");
    Serial.println(gpsLongitude);
    Serial.print("\n");
    Serial.print("SPEED: ");
    Serial.println(gpsSpeed);
    Serial.print("\n");
    Serial.print("Connected Satellites: ");
    Serial.println(gpsSatellites);
    Serial.print("\n");
    Serial.print("ALT : ");
    Serial.println(gpsAltitude);   
    Serial.print("\n");
    
  }
}
