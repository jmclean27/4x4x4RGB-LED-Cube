#pragma once
#include "cube.hpp"

class Launch{

    public:


    Launch(cube& r, cube& g, cube& b, volatile unsigned long int* t);


    ~Launch();


    void set(uint8_t x, uint8_t y, uint8_t z, uint8_t r,  uint8_t g, uint8_t b);
    void Firework(uint8_t x, uint8_t y);
    void RFirework();
    void Flash(uint8_t x, uint8_t y);



    private:

    cube& red;
    cube& green;
    cube& blue;
    volatile unsigned long int* ti;
    uint8_t lit = 0;

};