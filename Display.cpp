#include "Display.h"

Display::Display(){

    this->disp_width = DISP_WIDTH;
    this->disp_height = DISP_HEIGHT; 

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

void Display::set_message(char s[], uint8_t len, uint8_t line){

    strcpy(this->message[line], s); 

    if(len > this->disp_width){

        //pad the message with spaces for scrolling...

        uint8_t i = 0; 

        for(i = 0; i < this->disp_width; i++){
            this->message[line][len+i] = ' ';
        }
        this->message_lengths[line] = len + i; 
        this->message[line][this->message_lengths[line]] ='\0'; 

    }else{

        this->message_lengths[line] = len; 

    }

}

void Display::write(){

    this->lcd->clear();

    uint8_t line = 0;
    for(line = 0; line < this->disp_height; line++){

        // Handle case where message fits within the screen size.
        //
        if(this->message_lengths[line] < this->disp_width){

            this->lcd->setCursor(0,line);
            this->lcd->print(this->message[line]);

        }else{ 

            // Case where message must scroll to be shown.

            uint8_t i = 0,message_start = 0; 

            if(this->counter >= this->message_lengths[line]){
                this->counter = 0; 
                return;
            }

            if(this->counter <= this->disp_width){
                this->lcd->setCursor(this->disp_width - this->counter, line);
                message_start = 0; 

            }else{
                this->lcd->setCursor(0,line);
                message_start = this->counter - this->disp_width;
            }

            for(i = message_start; i < this->counter; i++){
                this->lcd->write(this->message[line][i]);
            }


        }

    }

    counter++;

    
}