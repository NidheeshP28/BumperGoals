# BumperGoals

I built a mini soccer game where two teams of two have a mini bumper cars face off to be the first to score five goals. To control the cars, I designed controllers that includes joysticks, a power converter, a tranceiver, AA batteries, a simple power switch, and a PCB to connect to the robots. The bumper car handles differential drive with 2 N20 DC gearmotors paired with a ball caster for easier 360 degree turns on the soccer field. By uploading code using a hardware programmer, I created a wireless, arcade game from scratch.

---

## Hardware

### Controller

To control the cars, I designed controllers that includes joysticks, a power converter, a tranceiver, AA batteries, a simple power switch, and a PCB to connect to the robots.

<p align="center">
  <img src="https://github.com/user-attachments/assets/6e111d4a-f026-431c-82f2-01922a5f8236" alt="Controller" width="45%"/>
  <img src="https://github.com/user-attachments/assets/8dfe6b67-1346-4002-a630-50444e95716e" alt="Board" width="45%"/>
  <img src="https://github.com/user-attachments/assets/1449ca8d-4543-44e1-b951-49d8e8b0467a" alt="ControllerPCB" width="45%"/>
</p>

The PCB is an Arduino Nano PCB which when connected to our joysticks, it helps it guide the robot to move. 

The button below shows how the system identifies on which direction to go:

[![Test Controller on Wokwi W/ PCB](https://img.shields.io/badge/Wokwi-Simulate%20Controller-29b6f6?style=for-the-badge&logo=hardware)](https://wokwi.com/projects/469181826556015617)

### Robot Chassis

The bumper car handles differential drive with 2 N20 DC gearmotors paired with a ball caster for easier 360 degree turns on the soccer field.

<p align="center">
  <img src="https://github.com/user-attachments/assets/3412b70d-9c2a-413e-8262-f3925325845d" alt="Robot" width="45%"/>
  <img src="https://github.com/user-attachments/assets/36c44d2c-2b33-4fdf-9f89-eefc627431bb" alt="MotorAssembly" width="45%"/>
  <img src="https://github.com/user-attachments/assets/dfe23223-3fb8-4bad-897c-af17101e789a" alt="ControllerPCB" width="45%"/>
</p>

The PCB is an Arduino Nano PCB which when connected to our motors (in this scenario the LEDs), it will help it guide the robot for rotation purposes. 

The button below shows how the system identifies on how the the direction of the motors can dicide on which direction to go:

[![Test Robot on Wokwi W/ PCB](https://img.shields.io/badge/Wokwi-Simulate%20Robot%20Chassis-29b6f6?style=for-the-badge&logo=hardware)](https://wokwi.com/projects/469191659636854785)

---

## Step-by-Step Assembly Guide

Building a complete Bumper Goals game involves assembling two parts: the controller and the bumper car. 

Make sure to have all the materials provided in the BOM (You can also see it in BOM2.csv):

<p align="center">
  <img src="https://github.com/user-attachments/assets/6bc7d630-b52d-4764-80ab-f9f365077de4" alt="BOM" width="45%"/>
</p>

### 1. Assembling the Controller
1. **Prepare the PCB:** First have your Arduino Nano PCB, then solder the PCB, AA Battery Holder, Tranceiver, Power Converter, and power switch into their designated slots.
2. **Mount the Joysticks:** Insert both joysticks into the front of the PCB. Make sure they are aligned vertically with their pins facing downward to match the clean wiring paths, then solder them securely.
3. **Fit into the Lower Shell:** Place the AA battery holder into the bottom plate of the controller, with the wiring to the switch and PCB. Secure the PCB beside the screw pillars.
4. **Finish the Controller:** Carefully align the top shell cutout over the joysticks. Snap the top shell onto the bottom plate tightly and secure the corners using screws.

Make sure the controller and wiring looks like this:

<p align="center">
  <img src="https://github.com/user-attachments/assets/e92caf04-0704-4593-828b-914f8709e23f" alt="ControllerAssembly" width="45%"/>
  <img src="https://github.com/user-attachments/assets/79c80fe1-e712-4c5f-9f6f-9d2dec58a955" alt="Wiring" width="45%"/>
</p>

### 2. Assembling the Robot Chassis
1. **Solder the PCB:** Solder your Arduino Nano, motor driver, and wireless receiver module onto the main Robot Chassis.
2. **Add motors:** Take your 2 N20 DC gearmotors and slide them onto mounts underneath the robot. Solder the wiring to the motor driver output pins.
3. **Add Wheels and Caster:** Add wheels onto the extended D-shafts of the N20 motors. Bolt ball caster to the front of the robot to complete drivebase.
4. **Finish Wiring:** Install the battery pack, secure all loose wires, and clear the wheels.

Make sure the robot look like this:

<p align="center">
  <img src="https://github.com/user-attachments/assets/f5f2a981-fcd7-477a-8653-5d36e2958d97" alt="FrontView" width="45%"/>
  <img src="https://github.com/user-attachments/assets/c71a48d7-d86e-4a05-904f-240aae1eeb49" alt="SideView" width="45%"/>
  <img src="https://github.com/user-attachments/assets/9bdd764b-6a84-427a-8c99-11106067c676" alt="BottomView" width="45%"/>
</p>

---

## Hardware Connection

To maintain wire paths inside the controller, the joysticks are mounted vertically with pins facing downward. The purpose of this is to show how on the left joystick you can only go foward and backward, while on the right joystick you can only rotate left and right. The pinouts map directly to the Arduino Nano as follows:

| Component | Joystick | Arduino Nano | Function |
| :--- | :--- | :--- | :--- |
| **Left Joystick** | HORZ | `A0` | Forward / Backward |
| **Left Joystick** | VERT | `A1` | Unused |
| **Right Joystick** | HORZ | `A2` | Unused |
| **Right Joystick** | VERT | `A3` | Right / Left |
| **Power Bus** | VCC | `5V` | 5V Power Converter |
| **Ground Bus** | GND | `GND` | Shared Common Ground |

[![Test Controller on Wokwi W/ PCB](https://img.shields.io/badge/Wokwi-Simulate%20Controller-29b6f6?style=for-the-badge&logo=hardware)](https://wokwi.com/projects/469181826556015617)

---

## Movement Understanding

Because the left and right DC gearmotors are physically mirrored on opposite sides of the drivebase, their rotations are used to follow the differential steering:

* **Forward:** Left Joystick = **Up** --> Left Motor: **CW** (Clockwise) | Right Motor: **CCW** (Counter-Clockwise)
* **Backward:** Left Joystick = **Down** --> Left Motor: **CCW** | Right Motor: **CW**
* **Turn Right:** Right Joystick = **Right** --> Left Motor: **CW** | Right Motor: **CW**
* **Turn Left:** Right Joystick = **Left** --> Left Motor: **CCW** | Right Motor: **CCW**
* **Coast / Idle:** Joysticks inside the center deadzone (450 to 570) --> Both Motors: **OFF**

<p align="center">
  <img src="https://github.com/user-attachments/assets/123185df-f556-4580-a39d-8e83444ce98d" alt="WheelAssembly" width="45%"/>
</p>

[![Test Robot on Wokwi W/ PCb](https://img.shields.io/badge/Wokwi-Simulate%20Robot%20Chassis-29b6f6?style=for-the-badge&logo=hardware)](https://wokwi.com/projects/469191659636854785)

---

## Repository Structure

[![GitHubTree](https://img.shields.io/badge/GitHubTree-BumperGoals-blue?style=flat-square)](https://githubtree.mgks.dev/repo/NidheeshP28/BumperGoals/main/?ref=badge)
