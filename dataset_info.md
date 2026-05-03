# 📊 Dataset Information

## Overview

| Property | Value |
|---|---|
| Platform | Edge Impulse |
| Total Data | 2h 36m 25s |
| Training Samples | 3,640 |
| Test Samples | 889 |
| Train/Test Split | 81% / 19% |
| Training Windows | 13,534 |
| Sample Rate | 8000 Hz |
| Window Size | 1000ms |
| Window Stride | 500ms |

---

## Sound Classes

| Class | Description | Source |
|---|---|---|
| `baby_cry` | Infant crying sounds | Recorded via sensor + Kaggle |
| `ambulance` | Emergency siren sounds | YouTube + sensor recording |
| `dog_barking` | Dog bark sounds | Kaggle Generic Audio Dataset |

---

## Data Collection Method

### Method 1 — Internet Datasets
- **Kaggle:** Generic Audio Samples dataset
- **Freesound.org:** Various sound effects
- **YouTube:** Sound effect videos

### Method 2 — Hardware Recording ⭐
- **Device:** ESP8266 NodeMCU + Sound Sensor
- **Tool:** Edge Impulse Data Forwarder
- **Frequency:** 8000 Hz
- **Sample Length:** 5000ms each

---

## Data Forwarder Setup

```bash
edge-impulse-data-forwarder \
  --frequency 8000 \
  --port /dev/ttyUSB0 \
  --baud-rate 115200
```

---

## Feature Extraction — MFCC

| Parameter | Value |
|---|---|
| Number of coefficients | 13 |
| Frame length | 0.02 |
| Frame stride | 0.02 |
| Filter number | 32 |
| FFT length | 256 |
| Pre-emphasis coefficient | 0.98 |

---

## Notes

- All audio converted to WAV format (16kHz mono) before upload
- Background noise samples important for reducing false positives
- Real hardware recordings give better real-world accuracy than internet datasets
