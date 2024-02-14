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


void Tardis::tardis(){
    if(!step){
        this->DisplayCube(xyz[0][0], xyz[0][1], xyz[0][2]);
        start_time = *ti;
        step = true;
        return;
    }
    if(*ti - start_time < speed) return;
    start_time = *ti;
    this->Flash();
    this->HideCube(xyz[0][0], xyz[0][1], xyz[0][2]);
    this->MoveCube();
    this->DisplayCube(xyz[0][0], xyz[0][1], xyz[0][2]);
    this->CheckBump();
}


void Tardis::CheckBump(){
    bool bump = false;
    for(uint8_t i = 0; i < 3; i++){
        if(xyz[0][i] == 2){
            xyz[1][i] = 0;
            bump = true;
        }  
        if(xyz[0][i] == 0){
            xyz[1][i] = 1;
            bump = true;
        } 
    }
    if(bump) RandDir();
}


void Tardis::MoveCube(){
    for(uint8_t i = 0; i < 3; i++){
        xyz[1][i] == 1 ? xyz[0][i] += xyz[2][i] : xyz[0][i] -= xyz[2][i];
    }
}


void Tardis::DisplayCube(uint8_t x, uint8_t y, uint8_t z){
    for(uint8_t i = 0; i < 2; i++){
        for(uint8_t j = 0; j < 2; j++){
            this->set(x+j,y+0,z+i,0,0,4);
            this->set(x+j,y+1,z+i,0,0,4);
        }
    }
}


void Tardis::HideCube(uint8_t x, uint8_t y, uint8_t z){
    for(uint8_t i = 0; i < 2; i++){
        for(uint8_t j = 0; j < 2; j++){
            this->set(x+j,y+0,z+i,0,0,0);
            this->set(x+j,y+1,z+i,0,0,0);
        }
    }
}


void Tardis::RandDir(){
    do{
        for(uint8_t i = 0; i < 3; i++) xyz[2][i] = rand() % 2;
    }
    while(xyz[2][0] + xyz[2][1] + xyz[2][2] == 0);
}


void Tardis::Flash(){
    uint8_t xyzF[3];
    do{
        for(uint8_t i = 0; i < 3; i++){
            xyzF[i] = rand() % 4;
        }
    }while(this->FlashCrash(xyzF[0], xyzF[1], xyzF[2]));

    uint8_t brightLight = rand() % 3;
    this->set(xyzF[0], xyzF[1], xyzF[2], 2 - brightLight, brightLight, 0);
}


bool Tardis::FlashCrash(uint8_t x, uint8_t y, uint8_t z){
    if(x != xyz[0][0] && x != xyz[0][0]+1) return false;
    if(y != xyz[0][1] && x != xyz[0][1]+1) return false;
    if(z != xyz[0][2] && x != xyz[0][2]+1) return false;
    
    return true;
}






