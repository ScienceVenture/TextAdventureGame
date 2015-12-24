#include <LiquidCrystal.h>
#include "scheduler.h"
#include "Display.h"
#include "GameModel.h"
#include "Map.h"

#define DISP_WIDTH 16
#define DISP_HEIGHT 2

uint32_t idle_period; 

Display * display = NULL; 
GameModel * G;
Map * game_map; 

char testy[100];

void display_update_wrapper(){

    display->update(); 

}

uint16_t i = 0; 
char S1[20] = "the quick brown fox";
char S2[6] = "hello";
char ERROR_MSG_1[8] = "ERROR 1";
char ERROR_MSG_2[8] = "ERROR 2";
char ERROR_MSG_3[8] = "ERROR 3";


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

void game_loop(){
    
}


void setup(){

    G = new GameModel(); 

    display = new Display();

    game_map = G->build_map(); 

    scheduler_init();

    scheduler_start_task(0, 250, display_update_wrapper);
    scheduler_start_task(50, 250, game_loop);


    Space * root = game_map->get_root(); 
    char * M = root->get_name(); 

    char * P = root->get_adjacent(0)->get_name();

    if(game_map == NULL){

        display->set_message(ERROR_MSG_2, 7, 0);

    }else if(M == NULL){

        display->set_message(ERROR_MSG_3, 7, 0);

    }else if(P == NULL){

        display->set_message(ERROR_MSG_1, 7, 0);

    }else{

        display->set_message(M, strlen(M), 0);
        display->set_message(P, strlen(P), 1);

    }

    //display->set_message(M, 7, 0);
    //display->set_message(S1,19,0);
    //display->set_message(S2,5,1);

}

void loop(){

    idle_period = scheduler_dispatch(); 

    if(idle_period){
        idle(idle_period); 
    }

}
