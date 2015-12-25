#include "GameModel.h"

/**
* This function builds the Map for the adventure game. 
*/
Map * GameModel::build_map(){

    //Implement map layout here.... 

    // 1) Create spaces...
    //
    Space * start = this->map->add_space("Start", 0);
    Space * space_1 = this->map->add_space("Room 1", 1);
    Space * space_2 = this->map->add_space("Room 2", 2);
    Space * space_3 = this->map->add_space("Room 3", 3);
    Space * space_4 = this->map->add_space("Room 4", 4);
    Space * space_5 = this->map->add_space("Room 5", 5);
    Space * space_6 = this->map->add_space("Room 6", 6);
    Space * end = this->map->add_space("End", 7);

    // 2) Connect spaces
    //
    start->add_adjacent(space_1);
    space_1->add_adjacent(space_2);
    space_2->add_adjacent(space_3);
    space_3->add_adjacent(space_4);
    space_4->add_adjacent(space_5);
    space_5->add_adjacent(space_6);
    space_6->add_adjacent(end);

    // 3) Set the map root. 
    //
    this->map->set_root(start);
    this->current_space = this->map->get_root(); 

    return this->map;
}

