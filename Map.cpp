#include "Map.h"

/* Map */

Map::Map(){
    this->num_spaces = 0; 
    this->root_space = NULL;
}

Space * Map::add_space(const char name[], uint8_t id){

    Space * tmp = &(this->spaces[this->num_spaces]);

    tmp->init(); 
    tmp->set_name(name);
    tmp->set_id(id);

    this->num_spaces++; 

    return tmp; 
}

/**
* Picks the lowest numerical ID that is not in use. 
*/
Space * Map::add_space(const char name[]){

    Space * tmp = &(this->spaces[this->num_spaces]);

    tmp->init(); 
    tmp->set_name(name);

    int8_t id = this->find_unused_id(); 

    if(id == -1){
        return NULL;
    }else{
        tmp->set_id((uint8_t)id);
    }

    this->num_spaces++; 

    return tmp; 
}

int8_t Map::find_unused_id(){

    uint8_t i = 0, j = 0; 
    for(i = 0; i < MAX_SPACES; i++){
        for(j = 0; j < MAX_SPACES; j++){
            if(this->spaces[j].get_id() != i){
                return i; 
            }
        }
    }

    return -1;
}

void Map::set_root(Space * s){

    this->root_space = s; 

}

Space * Map::get_root(){
    return this->root_space; 
}
/* End Map */ 

/* Space */ 

Space::Space(){}

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

uint8_t Space::get_id(){
    return this->space_id;
}

void Space::set_id(uint8_t id){
    this->space_id = id;
}

void Space::init(){

    this->adjacent_spaces_count = 0; 
    this->space_id = 0; 

}

/* End Space */

/* Object */ 

Object::Object(){}

/* End Object */