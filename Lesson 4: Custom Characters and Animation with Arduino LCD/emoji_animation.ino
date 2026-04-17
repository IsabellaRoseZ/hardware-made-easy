#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Clearer, bolder faces
byte happy[8] = {
  B00000,
  B01010,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
  B00000
};

byte sad[8] = {
  B00000,
  B01010,
  B00000,
  B00000,
  B01110,
  B10001,
  B00000,
  B00000
};

byte wink[8] = {
  B00000,
  B01000,
  B00010,
  B00000,
  B10001,
  B01110,
  B00000,
  B00000
};

byte neutral[8] = {
  B00000,
  B01010,
  B00000,
  B00000,
  B11111,
  B00000,
  B00000,
  B00000
};

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.createChar(0, happy);
  lcd.createChar(1, sad);
  lcd.createChar(2, wink);
  lcd.createChar(3, neutral);
}

// Pattern with spacing
void drawPatternA() {
  for (int row = 0; row < 2; row++) {
    lcd.setCursor(0, row);
    for (int col = 0; col < 16; col++) {
      if (col % 2 == 0) {
        lcd.write(byte((col / 2) % 4)); // faces
      } else {
        lcd.print(" "); // space between faces
      }
    }
  }
}

// Alternate pattern
void drawPatternB() {
  for (int row = 0; row < 2; row++) {
    lcd.setCursor(0, row);
    for (int col = 0; col < 16; col++) {
      if (col % 2 == 0) {
        lcd.write(byte(((col / 2) + 2) % 4)); // shifted faces
      } else {
        lcd.print(" ");
      }
    }
  }
}

void loop() {
  drawPatternA();
  delay(600);

  drawPatternB();
  delay(600);
}
