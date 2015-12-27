#include "Game.h"

void Game::state_machine(){

    Space * current_space = player->get_current_space(); 

    uint8_t button = display->read_button(); 

    if(current_space->get_id() == 7){

        display->say("You Win!");

    }else{

        display->say(current_space->get_name());

        if(button == BUTTON_UP){

            player->move_north();

        }


    }
}