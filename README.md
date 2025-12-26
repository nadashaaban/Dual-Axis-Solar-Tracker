# Dual-Axis Solar Tracker

An Arduino-based dual-axis solar tracking system that maximizes solar panel efficiency by continuously orienting the panel perpendicular to the sun's rays throughout the day.

## 📋 Overview

This project implements a smart solar tracking system using light-dependent resistors (LDRs) and DC motors to track the sun's position in both horizontal and vertical axes. The system can operate in both automatic and manual modes, significantly improving solar energy collection compared to fixed solar panels.

## ✨ Features

- **Dual-Axis Tracking**: Tracks sun movement in both horizontal and vertical axes
- **Automatic Mode**: Uses LDR sensors to detect light intensity and automatically adjust panel position
- **Manual Mode**: Allows user control of panel positioning via manual input
- **Real-Time Adjustment**: Continuously optimizes panel angle for maximum solar exposure
- **Energy Efficiency**: Increases solar energy capture by up to 30-40% compared to fixed panels

## 🛠️ Hardware Components

- Arduino microcontroller
- 2x DC motors (for horizontal and vertical movement)
- Motor driver
- 4x Light Dependent Resistors (LDRs)
- Mounting frame and mechanical structure
- IR remote
- Power supply
- Resistors and wiring

## 📁 Project Structure
```
Dual-Axis-Solar-Tracker/
├── automatic.final.ino    # Automatic tracking mode implementation
└── manual.final.ino       # Manual control mode implementation
```

## 🚀 How It Works

### Automatic Mode
1. Four LDR sensors positioned at corners of the solar panel detect light intensity
2. Arduino compares readings from opposite sensors (top vs. bottom, left vs. right)
3. DC motors adjust panel position to balance light readings across all sensors
4. System continuously tracks sun position for optimal energy capture

### Manual Mode
Allows direct control of motor positions through IR remote for:
- Testing and calibration
- Manual positioning during maintenance
- Custom positioning scenarios

## 💻 Installation & Usage

1. **Hardware Setup**:
   - Connect DC motors to Arduino PWM pins
   - Wire LDR sensors to analog input pins
   - Attach motors to mechanical mounting structure

2. **Upload Code**:
```bash
   # For automatic mode
   Upload automatic.final.ino to Arduino

   # For manual mode
   Upload manual.final.ino to Arduino
```

3. **Calibration**:
   - Adjust LDR threshold values based on ambient light conditions
   - Test full range of motion in both axes

## 🔧 Circuit Configuration

**LDR Sensors:**
- Top-Left LDR → A0
- Top-Right LDR → A1
- Bottom-Left LDR → A2
- Bottom-Right LDR → A3

**DC Motors:**
- Horizontal Motor → Pin 9
- Vertical Motor → Pin 10

*(Adjust pin configurations in code as needed)*

---

*Part of my coursework projects in the Electrical Engineering Department.*
