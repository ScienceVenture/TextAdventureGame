#include "Map.h"

/* Map */

Map::Map(){

    this->num_spaces = 0; 

}

Space * Map::add_space(const char name[]){

    Space * tmp = &(this->spaces[this->num_spaces]);

    tmp->init(); 
    tmp->set_name(name);

    this->num_spaces++; 

    return tmp; 
}

void Map::set_root(Space * s){

    this->root_space = s; 

}

Space * Map::get_root(){
    return this->root_space; 
}

/* End Map */ 

/* Space */ 

Space::Space(){

}

Space * Space::get_adjacent(uint8_t index){

    if(index >= this->adjacent_spaces_count || index >= MAX_ADJ_SPACES) return NULL;

    return this->adjacent_spaces[index];

}

void Space::set_name(const char S[]){

    strcpy(this->name, S);

}

char * Space::get_name(){
    return this->name; 
}

void Space::add_adjacent(Space * dest){

    this->adjacent_spaces[this->adjacent_spaces_count] = dest;
    this->adjacent_spaces_count++;

}

void Space::init(){

    this->adjacent_spaces_count = 0; 

}

/* End Space */

/* Object */ 

Object::Object(){

}

/* End Object */