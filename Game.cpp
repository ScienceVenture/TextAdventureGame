#include "Game.h"

void Game::state_machine(){

    Space * current_space = this->game_model->get_current_space(); 

    uint8_t button = this->display->read_button(); 

    if(current_space->get_id() == 7){

        this->display->say("You Win!");

    }else{

        this->display->say(current_space->get_name());

        if(button == BUTTON_UP){

            this->game_model->move_north();

        }


    }
}