//Projeto de Circuitos Eletrônicos - IoT
//Sensor de temperatura, uma buzina, um LED e um motor,controlados por meio de um Arduino. 
//O projeto deve seguir a seguinte funcionalidade:

//(a) Fazer a leitura da temperatura;
//(b) Fazer o acionamento de um motor de ventilador caso a temperatura seja igual ou maior a 30 °C;
//(c) Caso a temperatura ultrapasse os 50 °C, um LED vermelho e uma buzina devem acionar avisando uma situação de emergência. 

// Definição dos pinos
const int pinoSensor = A0;
const int pinoLed = 13;
const int pinoBuzzer = 12;
const int pinoMotor = 11;

void setup() {
  pinMode(pinoLed, OUTPUT);
  pinMode(pinoBuzzer, OUTPUT);
  pinMode(pinoMotor, OUTPUT);
  
  Serial.begin(9600); // Para monitorar a temperatura no monitor serial
}

void loop() {
  
  //(a) Fazer a leitura da temperatura;
  
  // Leitura do sensor (fórmula para TMP36: voltagem -> graus Celsius)
  int leitura = analogRead(pinoSensor);
  float voltagem = leitura * (5.0 / 1023.0);
  float temperatura = (voltagem - 0.5) * 100;

  Serial.print("Temperatura: ");
  Serial.println(temperatura);

  // Lógica de controle:
  
  // (b) Acionamento do motor se temperatura >= 30 °C
  if (temperatura >= 30.0) {
    digitalWrite(pinoMotor, HIGH);
  } else {
    digitalWrite(pinoMotor, LOW);
  }

  // (c) Emergência se temperatura > 50 °C
  if (temperatura > 50.0) {
    digitalWrite(pinoLed, HIGH);
    tone(pinoBuzzer, 1000); // Emite som de 1000Hz
  } else {
    digitalWrite(pinoLed, LOW);
    noTone(pinoBuzzer);     // Para o som
  }

  delay(500); // Pequena pausa para estabilidade da leitura
}