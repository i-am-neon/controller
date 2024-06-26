#include "LedStrip.h"

int currentMaxBrightness = DEFAULT_MAX_BRIGHTNESS; // Initialize with default maximum brightness
int ledPins[NUM_STRIPS] = {32, 25, 27, 12, 19, 5, 4, 15};

Adafruit_NeoPixel strips[NUM_STRIPS] = {
    Adafruit_NeoPixel(NUM_LEDS_PER_STRIP, ledPins[0], NEO_GRB + NEO_KHZ800),
    Adafruit_NeoPixel(NUM_LEDS_PER_STRIP, ledPins[1], NEO_GRB + NEO_KHZ800),
    Adafruit_NeoPixel(NUM_LEDS_PER_STRIP, ledPins[2], NEO_GRB + NEO_KHZ800),
    Adafruit_NeoPixel(NUM_LEDS_PER_STRIP, ledPins[3], NEO_GRB + NEO_KHZ800),
    Adafruit_NeoPixel(NUM_LEDS_PER_STRIP, ledPins[4], NEO_GRB + NEO_KHZ800),
    Adafruit_NeoPixel(NUM_LEDS_PER_STRIP, ledPins[5], NEO_GRB + NEO_KHZ800),
    Adafruit_NeoPixel(NUM_LEDS_PER_STRIP, ledPins[6], NEO_GRB + NEO_KHZ800),
    Adafruit_NeoPixel(NUM_LEDS_PER_STRIP, ledPins[7], NEO_GRB + NEO_KHZ800)};

void setupStrips()
{
  for (int i = 0; i < NUM_STRIPS; i++)
  {
    strips[i].begin();
    strips[i].setBrightness(currentMaxBrightness);
    strips[i].show(); // Initialize all pixels to 'off'
  }
}

void setBrightness(int brightness)
{
  currentMaxBrightness = brightness; // Update the global brightness level
  for (int i = 0; i < NUM_STRIPS; i++)
  {
    strips[i].setBrightness(brightness);
    strips[i].show();
  }
}
