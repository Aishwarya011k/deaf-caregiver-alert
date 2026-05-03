#  Deaf Caregiver Alert

A wearable smart ring that alerts deaf mothers and caregivers about emergency sounds like baby crying, ambulance sirens, and dog barking — using vibration patterns and RGB LED color codes.

---

## 🎯 Problem Statement

Deaf mothers and caregivers cannot hear critical sounds like:
- 👶 Baby crying
- 🚑 Ambulance sirens
- 🐕 Dog barking (intruder alert)
- 🔔 Doorbell

This puts both the caregiver and the child at risk.

---

## 💡 Solution

A **Smart Alert Ring** worn on the finger that:
- Detects emergency sounds using a microphone + ML model
- Vibrates in **different patterns** for different sounds
- Changes **LED color** to indicate what sound was detected
- Works **silently and discreetly** like jewelry

---

## 🏗️ System Architecture

```
[Room Unit]                          [Smart Ring]
Microphone + ESP8266          →      nRF52810 (BLE)
Sound detected                →      Vibration motor
ML Classification             →      RGB LED color
        ↓
Edge Impulse ML Model
(baby_cry / ambulance / dog_barking)
```

---

## 🔔 Alert System

| Sound Detected | Vibration Pattern | LED Color |
|---|---|---|
| Baby crying | 3 short pulses | 🔵 Blue |
| Ambulance siren | Fast continuous | 🔴 Red |
| Dog barking | 2 short pulses | 🟢 Green |
| Doorbell | 1 short pulse | 🟡 Yellow |
| Silence | None | Off |

---

## 🛠️ Components

### Room Hub Unit
| Component | Purpose |
|---|---|
| ESP8266 NodeMCU | Main microcontroller |
| Sound Sensor Module | Audio capture |
| Power supply | 5V USB |

### Smart Ring Unit
| Component | Purpose |
|---|---|
| nRF52810 | BLE microcontroller |
| Coin vibration motor (4mm) | Vibration alerts |
| RGB LED (0402 SMD) | Color-coded alerts |
| LIR1220 coin cell | Battery |

---

## 🤖 ML Model

- **Platform:** Edge Impulse
- **Algorithm:** 1D Convolutional Neural Network
- **Feature extraction:** MFCC (Mel Frequency Cepstral Coefficients)
- **Target hardware:** Cortex-M4F 80MHz

### Model Performance
| Metric | Value |
|---|---|
| Accuracy | 90.5% |
| Loss | 0.25 |
| F1 Score | 0.90 |
| ROC AUC | 0.98 |

### Sound Classes
- `baby_cry`
- `ambulance`
- `dog_barking`

---

## 📁 Repository Structure

```
deaf-caregiver-alert-ring/
├── README.md
├── firmware/
│   └── esp8266_sound_sensor/
│       └── sketch.ino
├── ml_model/
│   ├── dataset_info.md
│   └── model_results.md
├── hardware/
│   ├── components_list.md
│   └── circuit_diagram.md
└── docs/
    ├── project_report.md
    └── future_work.md
```

---

## 🚀 Setup Instructions

### 1. Clone Repository
```bash
git clone https://github.com/YOUR_USERNAME/deaf-caregiver-alert-ring.git
cd deaf-caregiver-alert-ring
```

### 2. Flash ESP8266
- Open `firmware/esp8266_sound_sensor/sketch.ino` in Arduino IDE
- Install ESP8266 board support
- Select `NodeMCU 1.0 (ESP-12E Module)`
- Upload code

### 3. Wire Components
```
Sound Sensor VCC → ESP8266 3.3V
Sound Sensor GND → ESP8266 GND
Sound Sensor AO  → ESP8266 A0
```

### 4. Train/Import ML Model
- Import Edge Impulse exported C++ library
- Or retrain using Edge Impulse platform

---

## 📊 Development Roadmap

- [x] Phase 1 — ML Model Training (Edge Impulse)
- [x] Phase 2 — ESP8266 Sound Detection
- [ ] Phase 3 — STM32 Firmware Development
- [ ] Phase 4 — Ring Hardware Design
- [ ] Phase 5 — Bluetooth Communication
- [ ] Phase 6 — PCB Design
- [ ] Phase 7 — 3D Print Ring Body
- [ ] Phase 8 — Final Testing

---

## 👩‍💻 Author

**Aishwarya** — Hardware Engineering Student

---

## 📄 License

MIT License
