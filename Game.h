#ifndef GAME_H
#define GAME_H

#include "GameModel.h"
#include "GameDisplay.h"
#include "Error.h"

/**
* Effectively the controller of the MVC framework.
*/
class Game{

    public:

        Game(GameModel * gm, GameDisplay * d){
            this->game_model = gm;  
            this->display = d;
            this->player = new Player(gm);
        };

        void state_machine(); 

        void init(){
            this->build_map(); 
            this->game_model->change_space(this->game_model->get_root()); 
        }

    private:

        GameDisplay * display; 
        GameModel * game_model; 

        Player * player; 

        // Private functions for building out a map. 
        // These functions forward calls to the GameModel 
        //

        // Called by the Game::init(); 
        void build_map(); 

        Space * add_space(const char * S, uint8_t id){ return this->game_model->add_space(S, id); }

        void set_root(Space * S){ this->game_model->set_root(S); }



};

#endif // GAME_H
