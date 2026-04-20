// IMPORTANDO BIBLIOTECA
#include "DHT.h"

// CONFIG DOS PINOS

// botões n, p e k
int botaoN = 14;
int botaoP = 27;
int botaoK = 26;

// DHT22
#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// LDR
int ldrPin = 34;

// relé
int rele = 25;

void setup() {
  // executa uma vez
  Serial.begin(115200);

  // botões com pull-up interno
  pinMode(botaoN, INPUT_PULLUP);
  pinMode(botaoP, INPUT_PULLUP);
  pinMode(botaoK, INPUT_PULLUP);

  pinMode(rele, OUTPUT);

  dht.begin();
}

void loop() {
  // executa em loop

  // LEITURA DOS SENSORES

  int N = digitalRead(botaoN);
  int P = digitalRead(botaoP);
  int K = digitalRead(botaoK);

  float umidade = dht.readHumidity();

  int ldr = analogRead(ldrPin);

  // CONVERSÃO LDR PARA ESCALA DE PH
  float ph = (ldr / 4095.0) * 14.0;

  // EXIBIÇÃO
  Serial.println("===== DADOS =====");

  Serial.print("Umidade: ");
  Serial.print(umidade);
  Serial.println("%");

  Serial.print("pH: ");
  Serial.println(ph);

  Serial.print("N: ");
  Serial.println(N == LOW ? "BAIXO" : "OK");

  Serial.print("P: ");
  Serial.println(P == LOW ? "BAIXO" : "OK");

  Serial.print("K: ");
  Serial.println(K == LOW ? "BAIXO" : "OK");

  // LÓGICA

  bool soloSeco = (umidade < 50);

  // definição de pH inadequado
  bool phRuim = (ph < 5.5, ph > 7.5);

  // ALERTAS

  // alerta de pH
  if (phRuim) {
    Serial.println(">>> ATENÇÃO: pH fora da faixa ideal !!!");
  }

  // alertas individuais de nutrientes
  if (N == LOW) {
    Serial.println(">> ATENÇÃO: nível de Nitrogênio (N) baixo !!!");
  }

  if (P == LOW) {
    Serial.println(">> ATENÇÃO: nível de Fósforo (P) baixo !!!");
  }

  if (K == LOW) {
    Serial.println(">> ATENÇÃO: nível de Potássio (K) baixo !!!");
  }

  // decisão de irrigação (baseada na umidade do solo)
  if (soloSeco) {
    digitalWrite(rele, HIGH);
    Serial.println("> IRRIGAÇÃO LIGADA (solo seco)");
  } else {
    digitalWrite(rele, LOW);
    Serial.println("> IRRIGAÇÃO DESLIGADA (umidade adequada)");
  }

  // para melhor visualização
  Serial.println("----------------------");

  delay(6000);
}
