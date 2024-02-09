#include "Rain.hpp"

Rain::Rain(cube& r, cube& g, cube& b, volatile unsigned long* t): red(r), green(g), blue(b){
    ti = t;
}

Rain::~Rain(){

}


void Rain::set(uint8_t x, uint8_t y, uint8_t z, uint8_t r,  uint8_t g, uint8_t b){
    red[z][y][x] = r;
    green[z][y][x] = g;
    blue[z][y][x] = b;
}


void Rain::RainUP(uint8_t x, uint8_t y){

    if(lit == 0){
        this->set(x,y,0,4,0,0);
        return;
    }
    this->set(x,y,lit - 1,0,0,0);       
    this->set(x,y,lit,4,0,0);

    if(lit == 3){
        this->TopFull(x,y);
        return;
    }
}

void Rain::RainDOWN(uint8_t x, uint8_t y){

    if(lit == 0){
        this->set(x,y,3,0,0,4);
        return;
    }
    this->set(x,y,4 - lit,0,0,0);       
    this->set(x,y,(4 - lit) - 1,0,0,4);

    if(lit == 3){
        this->TopFull(x,y);
        return;
    }   
}

void Rain::rain(){
    if(lit == 0){
        this->RandRain();
        start_time = *ti;
    } 
    if(*ti - start_time < step * lit) return;
    if(lit < 4) up == true ? this->RainUP(x, y) : this->RainDOWN(x, y); 
    lit++;
    if(lit == 4 + rainDelay){
        lit = 0;  
        swap++;
    }   
    if (swap == 16){
        swap = 0;
        up = !up;
    }
}

void Rain::RandRain(){
    while(true){
        x = rand() % 4;
        y = rand() % 4;
        if(up && red.getLevel(3)[y][x]) continue;
        if(!up && blue.getLevel(0)[y][x]) continue;
        break;
    }
}

void Rain::TopFull(uint8_t x, uint8_t y){
    up == true ? this->set(x,y,3,4,0,0) : this->set(x,y,0,0,0,4);
}