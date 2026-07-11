# BumperGoals: Miniature Soccer W/ Robots

For my BumperGoals project, I built a mini robotic soccer game where two teams of two have a mini bumper cars face off to be the first to score five goals. To control the cars, I designed custom controllers that feature built-in screw holes, clean cutouts for the joysticks, and a top shell that snaps tightly onto the bottom plate. Inside the case, each of the controllers uses a tiny computer chip, a power booster on AA batteries, a simple power switch, and a wireless chip to connect to the robots. By uploading code using a plug-in hardware programmer, I created a completely wireless, arcade game from scratch.

---

## Hardware Designs

### Custom Controller
Inside the controller case, it includes joysticks with perfect alignment for wiring, a power booster on AA batteries, a simple power switch, and a wireless chip to connect to the robots.

<p align="center">
  <img src="https://github.com/user-attachments/assets/6e111d4a-f026-431c-82f2-01922a5f8236" alt="Controller" width="45%"/>
  <img src="https://github.com/user-attachments/assets/8dfe6b67-1346-4002-a630-50444e95716e" alt="Board" width="45%"/>
  <img src="https://github.com/user-attachments/assets/1449ca8d-4543-44e1-b951-49d8e8b0467a" alt="ControllerPCB" width="45%"/>
</p>

The PCB is an Arduino Nano 3.0 ATmega328P Controller Board which when connected to our joysticks, it will help it guide the robot to move. The button below shows how the system identifies on which direction to go.

