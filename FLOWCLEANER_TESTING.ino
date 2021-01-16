#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306.h" // alias for `#include "SSD1306Wire.h"`
#include "Adafruit_MCP23017.h"

Adafruit_MCP23017 mcp;

SSD1306  display(0x3c, 5, 4);
unsigned long previousMillis = 0;

void setup() {
  Serial.begin(115200);
  Serial.println();

  // Initialising the UI will init the display too.
  display.init();

  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);

  //Wire.begin(0,2); 
  mcp.begin();      // use default address 0
  Serial.println("setup!");
  mcp.pinMode(0, OUTPUT);
  mcp.pinMode(1, OUTPUT);
  mcp.pinMode(2, OUTPUT);
  mcp.pinMode(3, OUTPUT);
  mcp.pinMode(4, OUTPUT);

}

void loop() {
  // clear the display
  unsigned long currentMillis = millis();
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_16);
  display.drawString(0, 0, "Timer-impuls 1s");

  display.setFont(ArialMT_Plain_10);
  display.drawString(50, 52, String(previousMillis));
  // write the buffer to the display
  display.display();

  if (currentMillis - previousMillis >= 3000) {
    previousMillis = currentMillis;
  }

  delay(10);
  Serial.println("loop!");
  mcp.digitalWrite(0, HIGH);
  mcp.digitalWrite(1, HIGH);
  mcp.digitalWrite(2, HIGH);
  mcp.digitalWrite(3, HIGH);
  mcp.digitalWrite(4, HIGH);
  delay(2000);
  mcp.digitalWrite(0, LOW);
  delay(500);
  mcp.digitalWrite(1, LOW);
  delay(500);
  mcp.digitalWrite(2, LOW);
  delay(500);
  mcp.digitalWrite(3, LOW);
  delay(500);
  mcp.digitalWrite(4, LOW);
  delay(1500);
}

