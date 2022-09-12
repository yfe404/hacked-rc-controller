#include <Wire.h>

#define I2C_DEV_ADDR 0x55
#define SDA_PIN 21
#define SCL_PIN 22

// Define the inputs
#define GAZ 25  
#define YAW 26 
#define PITCH 34 
#define ROLL 35


byte gaz, yaw, pitch, roll;

struct Data_Package {
  byte gaz;
  byte yaw;
  byte pitch;
  byte roll;
};

Data_Package data; //Create a variable with the above structure

char buffer[20];

void onRequest(){
 sprintf(buffer, "%03d,%03d,%03d,%03d", data.gaz, data.yaw, data.pitch, data.roll);
 Wire.print(buffer);
}


void setup() {
   Serial.begin(115200);

   Wire.onRequest(onRequest);
   Wire.setClock(100000);
   Wire.setPins(SDA_PIN, SCL_PIN);
   Wire.begin((uint8_t)I2C_DEV_ADDR);

   // Set initial default values
  data.gaz = 127;
  data.yaw = 127;
  data.pitch = 127;
  data.roll = 127;
}

void loop() {
  // Read all analog inputs and map them to one Byte value
  data.gaz = map(analogRead(GAZ), 740, 3185, 0, 255);
  data.yaw = map(analogRead(YAW), 790, 3115, 0, 255);
  data.pitch = map(analogRead(PITCH), 715, 3100, 0, 255);
  data.roll = map(analogRead(ROLL), 810, 3150, 0, 255);
  
}
