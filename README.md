# FarmTech Solutions – Sistema de Irrigação Inteligente

## Descrição do Projeto

O projeto foi desenvolvido como segunda etapa das atividades da FarmTech Solutions. O objetivo é simular um sistema de irrigação inteligente utilizando o microcontrolador ESP32 na plataforma Wokwi.

O sistema monitora as condições do solo por meio de sensores simulados, que permitem a tomada de decisão automática sobre a irrigação (com base nas variáveis: umidade do solo, pH edo solo e níveis de nutrientes N, P e K no solo).

## Componentes utilizados

- ESP32  
- Sensor DHT22 (simulando umidade do solo)  
- Sensor LDR (simulando pH do solo)  
- 3 botões (simulando os nutrientes N, P e K)  
- Módulo relé (simulando a bomba de irrigação)  

## Funcionamento do sistema

O sistema faz leituras contínuas dos sensores e interpreta os dados para simular as condições de uma plantação. Nesse caso, de cana-de-açúcar (uma das culturas usadas na atividade anterior).

### Umidade do solo

A umidade é obtida por meio do sensor DHT22  
Valores abaixo de 50% indicam que o solo está seco

### Nutrientes (N, P e K)

Os nutrientes são representados por botões:

- Botão pressionado significa que nutriente está em nível baixo  
- Botão não pressionado significa que nutriente está em nível adequado  

### pH do solo

O pH é simulado utilizando o sensor LDR 
O valor analógico do sensor é convertido para uma escala de 0 a 14 no código

A faixa considerada ideal está entre 5.5 e 7.5

O pH não interfere diretamente na irrigação, ele serve apenas como um alerta para o usuário

## Lógica de irrigação

A irrigação é acionada automaticamente quando as seguintes condições são atendidas:

- O solo está seco (umidade menor que 50%)  
- Existe deficiência em pelo menos um nutriente (N, P ou K)

A lógica implementada é:

if (soloSeco && nutrienteBaixo), a irrigação é ativada

## Alerta de pH

Quando o pH está fora da faixa ideal (menor que 5.5 ou maior que 7.5), o sistema exibe uma mensagem de alerta no monitor serial: ">>> ATENÇÃO: pH fora da faixa ideal !!!"

## Execução do sistema

O sistema opera em loop contínuo, realizando as seguintes etapas:

1. Leitura dos sensores  
2. Exibição dos dados no monitor serial  
3. Verificação das condições  
4. Acionamento ou desligamento da irrigação  

As leituras são atualizadas a cada 6 segundos

## Testes realizados

Durante a simulação, foram realizados testes práticos para validar o funcionamento do sistema em diferentes condições.

Inicialmente, o sistema foi executado com pH dentro da faixa ideal e sem nenhum botão pressionado, verificando que a irrigação permaneceu desligada.

Em seguida, mantendo o pH ideal, foram pressionados individualmente os botões correspondentes aos nutrientes K, P e N. O objetivo foi verificar se o sistema identificava corretamente a deficiência de nutrientes e ativava a irrigação conforme esperado.

Posteriormente, nenhum botão foi pressionado e o pH foi ajustado para um valor altamente alcalino (13.89). Nessa condição, foi possível observar que o sistema emitiu o alerta de pH fora da faixa ideal, sem acionar a irrigação.

Na sequência, mantendo o pH alcalino, foi pressionado o botão referente ao nutriente P, verificando o comportamento do sistema com a combinação de pH inadequado e deficiência do nutriente.

Depois disso, o pH foi ajustado para um valor extremamente ácido (0.11), sem pressionar nenhum botão, validando novamente a emissão do alerta de pH.

Por fim, o sistema foi retornado ao estado inicial, com pH dentro da faixa ideal e sem nenhum botão pressionado, confirmando a estabilidade do funcionamento.

## Imagem do circuito

Abaixo estão as imagens do circuito montado na plataforma Wokwi:

![Circuito no Wokwi](https://github.com/miolodenoia/repo_atvcap1fase2/blob/main/imagem-circuito.png?raw=true)

## Demonstração em vídeo

(https://youtu.be/_nzHUcyIOLw)

## Código fonte

O código completo do projeto está disponível nesse repositório

## Conclusão

O projeto demonstra na prática como sensores e lógica de programação podem ser utilizados para automatizar processos agrícolas, principalmente no contexto da agricultura digital. Essa simulação permitiu compreender como variáveis como umidade, nutrientes e pH influenciam na tomada de decisão de irrigação em uma plantação.
