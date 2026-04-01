#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

int CS_PIN = 10;             // the pin you plugged CS into

// some modules come soldered the wrong way around
// so if your image looks flipped, just swap these two numbers
int MODULES_HORIZONTAL = 4;
int MODULES_VERTICAL   = 1;

Max72xxPanel matrix = Max72xxPanel(CS_PIN, MODULES_HORIZONTAL, MODULES_VERTICAL);

void setup() {
  matrix.setIntensity(5);  // anywhere from 0 to 15 (blinding)

  // each module needs to be rotated so the text isn't sideways
  // try 1, 2 or 3 here until it looks right (90°, 180°, 270°)
  int totalModules = MODULES_HORIZONTAL * MODULES_VERTICAL;
  for (int module = 0; module < totalModules; module++) {
    matrix.setRotation(module, 1);
  }
}

void loop() {
  matrix.fillScreen(LOW);   // wipe everything
  matrix.write();
  delay(1000);

  matrix.fillScreen(HIGH);  // light up every single LED
  matrix.write();
  delay(1000);

  matrix.fillScreen(LOW);
  matrix.write();

  // turn on a single dot — X goes 0–31, Y goes 0–7
  matrix.drawPixel(0, 0, HIGH);
  matrix.drawPixel(5, 3, HIGH);
  matrix.drawPixel(15, 7, HIGH);
  matrix.write();
  delay(1000);

  matrix.fillScreen(LOW);
  matrix.write();

  // draw a line from point A to point B
  matrix.drawLine(0, 0, 31, 7, HIGH);
  matrix.write();
  delay(1000);

  matrix.fillScreen(LOW);
  matrix.write();

  // hollow rectangle — top-left corner, then width and height
  matrix.drawRect(1, 1, 14, 6, HIGH);
  matrix.write();
  delay(1000);

  matrix.fillScreen(LOW);
  matrix.write();

  // hollow circle - center point, then radius
  matrix.drawCircle(8, 3, 3, HIGH);
  matrix.write();
  delay(1000);

  matrix.fillScreen(LOW);
  matrix.write();

  // hollow triangle - just three corner points
  matrix.drawTriangle(4, 7, 12, 0, 20, 7, HIGH);
  matrix.write();
  delay(1000);

  matrix.fillScreen(LOW);
  matrix.write();

  // same as drawRect but filled in solid
  matrix.fillRect(0, 0, 8, 8, HIGH);
  matrix.write();
  delay(1000);

  matrix.fillScreen(LOW);
  matrix.write();

  // same as drawCircle but filled in solid
  matrix.fillCircle(16, 3, 3, HIGH);
  matrix.write();
  delay(1000);

  matrix.fillScreen(LOW);
  matrix.write();

  // set where the text starts, then just print whatever you want
  matrix.setCursor(0, 0);
  matrix.print("Hi!");
  matrix.write();  // nothing shows up until you call this
  delay(2000);

  matrix.fillScreen(LOW);
  matrix.write();
  delay(500);
}
