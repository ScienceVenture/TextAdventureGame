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

        uint8_t read_button(){
            return this->display->read_button(); 
        }

        void ask_input(const char * S);

    private:
        
        Display * display;

};

#endif