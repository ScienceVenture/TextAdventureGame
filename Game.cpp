#include "Game.h"

Game::Game(GameModel * gm, GameDisplay * d){

    this->game_model = gm;  
    this->display = d; 

}

void Game::state_machine(){

    Space * current_space = this->game_model->get_current_space(); 

    switch(current_space->get_id()){

        case 0:
            this->display->say(current_space->get_name());
            break;
        case 1:
            break; 
        case 2:
            break;
        default:
            this->display->error(ERROR_NO_CASE);
            break;

    }

}