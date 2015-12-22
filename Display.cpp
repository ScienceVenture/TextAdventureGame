#include "Display.h"

Display::Display(uint8_t width, uint8_t height){

    this->disp_width = width;
    this->disp_height = height; 

    // Configure Liquid Crystal display as per: 
    //      https://www.arduino.cc/en/Reference/LiquidCrystalConstructor
    // 
    this->lcd = new LiquidCrystal(8,9,4,5,6,7);

    this->lcd->begin(this->disp_width, this->disp_height);

    this->lcd->clear();

    this->lcd->noAutoscroll();

    this->counter = 0; 

}

void Display::update(){
    this->write(); 
}

void Display::set_message(char s[], uint8_t len){

    strcpy(this->message, s); 

    if(len > this->disp_width){

        //pad the message with spaces for scrolling...

        uint8_t i = 0; 

        for(i = 0; i < this->disp_width; i++){
            this->message[len+i] = ' ';
        }
        this->message_length = len + i; 
        this->message[this->message_length] ='\0'; 

    }else{

        this->message_length = len; 

    }

}

void Display::write(){

    this->lcd->clear();

    // Handle case where message fits within the screen size.
    //
    if(this->message_length < this->disp_width){

        this->lcd->setCursor(0,0);
        this->lcd->print(this->message);

    }else{ 

        // Case where message must scroll to be shown.

        uint8_t i = 0,message_start = 0; 

        if(this->counter >= this->message_length){
            this->counter = 0; 
            return;
        }

        if(this->counter <= this->disp_width){
            this->lcd->setCursor(this->disp_width - this->counter, 0);
            message_start = 0; 

        }else{
            this->lcd->setCursor(0,0);
            message_start = this->counter - this->disp_width;
        }

        for(i = message_start; i < this->counter; i++){
            this->lcd->write(this->message[i]);
        }

        counter++;

    }
    
}