[![Test Controller on Wokwi W/ PCB](https://img.shields.io/badge/Wokwi-Simulate%20Controller-29b6f6?style=for-the-badge&logo=hardware)](https://wokwi.com/projects/469181826556015617)

### Robot Chassis
The mini bumper car chassis handles differential drive through twin N20 DC gearmotors paired with a front ball caster for easier 360 degree turns on the soccer field.

<p align="center">
  <img src="https://github.com/user-attachments/assets/3412b70d-9c2a-413e-8262-f3925325845d" alt="Robot" width="45%"/>
  <img src="https://github.com/user-attachments/assets/36c44d2c-2b33-4fdf-9f89-eefc627431bb" alt="MotorAssembly" width="45%"/>
  <img src="https://github.com/user-attachments/assets/dfe23223-3fb8-4bad-897c-af17101e789a" alt="ControllerPCB" width="45%"/>
</p>

The PCB is an Arduino Nano 3.0 ATmega328P Controller Board which when connected to our motors (in this scenario the LEDs), it will help it guide the robot for rotation purposes. The button below shows how the system identifies on how the the direction of the motors can dicide on which direction to go.

[![Test Robot Chassis on Wokwi W/ PCb](https://img.shields.io/badge/Wokwi-Simulate%20Robot%20Chassis-29b6f6?style=for-the-badge&logo=hardware)](https://wokwi.com/projects/469191659636854785)

---

## Step-by-Step Assembly Guide

Building a complete Bumper Goals game involves assembling two parts: the custom handheld controller and the mini bumper car chassis. Make sure to have all the materials provided in the BOM:

<p align="center">
  <img src="https://github.com/user-attachments/assets/6bc7d630-b52d-4764-80ab-f9f365077de4" alt="BOM" width="45%"/>
</p>

### 1. Assembling the Controller
1. **Prepare the PCB:** First have the Arduino Nano PCB, then solder the microchip, power booster, wireless module, and power switch into their designated slots.
2. **Mount the Joysticks:** Insert both joysticks into the front of the PCB. Make sure they are aligned vertically with their pins facing downward to match the clean wiring paths, then solder them securely.
3. **Fit into the Lower Shell:** Place the AA battery holder into the bottom plate of your custom 3D-printed enclosure, wth the wiring to the switch and PCB. Secure the PCB onto the built-in screw pillars.
4. **Finish the Controller:** Carefully align the top shell cutout over the joysticks. Snap the top shell onto the bottom plate tightly and secure the corners using small assembly screws.

Make sure the controller looks like this:

<p align="center">
  <img src="https://github.com/user-attachments/assets/e92caf04-0704-4593-828b-914f8709e23f" alt="ControllerAssembly"/>
</p>

### 2. Assembling the Robot Chassis
1. **Solder the Drive Board:** Solder your Arduino Nano, motor driver, and wireless receiver module onto the main Robot Chassis.
2. **Mount the Motors:** Take your twin N20 DC gearmotors and slide them into their designated mounts underneath the chassis. Solder their power leads directly to the motor driver output pins.
3. **Add Wheels and Caster:** Press the rubber wheels onto the extended D-shafts of the N20 motors. Bolt ball caster to the front of the chassis to complete stabilization.
4. **Connect Power:** Install the battery pack, secure all loose wires, and clear the wheels for spin-testing.

Make sure the robot looks like this:

<p align="center">
  <img src="https://github.com/user-attachments/assets/f5f2a981-fcd7-477a-8653-5d36e2958d97" alt="FrontView" width="45%"/>
  <img src="https://github.com/user-attachments/assets/c71a48d7-d86e-4a05-904f-240aae1eeb49" alt="SideView" width="45%"/>
  <img src="https://github.com/user-attachments/assets/9bdd764b-6a84-427a-8c99-11106067c676" alt="BottomView" width="45%"/>
</p>

---

## 🔌 Hardware Pin Configuration

To maintain clean, wire paths inside the controller shell, the joysticks are mounted vertically with pins facing downward. The purpose of this is to show how on the left joystick you can only go foward and backward, while on the right joystick you can only rotate left and right. The pinouts map directly to the Arduino Nano as follows:

| Component | Joystick Pin | Arduino Nano Pin | Function |
| :--- | :--- | :--- | :--- |
| **Left Joystick** | HORZ (X-Axis) | `A0` | Forward / Backward Control |
| **Left Joystick** | VERT (Y-Axis) | `A1` | Unused |
| **Right Joystick** | HORZ (X-Axis) | `A2` | Unused |
| **Right Joystick** | VERT (Y-Axis) | `A3` | Turn Right / Turn Left Control |
| **Power Bus** | VCC | `5V` | Shared 5V Logic Rail |
| **Ground Bus** | GND | `GND` | Shared Common Ground |

[![Test Controller on Wokwi W/ PCB](https://img.shields.io/badge/Wokwi-Simulate%20Controller-29b6f6?style=for-the-badge&logo=hardware)](https://wokwi.com/projects/469181826556015617)

---

## 🕹️ Movement Logic Matrix

Because the left and right DC gearmotors are physically mirrored on opposite sides of the chassis, their directional rotations are configured to execute the following differential steering maneuvers flawlessly:

* **Forward:** Left Joystick pushed **Up** $\rightarrow$ Left Motor: **CW** (Clockwise) | Right Motor: **CCW** (Counter-Clockwise)
* **Backward:** Left Joystick pulled **Down** $\rightarrow$ Left Motor: **CCW** | Right Motor: **CW**
* **Turn Right:** Right Joystick pushed **Right** $\rightarrow$ Left Motor: **CW** | Right Motor: **CW**
* **Turn Left:** Right Joystick pulled **Left** $\rightarrow$ Left Motor: **CCW** | Right Motor: **CCW**
* **Coast / Idle:** Joysticks inside the center deadzone (450 to 570) $\rightarrow$ Both Motors: **OFF**

<p align="center">
  <img src="https://github.com/user-attachments/assets/123185df-f556-4580-a39d-8e83444ce98d" alt="WheelAssembly" width="45%"/>
</p>

[![Test Robot Chassis on Wokwi W/ PCb](https://img.shields.io/badge/Wokwi-Simulate%20Robot%20Chassis-29b6f6?style=for-the-badge&logo=hardware)](https://wokwi.com/projects/469191659636854785)

---

## Repository Structure
graph TD
    A[Root] --> B[Child 1]
    A --> C[Child 2]
    B --> D[Grandchild 1]
    C --> E[Grandchild 2]
