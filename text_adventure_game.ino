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

void setup(){

    display = new Display(DISP_WIDTH, DISP_HEIGHT);

    scheduler_init();

    scheduler_start_task(0, 100, display_update_wrapper);

}

void loop(){

    idle_period = scheduler_dispatch(); 

    if(idle_period){
        idle(idle_period); 
    }

}
