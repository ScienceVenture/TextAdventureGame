#ifndef GAME_DISPLAY_INCLUDE
#define GAME_DISPLAY_INCLUDE

#include "Display.h"

class GameDisplay{

    public:
        GameDisplay();

        void error(const char * S);

        void say(const char * S);

        void update(){
            this->display->update();
        }

    private:
        
        Display * display;

};

#endif