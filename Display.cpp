#include "Display.h"

Display::Display(uint8_t width, uint8_t height){

    this->disp_width = width;
    this->disp_height = height; 

    // Configure Liquid Crystal display as per: 
    //      https://www.arduino.cc/en/Reference/LiquidCrystalConstructor
    // 
    this->lcd = new LiquidCrystal(8,9,4,5,6,7);

    this->counter = 0; 

}

void Display::update(){
    this->write(); 
}

void Display::write(){
    
    this->lcd->setCursor(0,0);

    if(this->counter < 10){

        this->lcd->print("Hello");
        this->counter++; 

    }else if(this->counter < 20){
 
        this->lcd->print("World");
        this->counter++; 

    }else{

        this->counter = 0; 

    }

}