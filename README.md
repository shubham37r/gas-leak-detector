# Gas Leak Detector — Arduino UNO

A simple IoT gas leakage detection system built on Arduino UNO. It continuously
monitors gas concentration using an analog gas sensor and triggers an LED +
buzzer alert when levels exceed a safe threshold.

## Features
- Real-time gas level monitoring via analog sensor (e.g. MQ-2)
- Visual alert (LED) on gas leak detection
- Audible alert using a passive buzzer (`tone()` / `noTone()`)
- Live readings and status logged to Serial Monitor for debugging/calibration

## Hardware Required
- Arduino UNO
- MQ-2 (or similar) gas sensor
- LED
- Passive buzzer
- Breadboard + jumper wires
- Resistor for LED (~220Ω)

## Circuit / Pin Configuration

| Component     | Arduino Pin |
|----------------|------------|
| Gas Sensor (AOUT) | A0     |
| LED            | D2         |
| Buzzer         | D4         |

## How It Works
1. The sensor's analog output is read on `A0`.
2. If the reading is `>= MAX` (default threshold: `150`), the LED turns on
   and the buzzer sounds a 1000 Hz tone, while `"GAS LEAKING"` is printed to
   Serial Monitor.
3. Otherwise, the LED and buzzer stay off and `"NORMAL"` is printed.

> **Note:** The `MAX` threshold (150) works for the sensor/environment this
> was tested on. Recalibrate it for your own sensor by watching raw values
> in the Serial Monitor (baseline clean air vs. gas exposure) before
> deploying.

## Getting Started
1. Wire the circuit as per the pin table above.
2. Open `gas_leak_detector.ino` in the Arduino IDE.
3. Select **Board: Arduino UNO** and the correct COM port.
4. Upload the sketch.
5. Open Serial Monitor (9600 baud) to view live readings.

## Future Improvements
- Add a buzzer mute/reset button
- Send alerts over WiFi/GSM (e.g. via ESP8266 or SIM800L) for remote notification
- Log readings to an app/dashboard for historical tracking
- Add multi-level thresholds (warning vs. critical)
