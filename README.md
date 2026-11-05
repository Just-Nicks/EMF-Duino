# EMF DUINO

## About the Project

Eletromagnetic Field Meter with arduino

## Features

- LEDS
- BUZZER

## Required Components

| Component | Quantity |
|---|---:|
| Arduino Nano | 1 |
| Red Led | 1 |
| Orange Led | 1 |
| Yellow Led | 1 |
| Green Led | 2 |
| 220Ω Resistors | 5 |
| Ceramic Capacitor 100nF / 50V | 1 |
| Passive Buzzer | 1 |
| 9V Baterry | 1 |
| Copper Wire | 1 |
| ON/OFF Button | 1 |

## Circuit Connections

Connect the DHT11 sensor to the Arduino Nano as shown in the table.

| Arduino Nano | Conection |
|---|---|---| 
| D12 | Buzzer |
| A0 | Ceramic Capacitor | ANT |
| D2 | Green LED |
| D3 | Green LED |
| D4 | Yellow LED |
| D5 | Orange LED |
| D6 | Red LED |

## Software Requirements

Before you upload the code, install the following software and libraries:

- Arduino IDE

You can install the libraries through the Library Manager in the Arduino IDE.

## How to Install

1. Download or clone this repository.
2. Open the `emf-duino.ino` file in the Arduino IDE.
3. Connect the Arduino Nano to your computer with a USB cable.
4. Select the Arduino Nano board and the correct serial port.
5. Install the required libraries if they are not installed.
6. Upload the code to the board.

## How to Use

After you upload the code, follow these steps:

1. Connect 9V Baterry.
2. Bring the antenna closer to some power source. Source, socket, network cable.
3. The stronger the electronic field, the more LEDs will light up and the buzzer will ring

**Important** - This and a homemade project may not be accurate or may vary depending on the assembly or antenna used 

## Future Improvements

Some features that can be added to this project include:

- 3D Custom Case

## License

this project has its own license.

See the `LICENSE` file for the full license terms.

## Contributing

Suggestions and improvements are welcome.

If you find a problem or want to add a feature, open an issue before you submit a major change. Include a clear description of the problem and the proposed solution.

## Author

Just-Nicks