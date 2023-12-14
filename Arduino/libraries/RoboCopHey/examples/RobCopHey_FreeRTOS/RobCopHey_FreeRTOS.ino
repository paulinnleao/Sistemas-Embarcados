#include "robocophey.h"
#include "FreeRTOSConfig.h"
#include "task.h"
#include "Arduino_FreeRTOS.h"
#include <semphr.h>
RoboCopHey roboCopHey(3, 6, 5, 9);

TaskHandle_t frenteTask = NULL;
TaskHandle_t direitaTask = NULL;
TaskHandle_t esquerdaTask = NULL;
TaskHandle_t pararTask = NULL;
TaskHandle_t reTask = NULL;
TaskHandle_t reDireitaTask = NULL;
TaskHandle_t reEsquerdaTask = NULL;
TaskHandle_t iniciaTaskHandle = NULL;

void iniciaTask(void* parametro){
  while(1){
    Serial.println("Iniciando Tasks.");
    vTaskSuspend(direitaTask);
    vTaskSuspend(esquerdaTask);
    vTaskSuspend(pararTask);
    vTaskSuspend(reTask);
    vTaskSuspend(reDireitaTask);
    vTaskSuspend(reEsquerdaTask);
    vTaskResume(frenteTask);
    vTaskSuspend(NULL);
    }
}

void setup() {

  Serial.begin(9600);
  // xTaskCreate(TaskMain, 'TaskMain', 1000, NULL, 1, NULL);
  xTaskCreate(iniciaTask, "IniciaTask", 50, NULL, 1, &iniciaTaskHandle);
  xTaskCreate(frente, "Frente", 50, NULL, 1, &frenteTask);
  xTaskCreate(direita, "Direita", 50, NULL, 1, &direitaTask);
  xTaskCreate(esquerda, "Esquerda", 50, NULL, 1, &esquerdaTask);
  xTaskCreate(parar, "Parar", 50, NULL, 1, &pararTask);
  xTaskCreate(re, "Re", 50, NULL, 1, &reTask);
  xTaskCreate(reDireita, "ReDireita", 50, NULL, 1, &reDireitaTask);
  xTaskCreate(reEsquerda, "ReEsquerda", 50, NULL, 1, &reEsquerdaTask);
}

void loop() {
}
void frente(void* parametro) {
  while(1){
    Serial.println("Robo andando para frente");
    roboCopHey.Frente();
    vTaskDelay(900 / portTICK_PERIOD_MS);
    vTaskResume(direitaTask);
    vTaskSuspend(NULL);
  }
}
void direita(void* parametro) {
  while(1){
    Serial.println("Robo andando para direita");
    roboCopHey.Direita();
    vTaskDelay(900 / portTICK_PERIOD_MS);
    vTaskResume(esquerdaTask);
    vTaskSuspend(NULL);
  }
}
void esquerda(void* parametro) {
  while(1){
    Serial.println("Robo andando para esquerda");
    roboCopHey.Esquerda();
    vTaskDelay(900 / portTICK_PERIOD_MS);
    vTaskResume(pararTask);
    vTaskSuspend(NULL);
  }
}
void parar(void* parametro) {
  while(1){
    Serial.println("Robo parado");
    roboCopHey.Parar();
    vTaskDelay(900 / portTICK_PERIOD_MS);
    vTaskResume(reTask);
    vTaskSuspend(NULL);
    }
}
void re(void* parametro) {
  while(1){
    Serial.println("Robo andando de reh");
    roboCopHey.Re();
    vTaskDelay(900 / portTICK_PERIOD_MS);
    vTaskResume(reDireitaTask);
    vTaskSuspend(NULL);
    }
}
void reDireita(void* parametro) {
  while(1){
    Serial.println("Robo virando de reh para direita");
    roboCopHey.ReDireita();
    vTaskDelay(900 / portTICK_PERIOD_MS);
    vTaskResume(reEsquerdaTask);
    vTaskSuspend(NULL);
  }
}
void reEsquerda(void* parametro) {
  while(1){
    Serial.println("Robo virando de reh para esquerda");
    roboCopHey.ReEsquerda();
    vTaskDelay(900 / portTICK_PERIOD_MS);
    vTaskResume(iniciaTaskHandle);
    vTaskSuspend(NULL);
    }
}
// static void TaskMain(void* parametro) {
//   Frente();
//   Direita();
//   Esquerda();
//   Parar();
//   Re();
//   ReDireita();
//   ReEsquerda();
//   while(1){
//     roboCopHey.Frente();
//     vTaskDelay(1000 / portTICK_PERIOD_MS);
//     roboCopHey.Direita();
//     vTaskDelay(1000 / portTICK_PERIOD_MS);
//     roboCopHey.Esquerda();
//     vTaskDelay(1000 / portTICK_PERIOD_MS);
//     roboCopHey.Parar();
//     vTaskDelay(1000 / portTICK_PERIOD_MS);
//     roboCopHey.Re();
//     vTaskDelay(1000 / portTICK_PERIOD_MS);
//     roboCopHey.ReDireita();
//     vTaskDelay(1000 / portTICK_PERIOD_MS);
//     roboCopHey.ReEsquerda();
//     vTaskDelay(1000 / portTICK_PERIOD_MS);
//   }
// }