/* ================================================
   SOS Emergency Alert System
   Platform : Blynk IoT (blynk.cloud)
   Hardware : ESP32
   Virtual Pin: V0 (SOS Button Status)
   ================================================ */

#define BLYNK_TEMPLATE_ID   "TMPLxxxxxxxx"
#define BLYNK_TEMPLATE_NAME "SOS"
#define BLYNK_AUTH_TOKEN    "YourAuthTokenHere"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "YourWiFiSSID";
char pass[] = "YourWiFiPassword";

const int SOS_BUTTON_PIN = 4;    
const int STATUS_LED_PIN = 2;    

int  lastButtonState = LOW;
bool sosActive       = false;

BlynkTimer timer;

void readButton() {
  int currentState = digitalRead(SOS_BUTTON_PIN);

  if (currentState == HIGH && lastButtonState == LOW) {
  
    sosActive = true;
    Blynk.virtualWrite(V0, 1);       
    digitalWrite(STATUS_LED_PIN, HIGH);
    Serial.println("SOS ACTIVATED!");
  }

  if (currentState == LOW && lastButtonState == HIGH) {
  
    sosActive = false;
    Blynk.virtualWrite(V0, 0);        // Sends link
    digitalWrite(STATUS_LED_PIN, LOW);
    Serial.println("SOS cleared.");
  }

  lastButtonState = currentState;
}

void setup() {
  Serial.begin(115200);
  pinMode(SOS_BUTTON_PIN, INPUT);
  pinMode(STATUS_LED_PIN, OUTPUT);
  digitalWrite(STATUS_LED_PIN, LOW);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Poll button every 100 ms
  timer.setInterval(100L, readButton);
  Serial.println("SOS System Ready.");
}

void loop() {
  Blynk.run();
  timer.run();
}
