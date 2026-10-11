#include <Arduino.h>

#define buzzerPin 5   // зуммер на D5
#define photoPin A3   // фоторезистор на A3

void buzz(int targetPin, long frequency, long length);

int aVal;
int sMax = 1023;      // макс. значение АЦП (10 бит)
long buzzerFreq;
const long BUZZ_FREQ_MAX = 2500;

void setup() {
    pinMode(buzzerPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    // aVal = analogRead(photoPin);
    // Serial.print("aVal: ");
    // Serial.println(aVal);
    // buzzerFreq = (aVal * BUZZ_FREQ_MAX) / sMax;  // частота пропорциональна освещённости
    // buzz(buzzerPin, buzzerFreq, 10);
}

void buzz(int targetPin, long frequency, long length) {
    long delayValue = 1000000 / frequency / 2;   // полуволна в микросекундах
    long numCycles = frequency * length / 1000;
    for (long i = 0; i < numCycles; i++) {
        digitalWrite(targetPin, HIGH);
        delayMicroseconds(delayValue);
        digitalWrite(targetPin, LOW);
        delayMicroseconds(delayValue);
    }
}