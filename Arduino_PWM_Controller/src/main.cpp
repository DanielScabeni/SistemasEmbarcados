#include <Arduino.h>


#define BUTTON_PIN 2 //define as portas
#define PWM 9 


int estado_botao = 0; //variaveis uteis
int pwm = 0; 
int ultimo_estado_botao = 0;
unsigned long tempo_acionado = 0;
unsigned long tempo_delay = 50;

void setup() {
  pinMode(PWM, OUTPUT); //seta os pinos
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  int var = 64;
}

void loop() {

  int leitura = digitalRead(BUTTON_PIN); // le o estado do botao na variavel do pino

  if (leitura != ultimo_estado_botao) { //se o estado do botao estiver diferente do estado anterior
    ultimo_estado_botao = leitura; // atualiza o estado anterior 
    if (leitura == HIGH) { // se o botao tiver ligado
      tempo_acionado = millis();// salva o tempo 
    }
  }

  if (leitura == HIGH && ((millis() - tempo_acionado) > tempo_delay)) { // se o botao tiver ligado e a diferença entre o tempo atual e o tempo que ele foi pressionado for maior que o delay
    pwm += 64;
  }

  if (pwm > 255){ //se o motor ja tiver no seu maximo, resetaa
    pwm = 0;
  }

  analogWrite(PWM, pwm); //seta a velocidade definida nas variaveis anteriores
  delay(50);
}