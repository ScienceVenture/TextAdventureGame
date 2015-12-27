#ifndef GAME_MODEL_H
#define GAME_MODEL_H

#include <Arduino.h>
#include "Map.h"

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3


class GameModel {

    private:

        Map * map; 
        Space * current_space; 

        Map * build_map(); 

    public:

        GameModel(){
            this->map = new Map(); 
            this->current_space = this->map->get_root(); 
        }

        Space * get_current_space(){ return this->current_space; }

        void change_space(Space * s){ this->current_space = s; }

        void change_space(int i){ this->current_space = this->current_space->get_adjacent(i); }

        void move_north(){ this->change_space(NORTH); } 
        void move_east(){ this->change_space(EAST); } 
        void move_south(){ this->change_space(SOUTH); } 
        void move_west(){ this->change_space(WEST); } 

        Map * init(){
            Map * M = this->build_map(); 
            this->current_space = M->get_root(); 
            return M; 
        }

};

class Player {
    private:
        GameModel * M; 
    public: 

        Player(GameModel * m){
            this->M = m; 
        } 

        Space * get_current_space(){ return this->M->get_current_space(); }

        void move_north(){ this->M->move_north(); } 
        void move_east(){ this->M->move_east(); } 
        void move_south(){ this->M->move_south(); } 
        void move_west(){ this->M->move_west(); } 
};


#endif // GAME_MODEL_H
