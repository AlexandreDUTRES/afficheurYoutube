
#include "leds.h"

int off[MATRIX_HEIGHT][DIGIT_WIDTH] = {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}};

int zero[MATRIX_HEIGHT][DIGIT_WIDTH] = {
    {0, 1, 1, 1, 0},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 1, 1},
    {1, 0, 1, 0, 1},
    {1, 1, 0, 0, 1},
    {1, 0, 0, 0, 1},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0}};

int one[MATRIX_HEIGHT][DIGIT_WIDTH] = {
    {1, 1, 1, 1, 1},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 1},
    {0, 0, 1, 1, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}};

int two[MATRIX_HEIGHT][DIGIT_WIDTH] = {
    {1, 1, 1, 1, 1},
    {0, 0, 0, 1, 0},
    {0, 0, 1, 0, 0},
    {0, 1, 0, 0, 0},
    {1, 0, 0, 0, 0},
    {1, 0, 0, 0, 1},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0}};

int three[MATRIX_HEIGHT][DIGIT_WIDTH] = {
    {0, 1, 1, 1, 0},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0},
    {0, 1, 1, 0, 0},
    {1, 0, 0, 0, 0},
    {1, 0, 0, 0, 1},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0}};

int four[MATRIX_HEIGHT][DIGIT_WIDTH] = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 0, 0},
    {1, 1, 1, 1, 1},
    {0, 1, 0, 0, 1},
    {0, 1, 0, 1, 0},
    {0, 1, 1, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0}};

int five[MATRIX_HEIGHT][DIGIT_WIDTH] = {
    {0, 1, 1, 1, 0},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0},
    {1, 0, 0, 0, 0},
    {0, 1, 1, 1, 1},
    {0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0}};

int six[MATRIX_HEIGHT][DIGIT_WIDTH] = {
    {0, 1, 1, 1, 0},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1},
    {0, 1, 1, 1, 1},
    {0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0}};

int seven[MATRIX_HEIGHT][DIGIT_WIDTH] = {
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 1, 0, 0, 0},
    {1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0}};

int eight[MATRIX_HEIGHT][DIGIT_WIDTH] = {
    {0, 1, 1, 1, 0},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1},
    {0, 1, 1, 1, 0},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0}};

int nine[MATRIX_HEIGHT][DIGIT_WIDTH] = {
    {0, 1, 1, 1, 0},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0},
    {1, 1, 1, 1, 0},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0}};

String youtube_logo[MATRIX_HEIGHT][LOGO_WIDTH] = {
    {"off", "off", "off", "off", "off", "off", "off", "off"},
    {"off", "red", "red", "red", "red", "red", "red", "off"},
    {"red", "red", "red", "red", "white", "red", "red", "red"},
    {"red", "red", "red", "white", "white", "red", "red", "red"},
    {"red", "red", "red", "red", "white", "red", "red", "red"},
    {"off", "red", "red", "red", "red", "red", "red", "off"},
    {"off", "off", "off", "off", "off", "off", "off", "off"},
    {"off", "off", "off", "off", "off", "off", "off", "off"},
};

int xShift = 0;

int leds_coordonates[MATRIX_WIDTH][MATRIX_HEIGHT];
CRGB leds[MATRIX_WIDTH * MATRIX_HEIGHT];

CRGB *getLEDs()
{
   return leds;
}

CRGB getRGB(String color)
{
   if (color == "white")
      return CRGB(LUMINOSITY, LUMINOSITY, LUMINOSITY);
   if (color == "red")
      return CRGB(LUMINOSITY, 0, 0);
   if (color == "blue")
      return CRGB(0, 0, LUMINOSITY);
   if (color == "green")
      return CRGB(0, LUMINOSITY, 0);

   return CRGB(0, 0, 0);
}

