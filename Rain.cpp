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

// void Rain::RainUP(uint8_t x, uint8_t y){
//     unsigned long start_time = *ti;
//     int step = 300;
//     for(uint8_t i = 0; i < 4; i++){
//         this->set(x,y,i,4,0,0);
//         while(*ti - start_time < step*(i+1)){}
//         this->set(x,y,i,0,0,0);
//     }
//     this->TopFull(x,y);
// }

// void Rain::RainUP(uint8_t x, uint8_t y){

//     if(state == 0){
//         this->set(x,y,state,4,0,0);
//         state++;
//         return;
//     }
//     if(state == 4){
//         this->TopFull(x,y);
//         state = 0;
//         return;
//     }
//     this->set(x,y,state-1,0,0,0);  
//     state++;     
//     this->set(x,y,state-1,4,0,0);    
// }

void Rain::RainUP(uint8_t x, uint8_t y){

    if(lit % 4 == 0){
        this->set(x,y,0,4,0,0);
        return;
    }
    this->set(x,y,(lit % 4) - 1,0,0,0);       
    this->set(x,y,lit % 4,4,0,0);

    if(lit % 4 == 3){
        this->TopFull(x,y);
        return;
    }
}

void Rain::RainDOWN(uint8_t x, uint8_t y){
    unsigned long start_time = *ti;
    int step = 300;
    for(uint8_t i = 4; i > 0; i--){
        this->set(x,y,i-1,0,0,4);
        while(*ti - start_time < step*(5-i)){}
        this->set(x,y,i-1,0,0,0);
    }
    this->TopFull(x,y);    
}

void Rain::rain(){
    if(lit % 4 == 0) start_time = *ti;
    if(*ti - start_time < step * (lit % 4)) return;
    this->RandRain();
}

void Rain::RandRain(){
    // if(lit % (16*4) == 0) up = !up;//red.reset(3);
    if(lit == 64){
        up = !up;
        lit = 0;
    }


    if(lit % 4 == 0){
        while(true){
            x = rand() % 4;
            y = rand() % 4;

            if(up && red.getLevel(3)[y][x]) continue;

            if(!up && blue.getLevel(0)[y][x]) continue;

            break;
        }
    }

    up == true ? this->RainUP(x, y) : this->RainDOWN(x, y); 
    lit++;
}

void Rain::TopFull(uint8_t x, uint8_t y){
    up == true ? this->set(x,y,3,4,0,0) : this->set(x,y,0,0,0,4);
}