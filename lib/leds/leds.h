
#ifndef LEDS_H
#define LEDS_H

#include <ArduinoJson.h>
#include <FastLED.h>

#define MATRIX_WIDTH 32
#define MATRIX_HEIGHT 8
#define DIGIT_WIDTH 5
#define LOGO_WIDTH 8

#define LUMINOSITY 50

CRGB *getLEDs();
void sortCoordonates();
void showNumberDigit(int digit, int number, String color);
void showNumbers(int number, String color);
CRGB getRGB(String color);
void changeColorDigitLed(int digit, int xDigit, int yDigit, String color);
void goOverNumberArray(int digit, int array[MATRIX_HEIGHT][DIGIT_WIDTH], String color);
void showLogo(String brand);
void showBrandNumber(String brand, int number);

#endif