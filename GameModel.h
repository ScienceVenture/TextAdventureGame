#ifndef GAME_MODEL_H
#define GAME_MODEL_H

#include <Arduino.h>
#include "Map.h"


class GameModel {

    private:

        Map * map; 

    public:

        GameModel();

        Map * build_map(); 
};


#endif // GAME_MODEL_H
