/*
    Project name: ESP32 LED Matrix Display
    Modified Date: 24-06-2024
    Code by: Projectslearner
    Website: https://projectslearner.com/learn/esp32-led-matrix-display
*/

#include <Adafruit_GFX.h>   // Include the Adafruit graphics library
#include <Adafruit_NeoMatrix.h> // Include the Adafruit NeoMatrix library

#define WIDTH   8 // Width of LED matrix
#define HEIGHT  8 // Height of LED matrix
#define PIN     2 // GPIO pin connected to LED matrix

// Define the NeoMatrix configuration
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(WIDTH, HEIGHT, PIN,
  NEO_MATRIX_TOP + NEO_MATRIX_LEFT +
  NEO_MATRIX_ROWS + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB + NEO_KHZ800);

void setup() {
  matrix.begin(); // Initialize the LED matrix
  matrix.setTextWrap(false); // Don't wrap text

  matrix.setBrightness(50); // Set brightness (0-255)
  matrix.setTextColor(matrix.Color(255, 0, 0)); // Set text color (R,G,B)
}

void loop() {
  matrix.fillScreen(0); // Clear matrix

  // Draw text scrolling from right to left
  matrix.setCursor(0, 0); // Set starting position
  matrix.print("Hello, World!"); // Display text

  // Scroll text
  for (int16_t x = matrix.width(); x >= -matrix.width(); x--) {
    matrix.clear(); // Clear matrix
    matrix.setCursor(x, 0); // Set new cursor position
    matrix.print("Hello, World!"); // Display text
    matrix.show(); // Display updated matrix
    delay(100); // Delay between frames (adjust as needed)
  }
}
