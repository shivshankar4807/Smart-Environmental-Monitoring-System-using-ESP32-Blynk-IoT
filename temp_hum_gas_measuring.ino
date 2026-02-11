#define BLYNK_TEMPLATE_ID "TMPL3Ym64Hki_"
#define BLYNK_TEMPLATE_NAME "gas detect"
#define BLYNK_AUTH_TOKEN "jSKvkvpIBzUYxo3RgZUBfTRNCY7tpg-S"


#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

char ssid[] = "Shivshankar";
char pass[] = "password";

#define DHTPIN 4
#define DHTTYPE DHT11
#define MQ2_PIN 34

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

void sendData() {

  float temp = dht.readTemperature();
  float hum  = dht.readHumidity();
  int gasRaw = analogRead(MQ2_PIN);

  if (isnan(temp) || isnan(hum)) {
    Serial.println("DHT Error!");
    return;
  }

  // Convert raw value to approximate ppm
  int gasPPM = map(gasRaw, 0, 4095, 0, 10000);

  // Approximate different gases
  int lpg       = gasPPM * 0.6;
  int methane   = gasPPM * 0.8;
  int hydrogen  = gasPPM * 0.5;
  int smoke     = gasPPM;

  // Send to Blynk
  Blynk.virtualWrite(V0, temp);
  Blynk.virtualWrite(V1, hum);
  Blynk.virtualWrite(V2, lpg);
  Blynk.virtualWrite(V3, methane);
  Blynk.virtualWrite(V4, hydrogen);
  Blynk.virtualWrite(V5, smoke);

  Serial.println("Data Sent to Blynk");
}

void setup() {
  Serial.begin(9600);
  dht.begin();

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  timer.setInterval(2000L, sendData);
}

void loop() {
  Blynk.run();
  timer.run();
}
