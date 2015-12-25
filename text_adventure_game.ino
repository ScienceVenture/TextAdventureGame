#include <LiquidCrystal.h>
#include "scheduler.h"
#include "GameDisplay.h"
#include "GameModel.h"
#include "Game.h"
#include "Error.h"

// Global variables 
//
GameDisplay * display = NULL; 
GameModel * GM = NULL;
Game * G = NULL;

void display_update_wrapper(){
    display->update(); 
}

void game_loop(){
    G->state_machine(); 
}


void setup(){

    // DO NOT CHANGE THIS CODE

    GM = new GameModel();  // Model
    GM->build_map(); 
    display = new GameDisplay(); // View
    G = new Game(GM, display); // Control

    scheduler_init();
    scheduler_start_task(0, 200, display_update_wrapper);
    scheduler_start_task(50, 100, game_loop);

}

void loop(){

    // DO NOT CHANGE THIS CODE

    uint32_t idle_period = scheduler_dispatch(); 

    if(idle_period)
        idle(idle_period); 
}
