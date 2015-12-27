#ifndef DISPLAY_H
#define DISPLAY_H

#define DISP_WIDTH 16
#define DISP_HEIGHT 2

#define BUTTON_NONE 0 
#define BUTTON_SELECT 1
#define BUTTON_UP 2
#define BUTTON_DOWN 3
#define BUTTON_LEFT 4
#define BUTTON_RIGHT 5

#define RIGHT_10BIT_ADC           0  // right
#define UP_10BIT_ADC            155  // up
#define DOWN_10BIT_ADC          360  // down
#define LEFT_10BIT_ADC          565  // left
#define SELECT_10BIT_ADC        845  // right
#define BUTTON_TOLERANCE         50  // allow range for clicks 

#define BUTTON_ADC_PIN 0 //connected to pin 0

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

        uint8_t read_button(); 
        uint8_t _read_button(); 

    private: 

        //private member attributes
        //
        uint8_t disp_width;
        uint8_t disp_height;

        char message[DISP_HEIGHT][128];
        uint8_t message_lengths[DISP_HEIGHT];

        uint32_t counter;

        bool buttonJustReleased; 
        bool buttonJustPressed; 
        uint8_t buttonWas; 

        LiquidCrystal * lcd;

        //private member functions
        //
        void write();

};

#endif 
