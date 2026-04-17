#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the LCD (address 0x27, 16 columns, 2 rows)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();          // Initialize the LCD
  lcd.backlight();     // Turn on backlight

  lcd.setCursor(0, 0); // Column 0, Row 0
  lcd.print("Hello, World!");
}

void loop() {
  // Nothing needed here
}
