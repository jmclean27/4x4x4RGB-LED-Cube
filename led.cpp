#include "led.hpp"
#include <Arduino.h>
//#include "setup.hpp"

LED::LED(cube& r, cube& g, cube& b): red(r), green(g), blue(b){

}

LED::~LED(){

}

void LED::set(uint8_t x, uint8_t y, uint8_t z, uint8_t r,  uint8_t g, uint8_t b){
    red[z][y][x] = r;
    green[z][y][x] = g;
    blue[z][y][x] = b;
}

void LED::SmallCube(uint8_t x, uint8_t y, uint8_t z, uint8_t r,  uint8_t g, uint8_t b){

    this->set(x+0,y+0,z+0,r,g,b);
    this->set(x+0,y+1,z+0,r,g,b);
    this->set(x+1,y+0,z+0,r,g,b);
    this->set(x+1,y+1,z+0,r,g,b);
    this->set(x+0,y+0,z+1,r,g,b);
    this->set(x+0,y+1,z+1,r,g,b);
    this->set(x+1,y+0,z+1,r,g,b);
    this->set(x+1,y+1,z+1,r,g,b);
}

void LED::rain(){
    //unsigned long STick1 = tick1;
        
    // this->set(2,2,3,1,1,4);
    // if (STick1+250 == tick1) 
    // this->set(2,2,3,0,0,0);

    this->set(2,2,4,4,0,0);
    delay(40);
    delay(40);
    delay(40);
    this->set(2,3,4,4,4,0);
    this->set(3,2,4,4,4,0);
    delay(40);
    this->set(2,1,4,4,4,0);
    this->set(3,2,4,3,2,0);
    delay(40);
    this->set(2,2,4,3,0,0);
    this->set(3,2,4,1,0,0);
    delay(40);
    this->set(2,3,4,4,3,0);
    this->set(2,1,4,4,3,0);
    this->set(3,2,4,0,0,0);
    delay(40);
    delay(40);
    this->set(2,1,4,3,1,0);
    delay(40);
    this->set(1,2,4,4,4,0);
    this->set(2,3,4,3,1,0);
    this->set(2,2,4,2,0,0);
    delay(40);
    this->set(2,1,4,2,0,0);
    delay(40);
    delay(40);
    this->set(1,2,4,4,3,0);
    this->set(2,3,4,2,0,0);
    this->set(2,1,4,1,0,0);
    this->set(2,2,4,1,0,0);
    delay(40);
    delay(40);
    this->set(2,1,4,0,0,0);
    this->set(2,2,4,0,0,0);
    delay(40);
    this->set(1,2,4,3,1,0);
    this->set(2,3,4,1,0,0);
    delay(40);
    delay(40);
    delay(40);
    this->set(1,2,4,2,0,0);
    this->set(2,3,4,0,0,0);
    delay(40);
    delay(40);
    this->set(3,2,4,4,4,0);
    delay(40);
    this->set(3,2,4,4,3,0);
    this->set(1,2,4,1,0,0);
    delay(40);
    this->set(3,2,4,3,1,0);
    this->set(1,2,4,4,3,0);
    delay(40);
    this->set(3,2,4,2,0,0);
    delay(40);
    this->set(3,2,4,4,4,0);
    this->set(1,2,4,3,1,0);
    this->set(1,2,4,0,0,0);
    delay(40);
    this->set(3,2,4,1,0,0);
    delay(40);
    this->set(3,2,4,0,0,0);
    this->set(1,2,4,2,0,0);
    delay(40);
    delay(40);
    this->set(1,2,4,1,0,0);
    delay(40);
    delay(40);
    this->set(1,2,4,0,0,0);
    delay(40);
    delay(40);
    
}

