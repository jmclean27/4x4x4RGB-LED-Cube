#pragma once
#include "cube.hpp"

class Rain{

    public:


    Rain(cube& r, cube& g, cube& b, volatile unsigned long int* t);


    ~Rain();


    void set(uint8_t x, uint8_t y, uint8_t z, uint8_t r,  uint8_t g, uint8_t b);
    void rain();
    void RainUP(uint8_t x, uint8_t y);
    void RainDOWN(uint8_t x, uint8_t y);
    void RandRain();
    void TopFull(uint8_t x, uint8_t y);



    private:

    cube& red;
    cube& green;
    cube& blue;
    volatile unsigned long int* ti;
    uint8_t lit = 0;
    uint8_t swap = 0;
    bool up = true;
    unsigned long start_time = 0;
    uint step = 300;                //  adjusts the speed of the animation
    uint8_t x, y = 0;
    uint8_t rainDelay = 2;          //  adjusts the delay between each rain

};