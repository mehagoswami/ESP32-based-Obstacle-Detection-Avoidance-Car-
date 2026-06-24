# ESP32-based-Obstacle-Detection-Avoidance-Car-

An autonomous robot car built using **ESP32**, **HC-SR04 Ultrasonic Sensor**, **Servo Motor**, and **L298N Motor Driver**. The robot detects obstacles in real-time and automatically navigates around them without human intervention.

## 📌 Features

* Real-time obstacle detection using ultrasonic sensing
* Autonomous navigation and path selection
* Automatic left/right scanning using servo motor
* Reverse maneuver when obstacles are detected
* Continuous autonomous operation
* Low-cost and beginner-friendly robotics project

## 🛠️ Hardware Components

| Component                 | Quantity    |
| ------------------------- | ----------- |
| ESP32 Development Board   | 1           |
| HC-SR04 Ultrasonic Sensor | 1           |
| Servo Motor               | 1           |
| L298N Motor Driver        | 1           |
| DC Motors                 | 2           |
| Robot Chassis & Wheels    | 1           |
| Battery Pack              | 1           |
| Jumper Wires              | As Required |

## 🔧 Pin Configuration

| ESP32 Pin | Component       |
| --------- | --------------- |
| GPIO 14   | Motor IN1       |
| GPIO 27   | Motor IN2       |
| GPIO 26   | Motor IN3       |
| GPIO 25   | Motor IN4       |
| GPIO 33   | Ultrasonic TRIG |
| GPIO 32   | Ultrasonic ECHO |
| GPIO 13   | Servo Signal    |

## ⚙️ Working Principle

1. The robot continuously moves forward.
2. The ultrasonic sensor measures the distance ahead.
3. If an obstacle is detected within 30 cm:

   * The robot stops.
   * Moves backward slightly.
   * Scans left and right using the servo-mounted sensor.
4. The direction with greater free space is selected.
5. The robot turns and continues moving.
6. This process repeats continuously for autonomous navigation.

## 📚 Functions Used

### `getDistance()`

Measures the distance between the robot and obstacles.

### `forwardSlow()`

Moves the robot forward at a controlled speed.

### `stopCar()`

Stops all motor movement.

### `left()`

Turns the robot left.

### `right()`

Turns the robot right.

### `reverseShort()`

Moves the robot backward for a short duration.

## 🚀 Installation

1. Install Arduino IDE.
2. Install ESP32 board support package.
3. Install the ESP32Servo library.
4. Connect all hardware components according to the wiring configuration.
5. Upload the code to the ESP32 board.
6. Power the robot using a battery pack.

## 📂 Project Structure

```
Obstacle-Avoiding-Car/
│
├── Obstacle_Avoiding_Car.ino
├── README.md
└── Images/
    ├── robot.jpg
    ├── circuit_diagram.png
    └── working_demo.gif
```

## 🔮 Future Improvements

* Camera-based obstacle detection
* AI-powered navigation
* Path mapping and localization
* IoT monitoring and control
* Bluetooth/Wi-Fi remote operation

## 🎯 Learning Outcomes

* Embedded Systems Programming
* Robotics Fundamentals
* Sensor Integration
* Autonomous Navigation
* Motor Control using ESP32

## 📜 License

This project is licensed under the MIT License.

## 👨‍💻 Author

**Meha Goswami**

Computer Science Engineering Student

