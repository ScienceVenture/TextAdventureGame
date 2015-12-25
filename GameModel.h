#ifndef GAME_MODEL_H
#define GAME_MODEL_H

#include <Arduino.h>
#include "Map.h"


class GameModel {

    private:

        Map * map; 

        Space * current_space; 

    public:

        GameModel();

        Map * build_map(); 

        Space * get_current_space();
};


#endif // GAME_MODEL_H
