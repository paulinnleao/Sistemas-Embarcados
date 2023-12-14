
int i = 0, n = 5, x[n];

void setup() {
  
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  
  
  float y = 0;
  x[i] = analogRead(A0);
  i = i + 1;
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  delay(100);  
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
  delay(1);
}