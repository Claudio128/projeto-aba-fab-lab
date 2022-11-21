// Pode ser necessário alterar o "valor limite de disparo" para encontrar um valor adequado
// para ligar e desligar o LED quando "mover a mão" sobre o fotoresistor (LDR)
int limiteDisparo = 600;

// Ligue o LED ao pino digital 9
int led = 9;

// O fotoresistor (LDR) é conectado ao pino analógico 0
int sensor = A0;

// Armazena o valor de leitura analógica
int sensorValue = 0;


int brightness = 0;
int fadeAmount = 5;
void setup() {
  
  // Define o LED como uma saída
  pinMode(led, OUTPUT);
  
  // Define o fotoresistor como uma entrada
  pinMode(sensor, INPUT);
  
  // Inicia a comunicação serial com uma taxa de transmissão de 9600 boud rate
  Serial.begin(9600);
}

void loop(){
  analogWrite(led, brightness);
  
  // Lê o valor atual do fotoresistor
  sensorValue = analogRead(sensor);
  
  // Se o valor estiver abaixo de um determinado "limite de disparo", então o LED liga, caso contrário o LED permanece desligado
  
  if (sensorValue < limiteDisparo) {
      if (brightness < 245) {
        brightness = brightness + fadeAmount;
      }
  }
  else {
    if (brightness > 5) {
        brightness = brightness - fadeAmount;
      }
  }
  
  // Imprime as leituras atuais no monitor serial da IDE do Arduino
  Serial.print ("Leitura atual do led: ");
  Serial.println(brightness);
  Serial.print ("Leitura atual do sensor: ");
  Serial.println(sensorValue);
  delay(130);
}