void LED::small_cube(){
    for(int i = 0; i < 3; i++){
        this->SmallCube(2-i,2-i,i,4,0,0);
        delay(200);
        this->SmallCube(2-i,2-i,i,0,0,0);
    }
    for(int i = 2; i > -1; i--){
        this->SmallCube(0,2-i,i,0,0,4);
        delay(200);
        this->SmallCube(0,2-i,i,0,0,0);
    }
    for(int i = 0; i <3; i++){
        this->SmallCube(i,2-i,0,0,2,2);
        delay(200);
        this->SmallCube(i,2-i,0,0,0,0);
    }



// void LED::small_cube(){
//     for(int i = 0; i < 3; i++){
//         this->set(3-i,3-i,i,4,0,0);
//         this->set(3-i,2-i,i,4,0,0);
//         this->set(2-i,3-i,i,4,0,0);
//         this->set(2-i,2-i,i,4,0,0);
//         this->set(3-i,3-i,i+1,4,0,0);
//         this->set(3-i,2-i,i+1,4,0,0);
//         this->set(2-i,3-i,i+1,4,0,0);
//         this->set(2-i,2-i,i+1,4,0,0);
//         delay(200);
//         this->set(3-i,3-i,i,0,0,0);
//         this->set(3-i,2-i,i,0,0,0);
//         this->set(2-i,3-i,i,0,0,0);
//         this->set(2-i,2-i,i,0,0,0);
//         this->set(3-i,3-i,i+1,0,0,0);
//         this->set(3-i,2-i,i+1,0,0,0);
//         this->set(2-i,3-i,i+1,0,0,0);
//         this->set(2-i,2-i,i+1,0,0,0);
//     }
//     for(int i = 2; i > -1; i--){
//         this->set(1,3-i,i,0,0,4);
//         this->set(1,2-i,i,0,0,4);
//         this->set(0,3-i,i,0,0,4);
//         this->set(0,2-i,i,0,0,4);
//         this->set(1,3-i,i+1,0,0,4);
//         this->set(1,2-i,i+1,0,0,4);
//         this->set(0,3-i,i+1,0,0,4);
//         this->set(0,2-i,i+1,0,0,4);
//         delay(200);
//         this->set(1,3-i,i,0,0,0);
//         this->set(1,2-i,i,0,0,0);
//         this->set(0,3-i,i,0,0,0);
//         this->set(0,2-i,i,0,0,0);
//         this->set(1,3-i,i+1,0,0,0);
//         this->set(1,2-i,i+1,0,0,0);
//         this->set(0,3-i,i+1,0,0,0);
//         this->set(0,2-i,i+1,0,0,0);
//     }

//         for(int i = 0; i <3; i++){
//             // for(int j = 0; j <1000; j++){
//                 // this->set(i+1,3-i,0+0,0,j%4,(j+2)%4);
//                 // this->set(i+1,2-i,0+0,0,j%4,(j+2)%4);
//                 // this->set(i+0,3-i,0+0,0,j%4,(j+2)%4);
//                 // this->set(i+0,2-i,0+0,0,j%4,(j+2)%4);
//                 // this->set(i+1,3-i,0+1,0,j%4,(j+2)%4);
//                 // this->set(i+1,2-i,0+1,0,j%4,(j+2)%4);
//                 // this->set(i+0,3-i,0+1,0,j%4,(j+2)%4);
//                 // this->set(i+0,2-i,0+1,0,j%4,(j+2)%4);
//                 // delayMicroseconds(100);
//             // }
//             this->set(i+1,3-i,0+0,0,2,2);
//             this->set(i+1,2-i,0+0,0,2,2);
//             this->set(i+0,3-i,0+0,0,2,2);
//             this->set(i+0,2-i,0+0,0,2,2);
//             this->set(i+1,3-i,0+1,0,2,2);
//             this->set(i+1,2-i,0+1,0,2,2);
//             this->set(i+0,3-i,0+1,0,2,2);
//             this->set(i+0,2-i,0+1,0,2,2);
//          delay(200);
//         this->set(i+1,3-i,0+0,0,0,0);
//         this->set(i+1,2-i,0+0,0,0,0);
//         this->set(i+0,3-i,0+0,0,0,0);
//         this->set(i+0,2-i,0+0,0,0,0);
//         this->set(i+1,3-i,0+1,0,0,0);
//         this->set(i+1,2-i,0+1,0,0,0);
//         this->set(i+0,3-i,0+1,0,0,0);
//         this->set(i+0,2-i,0+1,0,0,0);
//     }
    

}