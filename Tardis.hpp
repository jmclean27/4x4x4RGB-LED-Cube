#pragma once
#include "cube.hpp"

class Tardis{

    public:


    Tardis(cube& r, cube& g, cube& b, volatile unsigned long int* t);


    ~Tardis();

    void set(uint8_t x, uint8_t y, uint8_t z, uint8_t r,  uint8_t g, uint8_t b);
    void tardis(uint8_t x, uint8_t y, uint8_t z);
    void MoveCube(uint8_t x, uint8_t y, uint8_t z);
    void RandDir();
    void bump();



    private:

    cube& red;
    cube& green;
    cube& blue;
    volatile unsigned long int* ti;
    uint step = 300;                //  adjusts the speed of the animation
    unsigned long start_time = 0;
    int step = 0;
    uint8_t QDir = 0;

};