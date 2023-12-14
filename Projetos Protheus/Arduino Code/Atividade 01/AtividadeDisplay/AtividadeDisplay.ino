

void setup() {
  pinMode(0, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int entradaP = analogRead(A0);
  
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  delay(100);
  Serial.print("Hello World!\nValor positivo - ");
  float resultado = entradaP*(5/1023);
  Serial.println(analogRead(resultado));
}
