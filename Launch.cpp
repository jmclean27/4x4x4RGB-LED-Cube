#include "Launch.hpp"

Launch::Launch(cube& r, cube& g, cube& b, volatile unsigned long* t): red(r), green(g), blue(b){
    ti = t;
}

Launch::~Launch(){

}


void Launch::set(uint8_t x, uint8_t y, uint8_t z, uint8_t r,  uint8_t g, uint8_t b){
    red[z][y][x] = r;
    green[z][y][x] = g;
    blue[z][y][x] = b;
}

void Launch::Firework(uint8_t x, uint8_t y){
    unsigned long start_time = *ti;
    int step = 300;
    for(uint8_t i = 0; i < 4; i++){
        this->set(x,y,i,0,0,4);
        while(*ti - start_time < step*(i+1)){}
        this->set(x,y,i,0,0,0);
    }
    this->Flash(x,y);
}

void Launch::RFirework(){
    if(lit % 16 == 0) red.reset(3);

    uint8_t x, y;
    while(true){
        x = rand() % 4;
        y = rand() % 4;

        if(red.getLevel(3)[y][x] != 0) continue;

        break;
    }
    lit++;
    this->Firework(x, y);
}

void Launch::Flash(uint8_t x, uint8_t y){
    this->set(x,y,3,4,0,0);
}