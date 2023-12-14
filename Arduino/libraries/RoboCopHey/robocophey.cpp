#include "Arduino.h"
#include "Arduino_FreeRTOS.h"
#include "robocophey.h"

RoboCopHey::RoboCopHey(int esquerdaHorario, int direitaHorario, int esquerdaAntiHorario, int direitaAntiHorario){
    pinMode(esquerdaHorario, OUTPUT);
    pinMode(direitaHorario, OUTPUT);
    pinMode(esquerdaAntiHorario, OUTPUT);
    pinMode(direitaAntiHorario, OUTPUT); 

    _esquerdaHorario = esquerdaHorario;
    _direitaHorario = direitaHorario;
    _esquerdaAntiHorario = esquerdaAntiHorario;
    _direitaAntiHorario = direitaAntiHorario;
}

void RoboCopHey::Frente(){
    // Motor da esquerda
    digitalWrite(_esquerdaHorario, HIGH);
    digitalWrite(_esquerdaAntiHorario, LOW);

    // Motor da direita
    digitalWrite(_direitaHorario, HIGH);
    digitalWrite(_direitaAntiHorario, LOW);
}

void RoboCopHey::Direita(){
    // Motor da esquerda
    digitalWrite(_esquerdaHorario, HIGH);
    digitalWrite(_esquerdaAntiHorario, LOW);

    // Motor da direita
    digitalWrite(_direitaHorario, LOW);
    digitalWrite(_direitaAntiHorario, LOW);
}
void RoboCopHey::Esquerda(){
    // Motor da esquerda
    digitalWrite(_esquerdaHorario, LOW);
    digitalWrite(_esquerdaAntiHorario, LOW);

    // Motor da direita
    digitalWrite(_direitaHorario, HIGH);
    digitalWrite(_direitaAntiHorario, LOW);
}
void RoboCopHey::Parar(){
    // Motor da esquerda
    digitalWrite(_esquerdaHorario, LOW);
    digitalWrite(_esquerdaAntiHorario, LOW);

    // Motor da direita
    digitalWrite(_direitaAntiHorario, LOW);
    digitalWrite(_direitaHorario, LOW);
}
void RoboCopHey::Re(){
    // Motor da esquerda
    digitalWrite(_esquerdaHorario, LOW);
    digitalWrite(_esquerdaAntiHorario, HIGH);

    // Motor da direita
    digitalWrite(_direitaHorario, LOW);
    digitalWrite(_direitaAntiHorario, HIGH);
}
void RoboCopHey::ReDireita(){
    // Motor da esquerda
    digitalWrite(_esquerdaHorario, LOW);
    digitalWrite(_esquerdaAntiHorario, HIGH);

    // Motor da direita
    digitalWrite(_direitaHorario, LOW);
    digitalWrite(_direitaAntiHorario, LOW);
}
void RoboCopHey::ReEsquerda(){
    // Motor da esquerda
    digitalWrite(_esquerdaHorario, LOW);
    digitalWrite(_esquerdaAntiHorario, LOW);

    // Motor da direita
    digitalWrite(_direitaHorario, LOW);
    digitalWrite(_direitaAntiHorario, HIGH);
}
