#include <Arduino.h>
#include <FastLED.h>

#define LED_PIN D4
#define LED_NUM 60

#define for_i(NUM) for (uint32_t i = 0; i < NUM; i++)
#define for_j(NUM) for (uint32_t j = 0; j < NUM; j++)
#define inverse_for_i(NUM) for (uint32_t i = NUM - 1; i >= 0; i--)
#define inverse_for_j(NUM) for (uint32_t j = NUM - 1; j >= 0; j--)

CRGB leds[LED_NUM];

void set_color(uint32_t index, uint32_t color)
{
    if (index > 0 && index < LED_NUM)
    {
        leds[index].setColorCode(color);
    }
}

void setup()
{
    FastLED.addLeds<WS2811, LED_PIN, GRB>(leds, LED_PIN);
}

void loop()
{
    for_i(LED_NUM)
    {
        set_color(i, CRGB::Red);
    }

    inverse_for_i(LED_NUM)
    {
        set_color(i, CRGB::Black);
    }
}
