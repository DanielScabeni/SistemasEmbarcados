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

# O que é o PWM ?

- PWM significa "Pulse Width Modulation" (Modulação por Largura de Pulso, em português). É uma técnica amplamente utilizada para controlar a quantidade de energia fornecida a dispositivos eletrônicos, como motores, LEDs e circuitos de áudio.

- O PWM envolve o envio de pulsos elétricos com uma largura variável, onde a relação entre o tempo em que o pulso está em nível alto (ligado) e o tempo em que está em nível baixo (desligado) determina a quantidade média de energia fornecida ao dispositivo. Isso permite controlar a intensidade de um LED, a velocidade de um motor ou o volume de um alto-falante, por exemplo.

# Componentes Utilizados

<h3>
  - Microcontrolador: Arduino Nano
</h3>
- O Arduino Nano é uma placa de desenvolvimento baseada em microcontrolador que oferece uma plataforma flexível e de baixo custo para criar projetos eletrônicos.

<h3>
- Fonte 5V:
  </h3>
-Uma fonte de alimentação de 5V fornece uma tensão constante de 5 volts para alimentar os componentes do circuito. No caso do Arduino Nano, é comum utilizar uma fonte de alimentação externa de 5V para fornecer energia à placa e aos componentes conectados a ela.

<h3>
- Botão:
</h3>
  -Um botão é um dispositivo de entrada simples que pode ser pressionado para enviar um sinal ao Arduino. O Arduino pode detectar esse sinal e executar ações específicas com base nessa entrada, como acionar um motor ou alterar o estado de um LED.

<h3>
- Resistor:
</h3>
  -O resistor é um componente eletrônico usado para limitar ou controlar o fluxo de corrente em um circuito. Ele pode ser usado para proteger componentes sensíveis, ajustar o nível de tensão, dividir a tensão, entre outros propósitos.

<h3>
- Ponte H:
</h3>
  -A ponte H é um circuito que permite controlar a direção e a velocidade de motores DC utilizando sinais PWM do Arduino. Ela recebe os sinais do Arduino e os modula de forma apropriada para transmitir a potência necessária aos componentes, como motores ou LEDs.

<h3>
- Motor elétrico:
</h3>
-Um motor elétrico é um dispositivo que converte energia elétrica em energia mecânica. Ele pode ser usado para gerar movimento em um sistema, como em robôs, veículos ou máquinas. O Arduino pode controlar um motor elétrico através da ponte H, ajustando a velocidade e a direção do movimento.

# Schematic do controlador PWM

<div align=center>
<a href="https://github.com/DanielScabeni">
<img height="500em" src="./schematic/eschemas.png">
</div>
  
# Codigo Utilizado no projeto

  ```javascript
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
  ```
  
# Funcionamento do codigo
  
- Esse código em Arduino trata-se de um sistema de controle de velocidade de um motor utilizando um botão como interface. Analise passo a passo:

- No início do código, são definidas as constantes BUTTON_PIN e PWM, que representam as portas utilizadas para o botão e o controle PWM do motor, respectivamente.

- Em seguida, são declaradas as variáveis estado_botao e pwm para armazenar o estado atual do botão e o valor do PWM, respectivamente. Também são declaradas as variáveis ultimo_estado_botao para armazenar o último estado do botão, tempo_acionado para registrar o tempo de acionamento do botão e tempo_delay para definir o tempo de espera entre as alterações de velocidade.

- Na função setup(), as configurações iniciais são feitas. O pino do motor (PWM) é configurado como saída e o pino do botão é configurado como entrada com o resistor de pull-up interno ativado através da função pinMode(BUTTON_PIN, INPUT_PULLUP).

- A função loop() é o loop principal do programa, onde ocorre a leitura do botão e o controle da velocidade do motor.

- A variável leitura armazena o estado atual do botão (HIGH ou LOW) através da função digitalRead(BUTTON_PIN).

- Em seguida, é feita uma verificação se o estado do botão é diferente do último estado registrado (leitura != ultimo_estado_botao). Isso permite detectar quando o botão é pressionado.

- Se o botão foi pressionado (leitura == HIGH), a variável tempo_acionado recebe o valor atual do tempo em milissegundos através da função millis(). Isso marca o tempo de acionamento do botão.

- Em seguida, é feita uma verificação se o botão está pressionado (leitura == HIGH) e se o tempo decorrido desde o acionamento (millis() - tempo_acionado) é maior que o tempo de delay (tempo_delay). Isso garante que a velocidade do motor só será alterada após um determinado intervalo de tempo.

- Se as condições anteriores forem atendidas, a variável pwm é incrementada em 64. Esse valor foi escolhido como exemplo, mas pode ser ajustado conforme necessário.

- A próxima verificação é para limitar a velocidade máxima do motor. Se a variável pwm ultrapassar o valor 255 (limite do PWM), ela é resetada para 0.

- Por fim, a função analogWrite(PWM, pwm) é utilizada para definir a velocidade do motor através da técnica PWM. O valor da variável pwm é passado como parâmetro para controlar a largura do pulso PWM enviado ao pino do motor.

- O programa aguarda um pequeno intervalo de tempo definido pela função delay(50) antes de repetir o loop.
#
- Resumindo, esse código permite controlar a velocidade do motor através do botão, onde cada pressionamento aumenta a velocidade em um valor específico. O valor da velocidade é ajustado de forma incremental e limitado ao valor máximo. O uso do PWM (através da função 
  
<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif">
  
<p align="center"> <img src="https://raw.githubusercontent.com/mayhemantt/mayhemantt/Update/svg/Bottom.svg" alt="DanielScabeni" /></p> 
  



 
