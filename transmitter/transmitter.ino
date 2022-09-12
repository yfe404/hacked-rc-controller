// Define the inputs
#define GAZ 25  

int gaz;

struct Data_Package {
  byte gaz;
};

Data_Package data; //Create a variable with the above structure


void setup() {
   Serial.begin(115200);

   // Set initial default values
  data.gaz = 127;
}

void loop() {
  // Read all analog inputs and map them to one Byte value
  data.gaz = map(analogRead(GAZ), 740, 3185, 0, 255);
  Serial.print(data.gaz);
  Serial.print(" ");
  Serial.println(analogRead(GAZ));

  delay(200);
}
