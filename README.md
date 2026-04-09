# SOS Emergency Alert System
### ESP32 + Blynk IoT Platform

A wireless SOS Emergency Alert System that sends a real-time alert to the Blynk cloud dashboard when a physical button is pressed.

---

## 📁 Project Files

| File | Description |
|------|-------------|
| `sos_blynk.ino` | Arduino sketch — upload to ESP32 |
| `SOS_Arduino_Blynk_Project.docx` | Full project documentation |
| `README.md` | This file |

---

## 🛒 Hardware Required

- ESP32 DevKit V1 / WROOM-32
- Push button (momentary, normally open)
- 10 kΩ resistor (pull-down)
- LED + 220 Ω resistor (optional — GPIO2 onboard LED works)
- Breadboard & jumper wires
- Micro-USB cable

---

## ⚡ Circuit Connections

| Component Pin       | ESP32 Pin        | Notes                              |
|---------------------|------------------|------------------------------------|
| Button — signal leg | GPIO4            | Reads HIGH when pressed            |
| Button — power leg  | 3.3V             | 3.3V rail only                     |
| 10 kΩ Resistor      | GPIO4 to GND     | Pull-down resistor                 |
| LED anode (+)       | GPIO2 (onboard)  | Via 220 Ω resistor if external     |
| LED cathode (–)     | GND              | Ground rail                        |
| ESP32 VIN           | Micro-USB Power  | 5V regulated to 3.3V on board      |
| ESP32 GND           | GND rail         | Common ground                      |

---

## 🛠️ Software Setup

### 1. Install Arduino IDE
Download from [arduino.cc](https://www.arduino.cc/en/software)

### 2. Add ESP32 Board Package
In Arduino IDE go to **File > Preferences** and add this URL to Board Manager URLs:
```
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
```
Then go to **Tools > Board > Board Manager**, search `ESP32`, and install.

### 3. Install Blynk Library
Go to **Sketch > Include Library > Manage Libraries**, search `Blynk`, and install by **Volodymyr Shymanskyy**.

---

## ☁️ Blynk Cloud Setup

1. Create a free account at [blynk.cloud](https://blynk.cloud)
2. Create a new Template — Name: `SOS`, Hardware: `ESP32`, Connection: `WiFi`
3. Add a Datastream — Virtual Pin `V0`, Name: `SOS Button Status`, Type: Integer, Min: 0, Max: 1
4. Add an LED widget to the Web Dashboard, linked to `V0`
5. Create a new Device from the template — copy the **Auth Token**

---

## 🔧 Configuration

Open `sos_blynk.ino` and replace these three values before uploading:

```cpp
#define BLYNK_TEMPLATE_ID   "TMPLxxxxxxxx"     // From Blynk Console
#define BLYNK_AUTH_TOKEN    "YourAuthTokenHere" // From Blynk Console
char ssid[] = "YourWiFiSSID";
char pass[] = "YourWiFiPassword";
```

---

## 🚀 Upload

1. Open `sos_blynk.ino` in Arduino IDE
2. Go to **Tools > Board > ESP32 Arduino > ESP32 Dev Module**
3. Select your COM port under **Tools > Port**
4. Click **Upload** — hold the **BOOT** button on ESP32 if upload fails
5. Open **Serial Monitor** at `115200` baud — you should see: `SOS System Ready.`

---

## ✅ How It Works

- Button **pressed** → ESP32 sends `1` to Blynk V0 → Dashboard LED turns **red**
- Button **released** → ESP32 sends `0` to Blynk V0 → Dashboard LED turns **off**

---

## 🐛 Troubleshooting

| Problem | Solution |
|---------|----------|
| Device Inactive on Blynk | Check Auth Token and Wi-Fi credentials in Serial Monitor |
| Upload fails | Hold BOOT button on ESP32 during upload; use data USB cable |
| Button not detected | Check GPIO4 wiring and 10 kΩ pull-down resistor |
| Blynk library not found | Install via Library Manager — search Blynk |
| Widget not updating | Link LED widget to V0; check Blynk message quota |
| ESP32 board not in IDE | Add ESP32 board manager URL in Preferences |

---

## 📄 License

This project is open source and free to use for personal and educational purposes.
