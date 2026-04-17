#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Screens (each is 2 lines)
String screens[][2] = {
  {"What would life", "be"}, \\ CHANGE TO YOUR QUOTE
  {"if we had no", "courage"}, \\ CHANGE TO YOUR QUOTE
  {"to attempt", "anything?"}, \\ CHANGE TO YOUR QUOTE
  {"Quote By:", "Vincent Van Gogh"} \\ CHANGE TO YOUR QUOTE
};

int totalScreens = 4;
int currentScreen = 0;

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  lcd.clear();

  // Row 1
  lcd.setCursor(0, 0);
  lcd.print(screens[currentScreen][0]);

  // Row 2
  lcd.setCursor(0, 1);
  lcd.print(screens[currentScreen][1]);

  delay(1500); // 1.5 seconds

  currentScreen++;
  if (currentScreen >= totalScreens) {
    currentScreen = 0;
  }
}
