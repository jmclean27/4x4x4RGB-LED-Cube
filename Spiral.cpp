#include "Spiral.hpp"

Spiral::Spiral(cube& r, cube& g, cube& b, volatile unsigned long* t): red(r), green(g), blue(b){
    ti = t;
}

Spiral::~Spiral(){

}


void Spiral::set(uint8_t x, uint8_t y, uint8_t z, uint8_t r,  uint8_t g, uint8_t b){
    red[z][y][x] = r;
    green[z][y][x] = g;
    blue[z][y][x] = b;
}


void Spiral::spiral(){
    if(!step){
        this->DisplayCube(0, 0, 0);
        start_time = *ti;
        step++;
        return;
    }
    if(*ti - start_time < speed) return;   
    start_time = *ti;
    

}


void Spiral::DisplayCube(uint8_t x, uint8_t y, uint8_t z){

}