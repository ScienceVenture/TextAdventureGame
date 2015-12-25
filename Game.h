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

        Game(GameModel * gm, GameDisplay * d);

        void state_machine(); 

    private:

        GameDisplay * display; 
        GameModel * game_model; 

};

#endif // GAME_H
