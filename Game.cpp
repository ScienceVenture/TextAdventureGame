#include "Game.h"

void Game::build_map(){

    //Implement map layout here.... 

    // 1) Create spaces...
    //
    Space * start = add_space("Start", 0);
    Space * space_1 = add_space("Room 1", 1);
    Space * space_2 = add_space("Room 2", 2);
    Space * space_3 = add_space("Room 3", 3);
    Space * space_4 = add_space("Room 4", 4);
    Space * space_5 = add_space("Room 5", 5);
    Space * space_6 = add_space("Room 6", 6);
    Space * end = add_space("End", 7);

    // 2) Connect spaces
    //
    connect(start, space_1, NORTH);
    connect(space_1, space_2, NORTH);
    connect(space_2, space_3, NORTH);
    connect(space_3, space_4, NORTH);
    connect(space_4, space_5, NORTH);
    connect(space_5, space_6, NORTH);
    connect(space_6, end, NORTH);

    // 3) Set the map root, i.e. the start of the game. 
    //
    set_start(start);

}

void Game::state_machine(){

    uint8_t button = display->read_button(); 

    Space * current_space = player->get_current_space(); 

    if(current_space->get_id() == 7){

        display->say("You Win!");

    }else{

        display->say(current_space->get_name());

        if(button == BUTTON_UP){

            player->move_north();

        }

    }
}