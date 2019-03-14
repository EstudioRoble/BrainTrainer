// readCapacitivePin
//  Input: Arduino pin number
//  Output: A number, from 0 to 17 expressing
//  how much capacitance is on the pin
//  When you touch the pin, or whatever you have
//  attached to it, the number will get higher
#include "pins_arduino.h" // Arduino pre-1.0 needs this
int capPin [50];
int prevState [50];
int threshold = 7;

#include <Adafruit_NeoPixel.h>
#define PIN 2
Adafruit_NeoPixel strip = Adafruit_NeoPixel(5, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);
  strip.begin();
  strip.setBrightness(100);
  strip.show(); // Initialize all pixels to 'off'

  for (int i = 0; i < 5; i++) {
    strip.setPixelColor(i, 0, 0, 255);
  }
  strip. show();

}

void loop() {


  capPin[22] = readCapacitivePin(22);
  if (capPin[22] > threshold && prevState[22] == 0) {
    Serial.println("22 IN");
    prevState[22] = 1;
    strip.setPixelColor(2, 255, 0, 0);
    strip.show();
  }
  if (capPin[22] < threshold && prevState[22] == 1) {
    Serial.println("22 OFF");
    prevState[22] = 0;
    strip.setPixelColor(2, 0, 0, 255);
    strip.show();
  }


  capPin[23] = readCapacitivePin(23);
  if (capPin[23] > threshold && prevState[23] == 0) {
    Serial.println("23 IN");
    prevState[23] = 1;
    strip.setPixelColor(3, 255, 0, 0);
    strip.show();
  }
  if (capPin[23] < threshold && prevState[23] == 1) {
    Serial.println("23 OFF");
    prevState[23] = 0;
    strip.setPixelColor(3, 0, 0, 255);
    strip.show();
  }

  capPin[24] = readCapacitivePin(24);
  if (capPin[24] > threshold && prevState[24] == 0) {
    Serial.println("24 IN");
    prevState[24] = 1;
    strip.setPixelColor(0, 255, 0, 0);
    strip.show();
  }
  if (capPin[24] < threshold && prevState[24] == 1) {
    Serial.println("24 OFF");
    prevState[24] = 0;
    strip.setPixelColor(0, 0, 0, 255);
    strip.show();
  }
  capPin[25] = readCapacitivePin(25);
  if (capPin[25] > threshold && prevState[25] == 0) {
    Serial.println("25 IN");
    prevState[25] = 1;
    strip.setPixelColor(4, 255, 0, 0);
    strip.show();
  }
  if (capPin[25] < threshold && prevState[25] == 1) {
    Serial.println("25 OFF");
    prevState[25] = 0;
    strip.setPixelColor(4, 0, 0, 255);
    strip.show();
  }

  capPin[26] = readCapacitivePin(26);
  if (capPin[26] > threshold && prevState[26] == 0) {
    Serial.println("26 IN");
    prevState[26] = 1;
    strip.setPixelColor(1, 255, 0, 0);
    strip.show();
  }
  if (capPin[26] < threshold && prevState[26] == 1) {
    Serial.println("26 OFF");
    prevState[26] = 0;
    strip.setPixelColor(1, 0, 0, 255);
    strip.show();
  }

  capPin[27] = readCapacitivePin(27);
  if (capPin[27] > threshold && prevState[27] == 0) {
    Serial.println("27 IN");
    prevState[27] = 1;
    strip.setPixelColor(2, 255, 0, 0);
    strip.show();
  }
  if (capPin[27] < threshold && prevState[27] == 1) {
    Serial.println("27 OFF");
    prevState[27] = 0;
    strip.setPixelColor(2, 0, 0, 255);
    strip.show();
  }

  if (1) { // Graf
    Serial.print("0 17 ");
    Serial.print(readCapacitivePin(22));
    Serial.print(" ");
    Serial.print(readCapacitivePin(23));
    Serial.print(" ");
    Serial.print(readCapacitivePin(24));
    Serial.print(" ");
    Serial.print(readCapacitivePin(25));
    Serial.print(" ");
    Serial.println(readCapacitivePin(26));
  }
}

uint8_t readCapacitivePin(int pinToMeasure) {
  // Variables used to translate from Arduino to AVR pin naming
  volatile uint8_t* port;
  volatile uint8_t* ddr;
  volatile uint8_t* pin;
  // Here we translate the input pin number from
  //  Arduino pin number to the AVR PORT, PIN, DDR,
  //  and which bit of those registers we care about.
  byte bitmask;
  port = portOutputRegister(digitalPinToPort(pinToMeasure));
  ddr = portModeRegister(digitalPinToPort(pinToMeasure));
  bitmask = digitalPinToBitMask(pinToMeasure);
  pin = portInputRegister(digitalPinToPort(pinToMeasure));
  // Discharge the pin first by setting it low and output
  *port &= ~(bitmask);
  *ddr  |= bitmask;
  delay(1);
  uint8_t SREG_old = SREG; //back up the AVR Status Register
  // Prevent the timer IRQ from disturbing our measurement
  noInterrupts();
  // Make the pin an input with the internal pull-up on
  *ddr &= ~(bitmask);
  *port |= bitmask;
  // Now see how long the pin to get pulled up. This manual unrolling of the loop
  // decreases the number of hardware cycles between each read of the pin,
  // thus increasing sensitivity.
  uint8_t cycles = 17;
  if (*pin & bitmask) {
    cycles =  0;
  }
  else if (*pin & bitmask) {
    cycles =  1;
  }
  else if (*pin & bitmask) {
    cycles =  2;
  }
  else if (*pin & bitmask) {
    cycles =  3;
  }
  else if (*pin & bitmask) {
    cycles =  4;
  }
  else if (*pin & bitmask) {
    cycles =  5;
  }
  else if (*pin & bitmask) {
    cycles =  6;
  }
  else if (*pin & bitmask) {
    cycles =  7;
  }
  else if (*pin & bitmask) {
    cycles =  8;
  }
  else if (*pin & bitmask) {
    cycles =  9;
  }
  else if (*pin & bitmask) {
    cycles = 10;
  }
  else if (*pin & bitmask) {
    cycles = 11;
  }
  else if (*pin & bitmask) {
    cycles = 12;
  }
  else if (*pin & bitmask) {
    cycles = 13;
  }
  else if (*pin & bitmask) {
    cycles = 14;
  }
  else if (*pin & bitmask) {
    cycles = 15;
  }
  else if (*pin & bitmask) {
    cycles = 16;
  }
  // End of timing-critical section; turn interrupts back on if they were on before, or leave them off if they were off before
  SREG = SREG_old;
  // Discharge the pin again by setting it low and output
  //  It's important to leave the pins low if you want to
  //  be able to touch more than 1 sensor at a time - if
  //  the sensor is left pulled high, when you touch
  //  two sensors, your body will transfer the charge between
  //  sensors.
  *port &= ~(bitmask);
  *ddr  |= bitmask;
  return cycles;
}
