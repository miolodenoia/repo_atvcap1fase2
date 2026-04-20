# FarmTech Solutions – Sistema de Irrigação Inteligente

## Descrição do Projeto

O projeto foi desenvolvido como segunda etapa das atividades da FarmTech Solutions. O objetivo é simular um sistema de irrigação inteligente utilizando o microcontrolador ESP32 na plataforma Wokwi.

O sistema monitora as condições do solo por meio de sensores simulados, permitindo a tomada de decisão automática sobre a irrigação com base na umidade do solo. Com base nos níveis de nutrientes e pH, o sistema fornece alertas.

## Componentes utilizados

- ESP32  
- Sensor DHT22 (simulando umidade do solo)  
- Sensor LDR (simulando pH do solo)  
- 3 botões (simulando os nutrientes N, P e K)  
- Módulo relé (simulando a bomba de irrigação)  

## Funcionamento do sistema

O sistema faz leituras contínuas dos sensores e interpreta os dados para simular as condições de uma plantação. Nesse caso, de cana-de-açúcar (uma das culturas usadas na atividade anterior).

### Umidade do solo

- A umidade é obtida por meio do sensor DHT22  
- Valores abaixo de 50% indicam que o solo está seco

### Nutrientes (N, P e K)

Os nutrientes são representados por botões:

- Botão pressionado significa que nutriente está em nível baixo  
- Botão não pressionado significa que nutriente está em nível adequado

Quando um nutriente está baixo, uma mensagem de alerta específica é exibida, indicando qual nutriente é esse que apresenta deficiência.

### pH do solo

- O valor obtido pelo sensor é convertido para uma escala de 0 a 14 no código
- A faixa considerada ideal é entre 5.5 e 7.5

O pH não interfere diretamente na irrigação, ele serve apenas como um alerta para o usuário.

## Lógica de irrigação

A irrigação é acionada exclusivamente com base na umidade do solo:

- Se a umidade for menor que 50%, a irrigação é ligada
- Acima disso, a irrigação permanece desligada

## Execução do sistema

O sistema opera em loop contínuo, e realiza:

1. Leitura dos sensores
2. Exibição dos dados no monitor serial
3. Verificação das condições
4. Acionamento ou desligamento da irrigação
5. Exibição de alertas

As leituras são atualizadas a cada 6 segundos. 

## Testes realizados

Os testes foram realizados de forma progressiva, variando uma condição por vez e, posteriormente, combinando múltiplos fatores.

Inicialmente, o sistema foi executado com condições ideais: umidade em 80.5% e pH em 6.99, sem nenhum botão pressionado. Nessa situação, todos os nutrientes estavam em nível adequado, não havendo exibição de alertas e com a irrigação desligada.

Em seguida, foram testados individualmente os botões correspondentes aos nutrientes K, P e N, mantendo as condições ideais de umidade e pH. O sistema identificou corretamente cada nutriente como baixo, exibindo a indicação "BAIXO" e a mensagem de alerta correspondente (">> ATENÇÃO: nível de Nutriente (X) baixo !!!")

Posteriormente, a umidade foi reduzida para 34.5%, caracterizando solo seco. Nessa condição, a irrigação foi automaticamente ativada, sem alterações nos níveis de pH ou nutrientes.

Na sequência, a umidade foi mantida em 34.5% e um dos botões (K) foi pressionado. O sistema apresentou simultaneamente a irrigação ligada e o alerta de nutriente baixo.

Após isso, a umidade foi ajustada para 64.5%, retornando a um nível adequado, o que resultou no desligamento da irrigação. Ao mesmo tempo, o pH foi ajustado para um valor altamente alcalino (13.89) e o botão referente ao nutriente P foi pressionado. O sistema exibiu corretamente os alertas de pH fora da faixa ideal e de nutriente baixo, mantendo a irrigação desligada.

Em seguida, a umidade foi reduzida para 10.5%, mantendo o pH alcalino. Nessa situação, a irrigação foi ativada devido ao solo seco, e o sistema continuou exibindo o alerta de pH inadequado. Ao pressionar um dos botões, foi possível observar simultaneamente os três tipos de mensagens do sistema: irrigação ligada, alerta de pH e alerta de nutriente.

Por fim, todos os parâmetros foram retornados para condições ideais.

## Imagem do circuito

Abaixo está a imagem do circuito montado na plataforma Wokwi:

![Circuito no Wokwi](https://github.com/miolodenoia/repo_atvcap1fase2/blob/main/imagem-circuito.png?raw=true)

## Demonstração em vídeo

(https://youtu.be/sENquvuoBEg)

## Código fonte

O código completo do projeto está disponível na pasta 'src' nesse repositório.

## Conclusão

O projeto demonstra, na prática, como sensores e lógica de programação podem ser utilizados para automatizar processos agrícolas no contexto da agricultura digital. A separação entre o controle de irrigação e o monitoramento das variáveis de pH e nutrientes permite que a irrigação responda diretamente à umidade do solo, enquanto os demais fatores auxiliam na análise e na tomada de decisão.
