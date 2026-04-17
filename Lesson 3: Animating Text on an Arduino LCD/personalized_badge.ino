#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Change these to your real info
const char* screens[] = {
  "Your Name", // CUSTOMIZE
  "Stan State", // CUSTOMIZE
  "Computer Science" // CUSTOMIZE
};

const int totalScreens = sizeof(screens) / sizeof(screens[0]);
int currentScreen = 0;

// Center text on row 0
void printCentered(const char* text) {
  int len = strlen(text);
  int startCol = (16 - len) / 2;
  if (startCol < 0) startCol = 0;

  lcd.setCursor(0, 0);
  lcd.print("                ");  // clear row

  lcd.setCursor(startCol, 0);
  for (int i = 0; i < len && i < 16; i++) {
    lcd.print(text[i]);
    delay(90); // typing speed
  }
}

// Erase text from right to left
void eraseCentered(const char* text) {
  int len = strlen(text);
  int startCol = (16 - len) / 2;
  if (startCol < 0) startCol = 0;

  for (int i = len - 1; i >= 0 && i < 16; i--) {
    lcd.setCursor(startCol + i, 0);
    lcd.print(" ");
    delay(50); // erase speed
  }
}

void showSubtitle(const char* subtitle) {
  lcd.setCursor(0, 1);
  lcd.print("                "); // clear row
  int len = strlen(subtitle);
  int startCol = (16 - len) / 2;
  if (startCol < 0) startCol = 0;
  lcd.setCursor(startCol, 1);
  lcd.print(subtitle);
}

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 1);
  lcd.print("  Loading...    ");
  delay(1000);
  lcd.clear();
}

void loop() {
  // Optional little label on second line
  if (currentScreen == 0) {
    showSubtitle("Name");
  } else if (currentScreen == 1) {
    showSubtitle("University");
  } else {
    showSubtitle("Major");
  }

  printCentered(screens[currentScreen]);
  delay(1200);
  eraseCentered(screens[currentScreen]);
  delay(250);

  currentScreen++;
  if (currentScreen >= totalScreens) {
    currentScreen = 0;
  }
}
