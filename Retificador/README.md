<h1 align="center">
  <img src="https://raw.githubusercontent.com/DanielScabeni/SistemasEmbarcados/master/titleRet.svg" alt="title" />
</h1>

<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif">

<table>
  <tr>
    <td width="50%">
      <a href="https://github.com/DanielScabeni/SistemasEmbarcados/tree/main/Retificador">
        <img src="https://github-readme-stats.vercel.app/api/pin/?username=DanielScabeni&repo=SistemasEmbarcados&theme=chartreuse-dark" alt="Readme Card">
      </a>
    </td>
    <td width="50%">
  </a>
    <p style="color: white;">Trabalho sobre Retificador, solicitado pelo professor Dr. Rafael babosa, para a materia de Sistemas Embarcados do curso de Sistemas de Informações da Universidade MaterDei (UNIMATER)</p>
    </td>
  </tr>
</table>

<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif">

# O que é um Retificador ?

- Um retificador é um dispositivo eletrônico utilizado para converter corrente alternada (AC) em corrente contínua (DC). Ele realiza essa conversão através de diodos retificadores, que permitem a passagem de corrente em apenas uma direção.

- Existem diferentes tipos de retificadores, os mais comuns são o retificador de meia onda e o retificador de onda completa. O retificador de meia onda utiliza um único diodo para retificar apenas metade do ciclo da corrente alternada, e o retificador de onda completa utiliza dois diodos para retificar ambos os semiciclos da corrente alternada.

# A ponte de diodos 

- Uma ponte de diodos é um circuito eletrônico que utiliza quatro diodos retificadores para converter corrente alternada (AC) em corrente contínua (DC).

- É uma das configurações mais comuns e eficientes para a retificação de corrente alternada, permitindo obter uma retificação de onda completa. Ela é amplamente utilizada em diversas aplicações que requerem a conversão de AC para DC, como fontes de alimentação, carregadores de bateria, inversores de frequência, entre outros.

- A ponte de diodos consiste em quatro diodos retificadores (geralmente diodos de junção PN) conectados em uma configuração específica. Dois diodos são dispostos em série com a polaridade reversa, formando um lado da ponte, e os outros dois diodos são dispostos em série com a polaridade direta, formando o outro lado da ponte. Os pontos de junção dos diodos formam os terminais de saída da ponte, onde é obtida a corrente contínua retificada.
  Quando a corrente alternada é aplicada à entrada da ponte de diodos, a configuração em ponte permite que a corrente seja retificada em ambos os semiciclos da onda, resultando em uma corrente contínua de polaridade constante na saída.

- A ponte de diodos oferece diversas vantagens, como uma retificação completa da corrente alternada, maior eficiência em relação a outros tipos de retificadores e facilidade de implementação. Ela se tornou uma solução padrão para retificação de corrente alternada em uma ampla gama de aplicações eletrônicas.

# Schematic do Retificador no Proteus

<div align=center>
<a href="https://github.com/DanielScabeni">
<img src="./schematics/Proteus1.png">
</div>

# Componentes 

- O conector macho de duas entradas (J1) é a porta de entrada para a energia elétrica no circuito. Ele permite a conexão direta do transformador ao circuito, fornecendo a energia necessária para o funcionamento dos componentes.

- BR1 (BIRDGR) Na ponte de diodos, os quatro diodos são arranjados em uma estrutura que forma uma ponte, permitindo que a corrente flua em uma direção específica.

- Capacitores C1, C2 e C3, são utilizados para ajudar a manter uma corrente mais constante durante a inversão na ponte de diodos. Eles desempenham um papel importante ao armazenar e liberar cargas elétricas, ajudando a suavizar a tensão e fornecer uma corrente mais estável.

- Regulador de tensão (UI), sua função basicamente é manter a tensão constante, protegendo os dispositivos eletrônicos contra variações de tensão que possam afetar seu desempenho ou causar danos.

- Resistor (R1): é um componente eletrônico que limita o fluxo de corrente em um circuito. Ele desempenha diversas funções, como controlar a intensidade da corrente, ajustar a tensão, dividir a tensão e polarizar transistores.
  
- LED: Um diodo emissor de luz
#
- **Dessa maneira.** O conector desempenha o papel de fornecer energia elétrica ao circuito. A ponte de diodo é responsável por transformar a corrente alternada gerada em corrente contínua, garantindo uma fonte de energia estável. Os capacitores são utilizados estrategicamente para manter o LED aceso de forma contínua, mesmo durante as reversões de corrente da ponte de diodo. Por fim, o resistor desempenha a importante função de regular a intensidade da corrente que flui pelo circuito, permitindo um controle preciso da luminosidade do LED. Dessa forma, o LED permanece constantemente iluminado, enquanto o restante do circuito opera em corrente alternada.
  
# PCB do circuito
  
![image](https://github.com/DanielScabeni/SistemasEmbarcados/blob/main/Retificador/schematics/pcb-Ponte1.png?raw=true)

# Montagem do circuito em uma protoboard representado no TinkerCad
  
![image](https://github.com/DanielScabeni/SistemasEmbarcados/blob/main/Retificador/schematics/RetTink1.png?raw=true)

# Circuito montado em uma Protoboard

![image](https://github.com/DanielScabeni/SistemasEmbarcados/blob/main/Retificador/schematics/CircRet1.jpeg?raw=true)
  
# Divisor de tensão

<h3>
  <p> 
    A parte final do exercicio consistia em implementar nesse circuito um divisor de tensão
  <p/>
</h3>

Um divisor de tensão é um circuito utilizado para obter uma fração de uma tensão de entrada maior. Ele consiste em dois resistores ligados em série entre a fonte de tensão e o terra, com um ponto de conexão entre eles. A tensão de saída é obtida nesse ponto de conexão.
  
# Circuito com um divisor de tensão
![image](https://github.com/DanielScabeni/SistemasEmbarcados/blob/main/Retificador/schematics/RetTink2.png?raw=true)

# Implementação do divisor de tensão na protboard
  
![image](https://github.com/DanielScabeni/SistemasEmbarcados/blob/main/Retificador/schematics/CircRet2.png?raw=true)
  
<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif">
  
<p align="center"> <img src="https://raw.githubusercontent.com/mayhemantt/mayhemantt/Update/svg/Bottom.svg" alt="DanielScabeni" /></p> 
  
