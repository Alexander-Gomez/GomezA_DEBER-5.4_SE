 /*
 *NOMBRE:GOMEZ ALEXANDER
 *DEBER 5.4
 *SEMAFORO
 */
 
#include <Arduino_FreeRTOS.h> // librería de RTOS
#define RED 8
#define YELLOW 7
#define GREEN 6
//objeto del gestor tareas
typedef int TaskProfiler;
TaskProfiler semaforoProfiler;
void setup() {
Serial.begin(9600);
Serial.println("Gomez Alexander");
//crear las rutinas de cada tarea
xTaskCreate(semaforoControllerTask,"semaforo Task",100,NULL,1,NULL); //rutina,nombre,memoria,NULL,prioridad,NULL
}
void semaforoControllerTask(void *pvParameters){//tarea 1
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(YELLOW,OUTPUT);
  while(1){
      //Serial.println("Proceso led rojo");
      semaforoProfiler++;
      Serial.print("Vuelta:");
      Serial.println(semaforoProfiler);
      digitalWrite(RED,HIGH);
      vTaskDelay(200);
      digitalWrite(RED,LOW);
      vTaskDelay(5);
       digitalWrite(GREEN,HIGH);
      vTaskDelay(200);
      digitalWrite(GREEN,LOW);
      vTaskDelay(5);
       digitalWrite(YELLOW,HIGH);
      vTaskDelay(200);
      digitalWrite(YELLOW,LOW);
      vTaskDelay(2);
      
    }
}
void loop() {
}
