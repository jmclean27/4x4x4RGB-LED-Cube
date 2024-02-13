#pragma once
#include "cube.hpp"

class Spiral{

    public:


    Spiral(cube& r, cube& g, cube& b, volatile unsigned long int* t);


    ~Spiral();

    void set(uint8_t x, uint8_t y, uint8_t z, uint8_t r,  uint8_t g, uint8_t b);
    void spiral();
    void DisplayCube(uint8_t x, uint8_t y, uint8_t z);



    private:

    // user adjustable variables
    uint speed = 300;                //  adjusts the speed of the animation
    uint flashSpeed = 10;            //  adjusts the anount of flashes


    //  non user adjustable variables
    cube& red;
    cube& green;
    cube& blue;
    volatile unsigned long int* ti;
    unsigned long start_time = 0;
    bool step = 0;
};