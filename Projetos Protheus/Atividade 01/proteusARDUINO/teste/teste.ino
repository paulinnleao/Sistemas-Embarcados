/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

 This example code is in the public domain.
 */
int i = 0, n = 5, x[n];
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  
  float y = 0;
  x[i] = analogRead(A0);
  i = i + 1;
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(100);              // wait for a second
  if(i==n){
    while(i>=0){
      y+=x[i];
    }
    Serial.print("Media: ");
    Serial.println(y/n);
  }
  Serial.print("Fim loop ");
  Serial.print(i);
  Serial.print(" valor y: ");
  Serial.println(y);
  delay(1);        // delay in between reads for stability
}
