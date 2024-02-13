#pragma once
#include "cube.hpp"

class LED{

    public:


    LED(cube& r, cube& g, cube& b);


    ~LED();


    void set(uint8_t x, uint8_t y, uint8_t z, uint8_t r,  uint8_t g, uint8_t b);
    void SmallCube(uint8_t x, uint8_t y, uint8_t z, uint8_t r,  uint8_t g, uint8_t b);
    void rain();
    void small_cube();




    private:

    cube& red;
    cube& green;
    cube& blue;


};