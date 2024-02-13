#include "setup.hpp"

void setup(){
    Serial.begin(115200);

    pinMode(l1_pin, OUTPUT);
    pinMode(l2_pin, OUTPUT);
    pinMode(l3_pin, OUTPUT);
    pinMode(l4_pin, OUTPUT);

    pinMode(clk_pin, OUTPUT);
    pinMode(le_pin, OUTPUT);
    pinMode(sdi_pin, OUTPUT);

    pinMode(oe_red_1, OUTPUT);
    pinMode(oe_red_2, OUTPUT);
    pinMode(oe_green_1, OUTPUT);
    pinMode(oe_green_2, OUTPUT);
    pinMode(oe_blue_1, OUTPUT);
    pinMode(oe_blue_2, OUTPUT);

    pinMode(touch_pin_1, INPUT);
    pinMode(touch_pin_2, INPUT);
    pinMode(touch_pin_3, INPUT);

    pinMode(sdo_pin, INPUT);

    //-----TIMER 0 -----// updates every 800us = 0.8 ms ==> 1.25 times per ms
    Timer0_Cfg = timerBegin(0, 80, true); //ticks up every 80 clock cycles
    timerAttachInterrupt(Timer0_Cfg, &Timer0_ISR, true);
    timerAlarmWrite(Timer0_Cfg, 800, true); //triggers interrupt function every 800 ticks (min 400)
    timerAlarmEnable(Timer0_Cfg);

    //-----TIMER 1 -----// updates every 1000us = 1 ms 
    RunTimer1 = timerBegin(1, 80, true); //ticks up every 80 clock cycles
    timerAttachInterrupt(RunTimer1, &RunTimer1_ISR, true);
    timerAlarmWrite(RunTimer1, 1000, true); //triggers interrupt function every 1000 ticks
    timerAlarmEnable(RunTimer1);

    

    digitalWrite(clk_pin, true);

    //reset all registers
    for(uint8_t i = 0; i < 6; i++){
        shiftOut(sdi_pin, clk_pin, MSBFIRST, 0x00);
    }
}

uint8_t layer = 0;
void loop(){

    //led.rain();
    //led.small_cube();
    //launch.RFirework();
<<<<<<< HEAD

    //rain.rain();
    //tardis.tardis();
    spiral.spiral();
=======
    rain.rain();
>>>>>>> origin/master


    // red.reset();
    // green.reset();
    // blue.reset();

    // load_O((4 - layer) % 4);
    // load_M((5 - layer) % 4);
    // load_A((6 - layer) % 4);
    // load_R((7 - layer) % 4);

    // layer == 3 ? layer = 0 : layer++;

    // delay(1000);
}


void load_O(uint8_t layer, bool horizontal){
    uint8_t b = 4 - layer;

    int8_t layout[4][4] = {{0, b, b, 0},
                           {b, 0, 0, b},
                           {b, 0, 0, b},
                           {0, b, b, 0}};
    
    for(uint8_t i = 0; i < 4; i++){
        for(uint8_t col = 0; col < 4; col++){
            // red.getLevel(horizontal ? layer : i)[horizontal ? i : 3][col] = layout[i][col];
            // green.getLevel(horizontal ? layer : i)[horizontal ? i : 3][col] = layout[i][col];
            blue.getLevel(horizontal ? layer : i)[horizontal ? i : 3][col] = layout[i][col];
        }
    }
}

void load_M(uint8_t layer, bool horizontal){
    uint8_t b = 4 - layer;

    int8_t layout[4][4] = {{b, 0, 0, b},
                           {b, b, b, b},
                           {b, 0, 0, b},
                           {b, 0, 0, b}};
    
    for(uint8_t i = 0; i < 4; i++){
        for(uint8_t col = 0; col < 4; col++){
            red.getLevel(horizontal ? layer : i)[horizontal ? i : 3][col] = layout[i][col];
            // green.getLevel(horizontal ? layer : i)[horizontal ? i : 3][col] = layout[i][col];
            // blue.getLevel(horizontal ? layer : i)[horizontal ? i : 3][col] = layout[i][col];
        }
    }
}

void load_A(uint8_t layer, bool horizontal){
    uint8_t b = 4 - layer;

    int8_t layout[4][4] = {{0, b, b, 0},
                           {b, 0, 0, b},
                           {b, b, b, b},
                           {b, 0, 0, b}};
    
    for(uint8_t i = 0; i < 4; i++){
        for(uint8_t col = 0; col < 4; col++){
            // red.getLevel(horizontal ? layer : i)[horizontal ? i : 3][col] = layout[i][col];
            green.getLevel(horizontal ? layer : i)[horizontal ? i : 3][col] = layout[i][col];
            // blue.getLevel(horizontal ? layer : i)[horizontal ? i : 3][col] = layout[i][col];
        }
    }
}

void load_R(uint8_t layer, bool horizontal){
    uint8_t b = 4 - layer;
    int8_t layout[4][4] = {{0, b, b, 0},
                           {b, 0, 0, b},
                           {b, b, b, 0},
                           {b, 0, 0, b}};
    
    for(uint8_t i = 0; i < 4; i++){
        for(uint8_t col = 0; col < 4; col++){
            red.getLevel(horizontal ? layer : i)[horizontal ? i : 3][col] = layout[i][col];
            green.getLevel(horizontal ? layer : i)[horizontal ? i : 3][col] = layout[i][col];
            blue.getLevel(horizontal ? layer : i)[horizontal ? i : 3][col] = layout[i][col];
        }
    }
}

