#include <SoftwareSerial.h>

const int RXPin = 4; // GPS module RX pin connected to Arduino TX pin
const int TXPin = 3; // GPS module TX pin connected to Arduino RX pin
const int GPSBaud = 9600; // GPS module baud rate

// Create a SoftwareSerial object for GPS communication
SoftwareSerial gpsSerial(RXPin, TXPin);

void setup() {
  // Start serial communication with the PC
  Serial.begin(115200);
  Serial.println("GPS NMEA Sentences");

  // Start software serial communication with the GPS module
  gpsSerial.begin(GPSBaud);
}

void loop() {
  // Check if data is available from the GPS
  while (gpsSerial.available()) {
    char c = gpsSerial.read();
    
    // Print the received character to the Serial Monitor
    Serial.print(c);
  }
}
