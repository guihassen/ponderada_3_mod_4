# Semáforo com Alerta Sonoro (Buzzer 3s)

## 🎯 Objetivo

Construir um semáforo didático com três LEDs (vermelho, amarelo, verde) e um buzzer
que emite **três bipes** quando faltam **3 segundos** para a próxima mudança de luz.

## ✅ Critérios de Sucesso

- Sequência: Verde → Amarelo → Vermelho → (repete)
- Buzzer: 3 bipes curtos antes de cada troca principal
- Pinos configurados conforme mapeamento abaixo

## 🧰 Materiais (BOM)

| Qtd | Item          | Observações        |
| --- | ------------- | ------------------ |
| 1   | Arduino Uno   |                    |
| 1   | Protoboard    |                    |
| 3   | LED (R, Y, G) |                    |
| 3   | Resistor 220Ω | Um por LED         |
| 1   | Buzzer        | Ativo (ou passivo) |
| 1   | Resistor 10kΩ | Opcional (botão)   |
| —   | Jumpers       | Macho-macho        |

## ⚙️ Mapeamento de Pinos

- LED vermelho → **D8**
- LED amarelo → **D9**
- LED verde → **D7**
- Buzzer → **D11**
- GND comum

## 🔌 Ligações (texto)

```
D8  → LED vermelho (ânodo)
LED vermelho (cátodo) → 220Ω → GND

D9  → LED amarelo (ânodo)
LED amarelo (cátodo) → 220Ω → GND

D7  → LED verde (ânodo)
LED verde (cátodo) → 220Ω → GND

D11 → Buzzer (+)
GND → Buzzer (–)
```

## 🧠 Lógica de Funcionamento

- Estado Verde (4 s) → **faltando 3 s**: buzzer bip x3 → troca
- Estado Amarelo (2 s) → troca
- Estado Vermelho (4 s) → **faltando 3 s**: buzzer bip x3 → troca

Estratégia de código:

- Funções que recebem **ponteiro de pino** (`int*`) para acender/apagar LEDs.
- Função `avisoBuzzer(int* pinoBuzzer)` para 3 bipes curtos.
- Tempos configuráveis em constantes.

## 💻 Código

```cpp
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
  delay(4000);
  avisoBuzzer(&buzzer);
  apagarLED(&ledVermelho);
}
```

## 🧪 Testes

1. **Unitário LED**: cada LED acende isoladamente.
2. **Buzzer**: 3 bipes de ~200 ms com ~300 ms entre eles.
3. **Integrado**: ciclo completo com avisos corretos.
4. **Aceite**: tempos dentro de ±100 ms.
