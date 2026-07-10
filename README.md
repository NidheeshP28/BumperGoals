# ⚽ BumperGoals: Dual-Joystick Custom Tank-Drive Controller & Chassis

An ergonomic, compact, wireless remote control system designed around an upgraded Type-C Arduino Nano. BumperGoals is a tabletop robotic soccer game where two teams of custom-made mini bumper cars face off in a fast-paced 2v2 match to be the first to score 5 goals. 

This repository covers the complete engineering design—including custom ergonomic controller shells, dual-joystick input mapping, custom PCBs, and differential tank-drive chassis firmware.

---

## 🛠️ Hardware Design & Interactive Previews

### 🎮 Custom Controller PCB
Inside the ergonomic case, each controller features parallel-mounted joysticks with uniform bottom-facing pin alignment for twist-free wiring, an integrated power booster to step up standard AA battery voltage safely, a simple power switch, and a wireless chip to talk to the cars.

<p align="center">
  <img src="https://github.com/user-attachments/assets/6e111d4a-f026-431c-82f2-01922a5f8236" alt="Controller" width="45%"/>
  <img src="https://github.com/user-attachments/assets/8dfe6b67-1346-4002-a630-50444e95716e" alt="Board" width="45%"/>
</p>

[![Test Controller on Wokwi W/ PCB](https://img.shields.io/badge/Wokwi-Simulate%20Controller-29b6f6?style=for-the-badge&logo=hardware)](https://wokwi.com/projects/469181826556015617)

### 🏎️ Robot Chassis PCB
The mini bumper car chassis handles differential drive execution through twin N20 DC gearmotors paired with a smooth-rolling front ball caster for seamless turns on the playfield.

<p align="center">
  <img src="https://github.com/user-attachments/assets/3412b70d-9c2a-413e-8262-f3925325845d" alt="Robot" width="45%"/>
  <img src="https://github.com/user-attachments/assets/36c44d2c-2b33-4fdf-9f89-eefc627431bb" alt="MotorAssembly" width="45%"/>
</p>

[![Test Robot Chassis on Wokwi W/ PCb](https://img.shields.io/badge/Wokwi-Simulate%20Robot%20Chassis-29b6f6?style=for-the-badge&logo=hardware)](https://wokwi.com/projects/469191659636854785)

---

## 🔌 Hardware Pin Configuration

To maintain clean, un-crossed wire paths inside the controller shell, the joysticks are mounted vertically with pins facing downward. The pinouts map directly to the Arduino Nano as follows:

| Component | Joystick Pin | Arduino Nano Pin | Function |
| :--- | :--- | :--- | :--- |
| **Left Joystick** | HORZ (X-Axis) | `A0` | Forward / Backward Control |
| **Left Joystick** | VERT (Y-Axis) | `A1` | Unused |
| **Right Joystick** | HORZ (X-Axis) | `A2` | Unused |
| **Right Joystick** | VERT (Y-Axis) | `A3` | Turn Right / Turn Left Control |
| **Power Bus** | VCC | `5V` | Shared 5V Logic Rail |
| **Ground Bus** | GND | `GND` | Shared Common Ground |

---

## 🕹️ Movement Logic Matrix

Because the left and right DC gearmotors are physically mirrored on opposite sides of the chassis, their directional rotations are configured to execute the following differential steering maneuvers flawlessly:

* **Forward:** Left Joystick pushed **Up** $\rightarrow$ Left Motor: **CW** (Clockwise) | Right Motor: **CCW** (Counter-Clockwise)
* **Backward:** Left Joystick pulled **Down** $\rightarrow$ Left Motor: **CCW** | Right Motor: **CW**
* **Turn Right:** Right Joystick pushed **Right** $\rightarrow$ Left Motor: **CW** | Right Motor: **CW**
* **Turn Left:** Right Joystick pulled **Left** $\rightarrow$ Left Motor: **CCW** | Right Motor: **CCW**
* **Coast / Idle:** Joysticks inside the center deadzone (450 to 570) $\rightarrow$ Both Motors: **OFF**

---

## 📂 Repository Structure
* `/software` : Contains the Wokwi simulation testing sketches and stable core logic files.
* `/pcb` : Contains KiCad schematic diagrams, custom routing layers, and manufacturing files.
