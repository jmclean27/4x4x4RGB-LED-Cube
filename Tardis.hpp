#pragma once
#include "cube.hpp"

class Tardis{

    public:


    Tardis(cube& r, cube& g, cube& b, volatile unsigned long int* t);


    ~Tardis();

    void set(uint8_t x, uint8_t y, uint8_t z, uint8_t r,  uint8_t g, uint8_t b);
    void tardis();
    void CheckBump();
    void MoveCube();
    void HideCube(uint8_t x, uint8_t y, uint8_t z);
    void DisplayCube(uint8_t x, uint8_t y, uint8_t z);
    void RandDir();
    void Flash();
    bool FlashCrash(uint8_t x, uint8_t y, uint8_t z);



    private:

    // user adjustable variables
    uint speed = 300;                //  adjusts the speed of the animation
    uint flashSpeed = 10;           //  adjusts the anount of flashes


    //  non user adjustable variables
    cube& red;
    cube& green;
    cube& blue;
    volatile unsigned long int* ti;
    unsigned long start_time = 0;
    bool step = 0;
    uint8_t xyz[3][3] = {{0, 0, 0},     // xyz possition of cube
                        {1, 1, 1},      // direction of movement 1 up, 0 down
                        {1, 1, 1}};     // if there is movement 1 yes, 0 no
};