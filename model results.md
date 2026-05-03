# 🤖 ML Model Results

## Platform
**Edge Impulse** — studio.edgeimpulse.com
**Project:** deaf-caregiver-alert

---

## Model Architecture

```
Input Layer (650 features)
        ↓
Reshape Layer (13 columns)
        ↓
1D Conv Layer (8 filters, kernel size 3)
        ↓
Dropout (0.25)
        ↓
1D Conv Layer (16 filters, kernel size 3)
        ↓
Dropout (0.25)
        ↓
Flatten Layer
        ↓
Output Layer (3 classes)
```

---

## Training Settings

| Parameter | Value |
|---|---|
| Training cycles | 100 |
| Learning rate | 0.005 |
| Validation size | 20% |
| Batch size | 32 |
| Data augmentation | Enabled |
| Add noise | High |
| Mask time bands | Low |

---

## Performance Results

### Overall Metrics
| Metric | Value |
|---|---|
| **Accuracy** | **90.5%** |
| **Loss** | **0.25** |
| ROC AUC | 0.98 |
| Weighted Precision | 0.91 |
| Weighted Recall | 0.90 |
| Weighted F1 Score | 0.90 |

---

## Confusion Matrix

| | ambulance | baby_cry | dog_barking |
|---|---|---|---|
| **ambulance** | 87.6% | 8.2% | 4.2% |
| **baby_cry** | 2.3% | 95.6% | 2.1% |
| **dog_barking** | 4.4% | 11.4% | 84.1% |

### F1 Scores
| Class | F1 Score |
|---|---|
| ambulance | 0.87 |
| baby_cry | 0.93 |
| dog_barking | 0.89 |

---

## On-Device Performance (Cortex-M4F 80MHz)

| Metric | Value |
|---|---|
| Processing time | 154 ms |
| Peak RAM usage | 15 KB |
| Flash usage | 22% |

---

## Model Versions

| Version | Accuracy | Notes |
|---|---|---|
| v1 | 90.5% | Internet dataset only |
| v2 | 88.4% | With augmentation (150 cycles) |
| v3 | 90.5% | Hardware sensor data added |

---

## Key Observations

- **baby_cry** has highest accuracy (95.6%) ✅
- **ambulance** sometimes confused with baby_cry (8.2%)
- **dog_barking** needs more training data
- Adding real hardware sensor data improved generalization

---

## How to Retrain

1. Go to [Edge Impulse Studio](https://studio.edgeimpulse.com)
2. Import project `deaf-caregiver-alert`
3. Go to **Classifier** → adjust settings
4. Click **Save & train**
5. Export as C++ library for STM32
