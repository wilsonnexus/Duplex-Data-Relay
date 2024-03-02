#include <SPI.h> // Include the SPI library for primary
byte dataToSend;
byte dataToReceive;
boolean blink = LOW;
void setup() {
pinMode(8,OUTPUT); // Blink
pinMode(10,OUTPUT); // Set the secondary select pin to output for the primary
digitalWrite(10, HIGH); // Set the secondary select pin high
SPI.begin(); // Start SPI
Serial.begin(115200);
delay(500); // Allow connected devices to initialize
}// End setup
void loop() {
while (Serial.available() > 0) {

dataToSend = Serial.read(); // Read a byte in from serial
transferSPI(dataToSend); // Sent that byte
}
digitalWrite(8, (blink = !blink)); // Blink LED life check
delay(1000);
}// End loop
byte transferSPI(byte dataToSend) {
digitalWrite(10, LOW); // Turn the secondary select on
delay(1); // The secondary takes a moment to respond to the secondary select line falling
dataToReceive = SPI.transfer(dataToSend); // Begin full-duplex data transfer
digitalWrite(10, HIGH); // Turn the secondary select off
Serial.write(dataToSend); // Echo sent data
Serial.println();
Serial.write(dataToReceive); // Display byte received
Serial.println();
}// End transferSPI