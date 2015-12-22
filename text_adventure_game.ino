#include <LiquidCrystal.h>
#include "scheduler.h"
#include "Display.h"

#define DISP_WIDTH 16
#define DISP_HEIGHT 2

uint32_t idle_period; 

Display * display = NULL; 

void display_update_wrapper(){

    display->update(); 

}

uint16_t i = 0; 
char S1[20] = "the quick brown fox";
char S2[6] = "hello";

void text_changer(){

    if(i == 0){

        display->set_message(S1,19,0);
        display->set_message(S2,5,1);

    }else if(i == 10){

        display->set_message(S2,5,0);
        display->set_message(S1,19,1);

    }

    if(i > 20){

        i = 0;  

    }else{
        i++;
    }

}


void setup(){

    display = new Display();

    scheduler_init();

    scheduler_start_task(0, 250, display_update_wrapper);
    scheduler_start_task(50, 250, text_changer);

    //display->set_message(S1,19);

}

void loop(){

    idle_period = scheduler_dispatch(); 

    if(idle_period){
        idle(idle_period); 
    }

}
