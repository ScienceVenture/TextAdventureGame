#include "GameModel.h"

GameModel::GameModel(){

    this->map = new Map(); 
    this->current_space = this->map->get_root(); 

}

Map * GameModel::build_map(){

    //Implement map layout here.... 

    // 1) Create spaces...
    //
    Space * space_1 = this->map->add_space("Space One");
    Space * space_2 = this->map->add_space("Space Two");
    Space * space_3 = this->map->add_space("Space Three");

    if(space_1 == NULL || space_2 == NULL || space_3 == NULL) return NULL; 

    // 2) Connect spaces
    //
    space_1->add_adjacent(space_2);
    space_1->add_adjacent(space_3);

    // 3) Set the map root. 
    //
    this->map->set_root(space_1);
    this->current_space = this->map->get_root(); 

    return this->map;
}

Space * GameModel::get_current_space(){
    return this->current_space; 
}