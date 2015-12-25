#include "GameDisplay.h"

GameDisplay::GameDisplay(){

    this->display = new Display();

}

void GameDisplay::error(const char * S){

    this->display->error((char *) S);

}

void GameDisplay::say(const char * S){

    this->display->set_message((char *) S, strlen(S), 0);

}

void GameDisplay::ask_input(const char * S){
    this->display->set_message((char * ) S, strlen(S), 1);
}