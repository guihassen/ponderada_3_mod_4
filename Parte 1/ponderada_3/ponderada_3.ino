
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


void avisoBuzzer(int *pinoBuzzer) {
  for (int i = 0; i < 3; i++) {
    digitalWrite(*pinoBuzzer, HIGH);
    delay(200);
    digitalWrite(*pinoBuzzer, LOW);
    delay(300);
  }
}


void setup() {
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(buzzer, OUTPUT);
}


void loop() {
  
  acenderLED(&ledVerde);
  delay(4000);              
  avisoBuzzer(&buzzer);     
  apagarLED(&ledVerde);

  
  acenderLED(&ledAmarelo);
  delay(2000);
  apagarLED(&ledAmarelo);

  
  acenderLED(&ledVermelho);
  delay(6000);
  avisoBuzzer(&buzzer);
  apagarLED(&ledVermelho);
}
