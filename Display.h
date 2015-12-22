#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <LiquidCrystal.h>

class Display{

    public: 
        Display(uint8_t width, uint8_t height);

        //force a display update
        void update();


    private: 
        
        //private member attributes
        //
        uint8_t disp_width;
        uint8_t disp_height;

        uint32_t counter;

        LiquidCrystal * lcd;

        //private member functions
        //
        void write();

};

#endif 
