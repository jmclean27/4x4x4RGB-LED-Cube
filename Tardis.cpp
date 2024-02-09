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


void Tardis::tardis(uint8_t x, uint8_t y, uint8_t z){
    if(step == 0){
        this->MoveCube(rand() %3, rand() %3, rand () %3);
        start_time = *ti;
        rand();
        step++;
    }

}


void Tardis::MoveCube(uint8_t x, uint8_t y, uint8_t z){
    for(uint8_t i = 0; i < 2; i++){
        for(uint8_t j = 0; j < 2; j++){
            this->set(x+j,y+0,z+i,0,0,4);
            this->set(x+j,y+1,z+i,0,0,4);
        }
    }
}


void Tardis::RandDir(){
    QDir = rand() % 8;
}


void Tardis::bump(){

}

