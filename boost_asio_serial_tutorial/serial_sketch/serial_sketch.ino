String line;

void setup() {
  
    Serial.begin(115200);    

}

void loop() {
  
  if (Serial.available() > 0) {
  
    line = Serial.readString();

    Serial.println(line);

  }
  
}
