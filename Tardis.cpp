#include "Tardis.hpp"

Tardis::Tardis(cube& r, cube& g, cube& b, volatile unsigned long* t): red(r), green(g), blue(b){
    ti = t;
}

Tardis::~Tardis(){

}


void Tardis::set(uint8_t x, uint8_t y, uint8_t z, uint8_t r,  uint8_t g, uint8_t b){
    red[z][y][x] = r;
    green[z][y][x] = g;
    blue[z][y][x] = b;
}


void tardis(uint8_t x, uint8_t y, uint8_t z){

}


void SmallCube(uint8_t x, uint8_t y, uint8_t z){

}


void RandDir(){

}


void bump(){

}

