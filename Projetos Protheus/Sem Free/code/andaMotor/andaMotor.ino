#define frenteEsquerda 3
#define frenteDireita 6
#define trasEsquerda 5
#define trasDireita 9

void setup() {
  Serial.begin(9600);

  pinMode(frenteEsquerda, OUTPUT);
  pinMode(frenteDireita, OUTPUT);
  pinMode(trasEsquerda, OUTPUT);
  pinMode(trasDireita, OUTPUT);

  digitalWrite(frenteEsquerda, LOW);
  digitalWrite(frenteDireita, LOW);
  digitalWrite(trasEsquerda, LOW);
  digitalWrite(trasDireita, LOW);

  delay(3000);
}

void frente(){
  delay(100);
  digitalWrite(frenteEsquerda, HIGH);
  digitalWrite(frenteDireita, HIGH);
  digitalWrite(trasEsquerda, LOW);
  digitalWrite(trasDireita, LOW);

  delay(2000);
}
void esquerda(){
  delay(100);
  digitalWrite(frenteEsquerda, LOW);
  digitalWrite(frenteDireita, HIGH);
  digitalWrite(trasEsquerda, LOW);
  digitalWrite(trasDireita, LOW);

  delay(2000);
}
void direita(){
  delay(100);
  digitalWrite(frenteEsquerda, HIGH);
  digitalWrite(frenteDireita, LOW);
  digitalWrite(trasEsquerda, LOW);
  digitalWrite(trasDireita, LOW);

  delay(2000);
}
void re(){
  delay(100);
  digitalWrite(frenteEsquerda, LOW);
  digitalWrite(frenteDireita, LOW);
  digitalWrite(trasEsquerda, HIGH);
  digitalWrite(trasDireita, HIGH);

  delay(2000);
}
void loop() {
  Serial.println("Hello World!");
  frente();
  esquerda();
  frente();
  direita();
  frente();
  re();
}
