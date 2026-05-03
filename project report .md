# 📝 Project Report

## Deaf Caregiver Alert Smart Ring

**Student:** Aishwarya
**Date:** May 2026
**Domain:** Embedded Systems + Machine Learning

---

## 1. Introduction

Hearing impairment affects millions of people worldwide. Deaf mothers and caregivers face unique challenges — they cannot hear critical sounds that signal danger or need for attention. This project addresses this gap by creating a **Smart Alert Ring** that detects emergency sounds and notifies the wearer through vibration and visual LED alerts.

---

## 2. Problem Statement

Deaf caregivers miss critical audio alerts including:
- Baby crying (infant distress)
- Ambulance sirens (emergency awareness)
- Smoke alarms (fire safety)
- Doorbells (visitor awareness)
- Dog barking (security alerts)

Existing solutions like flashing lights require line-of-sight and are not always practical.

---

## 3. Proposed Solution

A **two-unit wearable system:**

### Unit 1 — Room Hub
- Placed in the baby's room
- Continuously monitors audio
- Runs ML model for sound classification
- Sends alerts wirelessly

### Unit 2 — Smart Ring
- Worn on the caregiver's finger
- Receives wireless alerts
- Vibrates in unique patterns
- RGB LED changes color per alert type

---

## 4. Technology Stack

| Layer | Technology |
|---|---|
| ML Training | Edge Impulse |
| Feature Extraction | MFCC |
| ML Model | 1D CNN |
| Room Hub MCU | ESP8266 / STM32 |
| Ring MCU | nRF52810 |
| Communication | Bluetooth Low Energy |
| Development OS | Ubuntu 24 |
| Firmware IDE | Arduino IDE + STM32CubeIDE |

---

## 5. ML Model Development

### 5.1 Data Collection
- Collected audio data using ESP8266 + sound sensor
- Used Edge Impulse Data Forwarder for real-time capture
- Supplemented with Kaggle and Freesound.org datasets
- Total dataset: 2h 36m 25s of audio

### 5.2 Feature Extraction
Used **MFCC (Mel Frequency Cepstral Coefficients):**
- Mimics human ear frequency perception
- Extracts 13 key coefficients per audio frame
- Converts raw audio into ML-readable fingerprints

### 5.3 Model Architecture
1D Convolutional Neural Network:
```
Input (650 features) → Reshape → Conv1D(8) → 
Dropout → Conv1D(16) → Dropout → Flatten → 
Output (3 classes)
```

### 5.4 Results
| Metric | Value |
|---|---|
| Accuracy | 90.5% |
| Loss | 0.25 |
| F1 Score | 0.90 |
| ROC AUC | 0.98 |

---

## 6. Hardware Implementation

### 6.1 Sound Detection
- ESP8266 NodeMCU reads analog values from sound sensor
- Values forwarded to Edge Impulse for training
- Threshold-based detection implemented as fallback

### 6.2 Alert System
Different vibration patterns per sound class:
- Baby cry → 3 short pulses
- Ambulance → fast continuous buzz
- Dog bark → 2 short pulses

### 6.3 Ring Design
- Miniaturized electronics in ring form factor
- Coin cell battery for power
- Resin cast for waterproofing
- Looks like fashionable jewelry

---

## 7. Challenges Faced

| Challenge | Solution |
|---|---|
| Basic sensor not suitable for ML | Used data forwarder with analog values |
| MPEG files not accepted by Edge Impulse | Converted to WAV using FFmpeg |
| USB port not detected | Fixed with dialout group permissions |
| Low accuracy with internet data | Collected real hardware sensor data |
| Image axis selected instead of audio | Fixed impulse configuration |

---

## 8. Results Summary

- ML model trained with **90.5% accuracy**
- Real-time sound detection working on ESP8266
- Data collection pipeline established
- Hardware prototype in progress

---

## 9. Future Work

- Integrate INMP441 MEMS microphone for better audio quality
- Deploy ML model on STM32 hardware
- Design custom circular PCB for ring
- Add more sound classes (smoke alarm, doorbell)
- Implement BLE communication between units
- Waterproof the ring using resin casting
- Clinical testing with deaf caregivers

---

## 10. References

1. Edge Impulse Documentation — docs.edgeimpulse.com
2. ESP8266 NodeMCU Documentation
3. Kaggle Generic Audio Samples Dataset
4. MFCC Feature Extraction — Speech Processing Literature
5. nRF52810 Product Specification — Nordic Semiconductor
