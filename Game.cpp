#include "Game.h"

Game::Game(GameModel * gm, GameDisplay * d){

    this->game_model = gm;  
    this->display = d; 

}

void Game::state_machine(){

    Space * current_space = this->game_model->get_current_space(); 

    uint8_t button = this->display->read_button(); 

    switch(current_space->get_id()){

        case 1:
            this->display->say(current_space->get_name());

            this->display->ask_input("SELECT > Space Two");

            if(button == 1){

                Space * tmp = current_space->get_adjacent(0);

                this->game_model->change_space(tmp);

            }

            break;
        case 2:
            this->display->say(current_space->get_name());

            this->display->ask_input("SELECT > Space One");

            if(button == 1){

                Space * tmp = current_space->get_adjacent(0);

                this->game_model->change_space(tmp);

            }
            break; 
        case 3:
            this->display->say(current_space->get_name());
            break;
        default:
            this->display->error(ERROR_NO_CASE);
            break;

    }

}