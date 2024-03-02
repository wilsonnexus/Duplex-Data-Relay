# Duplex-Data-Relay

Overview

Implements full-duplex data transfer between two Arduino boards using SPI communication
One Arduino acts as the Primary, one as the Secondary
Primary relays serial input to Secondary over SPI
Secondary echoes back any data received via SPI
Allows bidirectional data flow between a serial device and SPI network
Primary Arduino Functionality

Listens for data on serial port and relays to Secondary via SPI
Manages SPI communication with Secondary
Uses Secondary select pin to initiate SPI transfer
Sends one byte and receives response byte in full duplex transfer
Prints sent and received bytes to serial port (USB Serial Monitor)
Secondary Arduino Functionality

Listens for data sent over SPI
Interrupt routine reads byte and immediately echoes response over SPI in one transfer
SPI data register automatically shifts out response byte
Loop blinks LED as heartbeat indicator
Wiring

Primary and Secondary MISO/MOSI pins are connected
Primary D10 is connected to Secondary D4 to serve as secondary select signal
Both Arduinos have independent ground/power
To Use

Upload Primary and Secondary code to two Arduino boards
Connect boards to computer via USB
Open Serial Monitor on Primary's USB serial
Send bytes to be relayed between serial and SPI network
