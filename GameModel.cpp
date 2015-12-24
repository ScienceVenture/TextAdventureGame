#include "GameModel.h"

GameModel::GameModel(){

    this->map = new Map(); 

}

Map * GameModel::build_map(){

    //implement map layout here.... 

    Space * space_1 = this->map->add_space("Space One");
    Space * space_2 = this->map->add_space("Space Two");
    Space * space_3 = this->map->add_space("Space Three");

    if(space_1 == NULL || space_2 == NULL || space_3 == NULL){

        return NULL; 

    }

    space_1->add_adjacent(space_2);
    space_1->add_adjacent(space_3);

    this->map->set_root(space_1);

    return this->map;

}