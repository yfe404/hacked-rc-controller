// Define the inputs
#define GAZ 25  
#define YAW 26 
#define PITCH 34 
#define ROLL 35

int gaz, yaw, pitch, roll;

struct Data_Package {
  byte gaz;
  byte yaw;
  byte pitch;
  byte roll;
};

Data_Package data; //Create a variable with the above structure


void setup() {
   Serial.begin(115200);

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

  
  Serial.print(data.roll);
  Serial.print(" ");
  Serial.println(analogRead(ROLL));

  delay(200);
}
