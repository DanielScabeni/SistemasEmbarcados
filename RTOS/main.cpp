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