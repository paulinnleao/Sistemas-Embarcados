#define ROBOCOPHEY_H

#include "Arduino.h"
#include "Arduino_FreeRTOS.h"

class RoboCopHey{

      public:
         // Construtor
         RoboCopHey(int esquerdaHorario, int direitaHorario, int esquerdaAntiHorario, int direitaAntiHorario);
         
         void Frente();
         void Direita();
         void Esquerda();
         void Parar();
         void Re();
         void ReDireita	();
         void ReEsquerda();
         
      private:
         int _esquerdaHorario;
         int _direitaHorario;
         int _esquerdaAntiHorario;
         int _direitaAntiHorario;
      };
