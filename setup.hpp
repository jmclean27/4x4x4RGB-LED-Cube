#pragma once
#include "level.hpp"
#include "cube.hpp"
#include "led.hpp"
#include "Launch.hpp"
#include "Rain.hpp"

#define l1_pin 23
#define l2_pin 22
#define l3_pin 25
#define l4_pin 26

#define clk_pin 18
#define le_pin 5
#define sdi_pin 17

#define oe_red_1 16
#define oe_red_2 4
#define oe_green_1 2
#define oe_green_2 15
#define oe_blue_1 21
#define oe_blue_2 19

#define touch_pin_1 32
#define touch_pin_2 33
#define touch_pin_3 27

#define sdo_pin 14

volatile unsigned long tick1 = 0;

cube red, green, blue;
LED led(red, green, blue);
Launch launch(red,green,blue,&tick1);
Rain rain(red,green,blue,&tick1);

void load_O(uint8_t layer, bool horizontal = true);
void load_M(uint8_t layer, bool horizontal = true);
void load_A(uint8_t layer, bool horizontal = true);
void load_R(uint8_t layer, bool horizontal = true);

hw_timer_t* Timer0_Cfg = NULL;
hw_timer_t* RunTimer1 = NULL;

volatile uint8_t tick = 0;
void IRAM_ATTR Timer0_ISR(){
    uint8_t layer = tick / 4;
    uint8_t brightness = tick % 4;
    shiftOut(sdi_pin, clk_pin, LSBFIRST, blue.getLevel(3-layer).send(brightness)[1]);
    shiftOut(sdi_pin, clk_pin, LSBFIRST, blue.getLevel(3-layer).send(brightness)[0]);
    
    shiftOut(sdi_pin, clk_pin, LSBFIRST, green.getLevel(3-layer).send(brightness)[1]);
    shiftOut(sdi_pin, clk_pin, LSBFIRST, green.getLevel(3-layer).send(brightness)[0]);
    
    shiftOut(sdi_pin, clk_pin, LSBFIRST, red.getLevel(3-layer).send(brightness)[1]);
    shiftOut(sdi_pin, clk_pin, LSBFIRST, red.getLevel(3-layer).send(brightness)[0]);

    digitalWrite(l1_pin, 1);
    digitalWrite(l2_pin, 1);
    digitalWrite(l3_pin, 1);
    digitalWrite(l4_pin, 1);

    digitalWrite(le_pin, HIGH);
    
    digitalWrite(l4_pin, layer != 3);
    digitalWrite(l3_pin, layer != 2);
    digitalWrite(l2_pin, layer != 1);
    digitalWrite(l1_pin, layer != 0);

    digitalWrite(le_pin, LOW);

    tick == 15 ? tick = 0 : tick++;
}

void IRAM_ATTR RunTimer1_ISR(){
    tick1++;
}