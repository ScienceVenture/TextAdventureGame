#ifndef DISPLAY_H
#define DISPLAY_H

#define DISP_WIDTH 16
#define DISP_HEIGHT 2

#include <Arduino.h>
#include <LiquidCrystal.h>
#include "Error.h"

class Display{

    public: 
        Display();

        //force a display update
        void update();

        void set_message(char s[], uint8_t len, uint8_t line);

        void error(char s[]);

    private: 

        //private member attributes
        //
        uint8_t disp_width;
        uint8_t disp_height;

        char message[DISP_HEIGHT][128];
        uint8_t message_lengths[DISP_HEIGHT];

        uint32_t counter;

        LiquidCrystal * lcd;

        //private member functions
        //
        void write();

};

#endif 
