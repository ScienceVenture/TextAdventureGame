#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <LiquidCrystal.h>

class Display{

    public: 
        Display(uint8_t width, uint8_t height);

        //force a display update
        void update();

        void set_message(char s[], uint8_t len);


    private: 

        //private member attributes
        //
        uint8_t disp_width;
        uint8_t disp_height;

        char message[128];
        uint8_t message_length;

        uint32_t counter;

        LiquidCrystal * lcd;

        //private member functions
        //
        void write();

};

#endif 
