# ⚡ Circuit Diagram

## Room Hub — ESP8266 + Sound Sensor

### Wiring Connections

```
Sound Sensor Module        ESP8266 NodeMCU
┌──────────────┐          ┌──────────────┐
│              │          │              │
│    VCC  ─────┼──────────┼─ 3.3V        │
│    GND  ─────┼──────────┼─ GND         │
│    AO   ─────┼──────────┼─ A0          │
│    DO   ─────┼──────────┼─ D0          │
│              │          │              │
└──────────────┘          └──────────────┘
```

### Pin Description

| Sensor Pin | ESP8266 Pin | Description |
|---|---|---|
| VCC | 3.3V | Power supply |
| GND | GND | Ground |
| AO | A0 | Analog audio output |
| DO | D0 | Digital threshold output |

---

## Smart Ring — nRF52810 Circuit

### Vibration Motor Circuit

```
GPIO Pin ──── Gate (MOSFET 2N7000)
              │
              Drain ──── Vibration Motor ──── 3.3V
              │
              Source ──── GND
```

### RGB LED Circuit

```
nRF52810          RGB LED
GPIO_R ──[100Ω]── Red anode
GPIO_G ──[100Ω]── Green anode  
GPIO_B ──[100Ω]── Blue anode
GND    ─────────── Common cathode
```

### Power Circuit

```
LIR1220 Battery (3.6V)
        │
    ────┴────
    │       │
   3.3V    GND
    │
nRF52810 VDD
```

---

## Communication — ESP8266 to Ring

```
ESP8266 (Room Hub)          nRF52810 (Smart Ring)
┌──────────────┐            ┌──────────────┐
│              │            │              │
│   WiFi/BLE   │ ─────────► │   BLE RX     │
│   TX Alert   │            │              │
│              │            │  Vibration   │
│              │            │  Motor + LED │
└──────────────┘            └──────────────┘
```

---

## Alert Signal Protocol

```
Sound detected → ESP8266 sends BLE signal:
"1" → baby_cry    → Ring: 3 short buzzes + Blue LED
"2" → ambulance   → Ring: Fast continuous + Red LED
"3" → dog_barking → Ring: 2 short buzzes + Green LED
"0" → silence     → Ring: No alert
```

---

## Sensitivity Adjustment

The red sound sensor has a **potentiometer**:
```
Turn clockwise     → Less sensitive
Turn anticlockwise → More sensitive

Correct setting:
→ Green LED stays ON (power)
→ Red LED flickers only on sound ✅
```

---

## Notes

- Always use **3.3V** for ESP8266 (NOT 5V — will damage board!)
- Use a **data USB cable** (not charge-only) for programming
- Keep sensor **away from motor** to avoid electrical interference
- Add **100nF capacitor** across motor terminals to reduce noise
