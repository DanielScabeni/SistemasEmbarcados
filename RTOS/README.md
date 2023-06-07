<h1 align="center">
  <img src="https://raw.githubusercontent.com/DanielScabeni/SistemasEmbarcados/master/titlePwm.svg" alt="title" />
</h1>

<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif">

<table>
  <tr>
    <td width="50%">
      <a href="https://github.com/DanielScabeni/SistemasEmbarcados/tree/main/Arduino_PWM_Controller">
        <img src="https://github-readme-stats.vercel.app/api/pin/?username=DanielScabeni&repo=SistemasEmbarcados&theme=chartreuse-dark" alt="Readme Card">
      </a>
    </td>
    <td width="50%">
  </a>
    <p style="color: white;">Trabalho sobre PWM (Pulse Width Modulator), solicitado pelo professor Dr. Rafael babosa, para a materia de Sistemas Embarcados do curso de Sistemas de Informações da Universidade MaterDei (UNIMATER)</p>
    </td>
  </tr>
</table>

<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif">

# Introdução ao RTOS

- 

# Multitarefa com FreeRTOS

- 

# Schematic do controlador PWM

- 

# Sincronização de tarefas

- 
  
# Codigo Utilizado no projeto

  ```
#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <LiquidCrystal.h>



LiquidCrystal lcd(12,11,10,9,8,7);

// protótipos para as tarefas
void TaskReadTemperature(void *pvParameters);

// Variável para armazenar a temperatura lida
volatile float temperature = 0.0;

void setup() {
 Serial.begin(9600);

 lcd.begin(16,2);

 // cria as tarefas
 xTaskCreate(
 TaskReadTemperature,
 "ReadTemperature",
 128,
 NULL,
 3,
 NULL );

//Crie as outras tarefas aqui

}
void loop() {
 // nada aqui!
}

void TaskReadTemperature(void *pvParameters) {
 (void) pvParameters;
 float sensorValue = 0.0;
 for (;;) {

 // Aqui você normalmente leria o valor do sensor de temperatura.
 // Por simplicidade, vamos apenas simular um sensor variando a
temperatura de -10 a 40.
 sensorValue = -10.0 + (rand() % 51); // gera um número aleatório entre
-10 e 40
 temperature = sensorValue;
 vTaskDelay(2000 / portTICK_PERIOD_MS); // aguarda por 2 segundos

 lcd.setCursor(0,0);
 lcd.print("Temp: ");
 lcd.print(temperature);
 lcd.print(" C");


 // vTaskDelay(1000 / portTICK_PERIOD_MS);
 }
}
////////////////////////////////////////////////////////////////
  ```
  
# Funcionamento do codigo
  
- 

# Vantagens

 - 
  
<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif">
  
<p align="center"> <img src="https://raw.githubusercontent.com/mayhemantt/mayhemantt/Update/svg/Bottom.svg" alt="DanielScabeni" /></p> 
  



 
