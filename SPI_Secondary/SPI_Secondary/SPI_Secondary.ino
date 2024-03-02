byte dataToEcho; // Declare a global variable to be used in interrupt
boolean blink = LOW;
void setup() {
Serial.begin(115200);
DDRB |= 0b00010001; // MISO LED(8) Output
PORTB |= 0b00000100; // Set secondary select HIGH
SPCR |= 0b11000000; // Turn SPIE and SPE on
SPSR |= 0b00000000; // Default SPI settings
sei(); // Enable global interrupts
}// End setup
void loop() {
digitalWrite(8, (blink = !blink)); // Blink LED life check
delay(1000);
}// End loop
ISR(SPI_STC_vect) {
cli(); // Turn interrupts off while running sensitive code
while (!(PINB & 0b00000100)) { // Enter while loop if secondary select is low
SPDR = dataToEcho; // Load the SPI data register with data to shift out
while (!(SPSR & (1 << SPIF))); // Wait till data transfer is complete
dataToEcho = SPDR; // Read the incomming data. This byte will be sent next interrupt.
}
sei(); // Turn interrupts back on when done
}// End ISR for spi