void changeColorDigitLed(int digit, int xDigit, int yDigit, String color)
{
   int xGlobal = xDigit + (digit * (DIGIT_WIDTH + 1)) + xShift;
   int yGlobal = yDigit;

   if (xGlobal < MATRIX_WIDTH && xGlobal >= 0 && yGlobal < MATRIX_HEIGHT && yGlobal >= 0)
   {
      leds[leds_coordonates[xGlobal][yGlobal]] = getRGB(color);
   }
}

void goOverNumberArray(int digit, int array[MATRIX_HEIGHT][DIGIT_WIDTH], String color)
{
   for (int y = 0; y < MATRIX_HEIGHT; y++)
   {
      for (int x = 0; x < DIGIT_WIDTH; x++)
      {
         changeColorDigitLed(digit, x, y, array[y][x] == 1 ? color : "");
      }
   }
}

void goOverLogoArray(String array[MATRIX_HEIGHT][LOGO_WIDTH])
{
   for (int y = 0; y < MATRIX_HEIGHT; y++)
   {
      for (int x = 0; x < LOGO_WIDTH; x++)
      {
         changeColorDigitLed(4, x, y, array[y][x]);
      }
   }
}

void sortCoordonates()
{
   for (int y = 0; y < MATRIX_HEIGHT; y++)
   {
      for (int x = 0; x < MATRIX_WIDTH; x++)
      {
         if (y % 2 == 0)
         {
            leds_coordonates[x][y] = y * MATRIX_WIDTH + x;
         }
         else
         {
            leds_coordonates[x][y] = (y + 1) * MATRIX_WIDTH - (x + 1);
         }
      }
   }
}

void showNumberDigit(int digit, int number, String color)
{
   switch (number)
   {
   case 0:
      goOverNumberArray(digit, zero, color);
      break;
   case 1:
      goOverNumberArray(digit, one, color);
      break;
   case 2:
      goOverNumberArray(digit, two, color);
      break;
   case 3:
      goOverNumberArray(digit, three, color);
      break;
   case 4:
      goOverNumberArray(digit, four, color);
      break;
   case 5:
      goOverNumberArray(digit, five, color);
      break;
   case 6:
      goOverNumberArray(digit, six, color);
      break;
   case 7:
      goOverNumberArray(digit, seven, color);
      break;
   case 8:
      goOverNumberArray(digit, eight, color);
      break;
   case 9:
      goOverNumberArray(digit, nine, color);
      break;
   default:
      goOverNumberArray(digit, off, color);
   }
}

void showLogo(String brand)
{
   if (brand == "youtube")
      goOverLogoArray(youtube_logo);
}

void showNumbers(int number, String color)
{
   int d3 = (number) / 1000;
   int d2 = (number - d3 * 1000) / 100;
   int d1 = (number - d3 * 1000 - d2 * 100) / 10;
   int d0 = (number - d3 * 1000 - d2 * 100 - d1 * 10);

   bool firstShow = false;

   if (d3 > 0)
   {
      showNumberDigit(3, d3, color);
      firstShow = true;
   }
   else
   {
      showNumberDigit(3, -1, color);
   }

   if (d2 > 0 || firstShow)
   {
      showNumberDigit(2, d2, color);
      firstShow = true;
   }
   else
   {
      showNumberDigit(2, -1, color);
   }

   if (d1 > 0 || firstShow)
   {
      showNumberDigit(1, d1, color);
      firstShow = true;
   }
   else
   {
      showNumberDigit(1, -1, color);
   }

   if (d0 > 0 || firstShow)
   {
      showNumberDigit(0, d0, color);
      firstShow = true;
   }
   else
   {
      showNumberDigit(0, -1, color);
   }
}

void showBrandNumber(String brand, int number)
{
   for (int x = 1 - MATRIX_WIDTH; x <= 0; x++)
   {
      FastLED.clear();
      xShift = x;
      showLogo("youtube");
      showNumbers(number, "white");
      FastLED.show();
      delay(50);
   }
}