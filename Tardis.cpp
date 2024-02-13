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


<<<<<<< HEAD
void Tardis::tardis(){
    if(!step){
        this->DisplayCube(xyz[0][0], xyz[0][1], xyz[0][2]);
        start_time = *ti;
        step++;
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
=======
void Tardis::tardis(uint8_t x, uint8_t y, uint8_t z){
    if(step == 0){
        this->MoveCube(rand() %3, rand() %3, rand () %3);
        start_time = *ti;
        rand();
        step++;
    }

}


void Tardis::MoveCube(uint8_t x, uint8_t y, uint8_t z){
>>>>>>> origin/master
    for(uint8_t i = 0; i < 2; i++){
        for(uint8_t j = 0; j < 2; j++){
            this->set(x+j,y+0,z+i,0,0,4);
            this->set(x+j,y+1,z+i,0,0,4);
        }
    }
}


<<<<<<< HEAD
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
    // }while(this->FlashCrash(xyzF[0], xyzF[1], xyzF[2]));
    }while(false);

    uint8_t brightLight = rand() % 3;
    this->set(xyzF[0], xyzF[1], xyzF[2], 2 - brightLight, brightLight, 0);
}


bool Tardis::FlashCrash(uint8_t x, uint8_t y, uint8_t z){
    bool check = false;
    if(x >= xyz[0][0] && x <= xyz[0][0]+1) check = true;
    if(y >= xyz[0][1] && x <= xyz[0][1]+1) check = true;
    if(z >= xyz[0][2] && x <= xyz[0][2]+1) check = true;
    return check;
}






=======
void Tardis::RandDir(){
    QDir = rand() % 8;
}


void Tardis::bump(){

}

>>>>>>> origin/master
