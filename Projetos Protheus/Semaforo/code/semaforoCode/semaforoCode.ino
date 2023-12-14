#include "Arduino_FreeRTOS.h"
#include "task.h"
#include <semphr.h>

TaskHandle_t vermelhoTask = NULL;
TaskHandle_t amareloTask = NULL;
TaskHandle_t verdeTask = NULL;

int ledVermelho = 4;
int ledAmarelo = 3;
int ledVerde = 2;

void setup() {
  Serial.begin(9600);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);

  xTaskCreate(acendeVerde, "acendeVerde", 128, NULL, 1, &verdeTask);
  xTaskCreate(acendeAmarelo, "acendeAmarelo", 128, NULL, 1, &amareloTask);
  xTaskCreate(acendeVermelho, "acendeVermelho", 128, NULL, 1, &vermelhoTask);
}


  // xTaskCreate(Semaforo, 'Semaforo', 1000, NULL, 1, NULL);

void loop() {
  // put your main code here, to run repeatedly:

}
void acendeVerde(void *pvParameters){
  while(1){
    Serial.println("Verde");
    // vTaskSuspend(vermelhoTask);

    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, HIGH);

    vTaskDelay(500 / portTICK_PERIOD_MS);
    // //setPrioridade(amareloTask, verdeTask, vermelhoTask);
    vTaskResume(amareloTask);
    vTaskSuspend(NULL);
  }
}
void acendeAmarelo(void *pvParameters){
  while(1){
    Serial.println("Amarelo");
    
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVerde, LOW);

    vTaskDelay(500 / portTICK_PERIOD_MS);
    
    // //setPrioridade(vermelhoTask, amareloTask, verdeTask);
    vTaskResume(vermelhoTask);
    vTaskSuspend(NULL);
  }
}
void acendeVermelho(void *pvParameters){
  while(1){
    Serial.println("Led vermelho");
    // vTaskSuspend(amareloTask);

    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, LOW);

    vTaskDelay(500 / portTICK_PERIOD_MS);
    // //setPrioridade(verdeTask, vermelhoTask, amareloTask);
    vTaskResume(verdeTask);
    vTaskSuspend(NULL);
  }
}

void setPrioridade(TaskHandle_t executa, TaskHandle_t espera_1, TaskHandle_t espera_2){
  vTaskPrioritySet(executa, 1);
  vTaskPrioritySet(espera_1, 2);
  vTaskPrioritySet(espera_2, 2);
}

// void Semaforo(void*parametro){
//   while(1){
//     acendeTodos();
//     vTaskDelay(1000 / portTICK_PERIOD_MS);
//     acendeVermelho();
//     vTaskDelay(1000 / portTICK_PERIOD_MS);
//     acendeAmarelo();
//     vTaskDelay(1000 / portTICK_PERIOD_MS);
//     acendeVerde();
//     vTaskDelay(1000 / portTICK_PERIOD_MS);
//     apagaTodos();
//     vTaskDelay(1000 / portTICK_PERIOD_MS);
//   }
// }
// void acendeTodos(){
//   digitalWrite(ledVermelho, HIGH);
//   digitalWrite(ledAmarelo, HIGH);
//   digitalWrite(ledVerde, HIGH);
  
//   vTaskDelay(3000 / portTICK_PERIOD_MS);
//   xSemaphoreGive(xSemaphoreYellow);
// }

// void apagaTodos(){
//   digitalWrite(ledVermelho, LOW);
//   digitalWrite(ledAmarelo, LOW);
//   digitalWrite(ledVerde, LOW);
// }