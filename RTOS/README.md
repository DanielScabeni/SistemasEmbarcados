<h1 align="center">
  <img src="https://raw.githubusercontent.com/DanielScabeni/SistemasEmbarcados/master/titleRtos.svg" alt="title" />
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

- O RTOS (Real-Time Operating System) é um sistema operacional para suportar a execução de aplicações em tempo real. Ele tem recursos de gerenciamento de tarefas, escalonamento, comunicação entre tarefas e controle de recursos, permitindo a execução precisa e previsível de tarefas com diferentes tempos de execução.

# Multitarefa com FreeRTOS

- O FreeRTOS é um kernel de sistema operacional de tempo real de código aberto amplamente utilizado. Ele suporta multitarefa, permitindo a execução de várias tarefas independentes ao mesmo tempo!. Cada tarefa tem sua própria prioridade, e o escalonador do FreeRTOS garante que as tarefas sejam executadas de acordo com suas prioridades.

# Sincronização de tarefas

- No RTOS, a sincronização de tarefas é usada para coordenar o acesso a recursos compartilhados entre tarefas e evitar condições de corrida. Em alguns casos, pode não ser necessário sincronizar tarefas se não houver acesso concorrente a recursos compartilhados. No entanto, em ambientes de produção mais complexos, é comum criar semáforos, mutexes ou outros mecanismos de sincronização para garantir a correta compartilhamento de recursos.
  
# Codigo Utilizado no projeto

```javascript
#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <LiquidCrystal.h>

#define LED_PIN_1 6
#define LED_PIN_2 5

LiquidCrystal lcd(12,11,10,9,8,7);

// protótipos tarefas
void TaskLeTemp(void *pvParameters);
void TaskLED(void *pvParameters);
void TaskTemp(void *pvParameters);

// Variável da temperatura
volatile float temp1 = 0.0;

void setup() {
    Serial.begin(9600);
    lcd.begin(16, 2);

    pinMode(LED_1, OUTPUT);
    pinMode(LED_2, OUTPUT);

    // Tarefas
        xTaskCreate(
        TaskLeTemp,
        "LeTemp",
        128,
        NULL,
        3,
        NULL);
    xTaskCreate(
        TaskLed1,
        "Led",
        128,
        NULL,
        3,
        NULL);
    xTaskCreate(
        TaskLedTemp,
        "LedTemp",
        128,
        NULL,
        3,
        NULL);
}

void loop(){
    // Nd aq
}

void TaskLeTemp(void *pvParameters){
    (void)pvParameters;
    float sensorValue = 0.0;
    for (;;){
        // Valor da TEMPeratura
        sensorValue = -10.0 + (rand() % 51); // Número aleatório entre -10 e 40
        temp1 = sensorValue;
        vTaskDelay(2000 / portTICK_PERIOD_MS); // Delay de 2 segundos
        lcd.setCursor(0, 0);
        lcd.print("Temp: ");
        lcd.print(temp1);
        lcd.print(" C");
    }
}
void TaskLed1(void *pvParameters){
    (void)pvParameters;
    for (;;){
        digitalWrite(LED_1, HIGH);
        vTaskDelay(500 / portTICK_PERIOD_MS);
        digitalWrite(LED_1, LOW);
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}

void TaskLedTemp(void *pvParameters){
    (void)pvParameters;
    for (;;){
        if (temp1 == 26.00){
            vTaskDelay(2000 / portTICK_PERIOD_MS);
            digitalWrite(LED_2, HIGH);
        }
    }
}
```
  
# Funcionamento do codigo
  
- Esse código é um exemplo de uso do FreeRTOS (Real-Time Operating System) em uma placa Arduino para executar tarefas simultâneas e reagir a eventos em tempo real.

- O código começa com a inclusão das bibliotecas necessárias, como o Arduino.h, o Arduino_FreeRTOS.h e o LiquidCrystal.h. Em seguida, são definidos os pinos dos LEDs e é criado um objeto do tipo LiquidCrystal para controlar um display LCD.

- São declarados os protótipos das três tarefas: TaskLeTemp, TaskLED e TaskTemp. Essas tarefas serão executadas simultaneamente pelo RTOS.

- No setup(), são iniciadas a comunicação serial, a configuração do LCD e a definição dos pinos dos LEDs como saída. Em seguida, são criadas as três tarefas utilizando a função xTaskCreate(). Cada tarefa recebe um nome, uma quantidade de memória alocada, prioridade e outros parâmetros necessários.

- A função loop() fica vazia, pois o controle das tarefas é feito pelo RTOS.

- A primeira tarefa, TaskLeTemp, é responsável por ler um valor de temperatura simulado a cada 2 segundos e atualizar o display LCD com esse valor. Ela utiliza a função vTaskDelay() para criar um atraso de 2 segundos entre as leituras.

- A segunda tarefa, TaskLed1, pisca um LED em um intervalo de 500 milissegundos, alternando entre os estados ligado e desligado.

- A terceira tarefa, TaskLedTemp, verifica se a temperatura (armazenada na variável temp1) é igual a 26.00. Se for, ela acende um segundo LED.

- Essas tarefas são executadas simultaneamente pelo RTOS, garantindo que cada uma tenha o tempo de processamento necessário e possa reagir a eventos em tempo real, como a leitura da temperatura e o controle dos LEDs.

- É importante destacar que esse é apenas um exemplo básico de uso do FreeRTOS no Arduino, e que as funcionalidades e configurações podem variar dependendo das necessidades do projeto em que o RTOS está sendo aplicado.

# Vantagens

- Gerenciamento de tempo real: O RTOS fornece garantias de tempo real, permitindo que as aplicações IoT respondam a eventos e requisitos temporais específicos.

- Multitarefa: A capacidade de executar várias tarefas simultaneamente ajuda a lidar com tarefas concorrentes em sistemas IoT complexos.

- Sincronização e comunicação entre tarefas: Os mecanismos de sincronização, como semáforos e mutexes, permitem a coordenação entre tarefas, facilitando o compartilhamento de recursos e a comunicação.

- Escalonamento de tarefas: O escalonador do RTOS garante uma execução eficiente e justa das tarefas, priorizando-as com base em suas prioridades.

- Modularidade e portabilidade: O uso de RTOS permite uma arquitetura modular e facilita a portabilidade do código entre diferentes plataformas e sistemas operacionais.

- Confiabilidade e segurança: O RTOS oferece recursos para garantir a confiabilidade e a segurança das aplicações IoT, como proteção contra estouro de pilha e isolamento de tarefas.
  
<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif">
  
<p align="center"> <img src="https://raw.githubusercontent.com/mayhemantt/mayhemantt/Update/svg/Bottom.svg" alt="DanielScabeni" /></p> 
  



 
