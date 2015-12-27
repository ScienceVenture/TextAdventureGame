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
    start->add_adjacent(space_1);
    space_1->add_adjacent(space_2);
    space_2->add_adjacent(space_3);
    space_3->add_adjacent(space_4);
    space_4->add_adjacent(space_5);
    space_5->add_adjacent(space_6);
    space_6->add_adjacent(end);

    // 3) Set the map root, i.e. the start of the game. 
    //
    set_root(start);

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