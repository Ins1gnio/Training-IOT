#define BLYNK_TEMPLATE_ID             "TMPL64giZ7c0R"
#define BLYNK_TEMPLATE_NAME           "LED ESP32"
#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
#define APP_DEBUG
#include "BlynkEdgent.h"
#define LED_PIN 2  // LED pin on ESP32

BLYNK_WRITE(V0)
{
  int value = param.asInt();

  if (value == 1) {
    digitalWrite(LED_PIN, HIGH);
    Serial.print("value =");
    Serial.println(value);
  } else {
    digitalWrite(LED_PIN, LOW);
    Serial.print("value = ");
    Serial.println(value);
  }
}
void setup()
{
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
  delay(10);
}
