
int ledVermelho = 8;
int ledAmarelo  = 9;
int ledVerde    = 7;   
int buzzer      = 11;  


void acenderLED(int *pino) {
  digitalWrite(*pino, HIGH);
}

void apagarLED(int *pino) {
  digitalWrite(*pino, LOW);
}

//Inicializa o Ponteiro 
void avisoBuzzer(int *pinoBuzzer) {
  for (int i = 0; i < 3; i++) {
    digitalWrite(*pinoBuzzer, HIGH);
    delay(200);
    digitalWrite(*pinoBuzzer, LOW);
    delay(300);
  }
}


void setup() {
  pinMode(ledVermelho, OUTPUT); // Define a porta como Output
  pinMode(ledAmarelo, OUTPUT); // Define a porta como Output
  pinMode(ledVerde, OUTPUT); // Define a porta como Output
  pinMode(buzzer, OUTPUT); // Define a porta como Output
}


void loop() {
  
  acenderLED(&ledVerde); // acende o LED Verde
  delay(4000); // Delay de 4s             
  avisoBuzzer(&buzzer);   // Bipa o Buzzer
  apagarLED(&ledVerde); // Apaga o LED 

  
  acenderLED(&ledAmarelo); // Acende o LED Amarelo
  delay(2000); // Delay de 2s
  apagarLED(&ledAmarelo); // Apaga o LED Amarelo

  
  acenderLED(&ledVermelho); // Acende o LED Vermelho
  delay(6000); // Delay 6s
  avisoBuzzer(&buzzer); // Bipa o Buzzer
  apagarLED(&ledVermelho);// Apagar o LED Vermelho
}
