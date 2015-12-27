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

    uint8_t i = 0; 

    for(i = 0; i < this->disp_height; i++){

        this->message_lengths[i] = 0; 
        this->message[i][0] = '\0';

    }

}

void Display::update(){
    this->write(); 
}

/*
uint8_t Display::read_button(){

    int adc_key_in = analogRead(0); 

    if (adc_key_in > 1000) return NO_BUTTON; 
    if (adc_key_in < 50)   return BUTTON_RIGHT;  
    if (adc_key_in < 250)  return BUTTON_UP; 
    if (adc_key_in < 450)  return BUTTON_DOWN; 
    if (adc_key_in < 650)  return BUTTON_LEFT; 
    if (adc_key_in < 850)  return BUTTON_SELECT;  

    return NO_BUTTON;

}
*/

uint8_t Display::read_button(){

    // returns which ever button is currently pressed. 
    uint8_t button = this->_read_button(); 

    // rising edge sensitive to buttons. 
    // only returns if the button was just pressed. 
    if(buttonJustPressed == true){

        buttonJustPressed = false; 
        return button; 

    }else{

        return BUTTON_NONE;

    }

}

uint8_t Display::_read_button() {

   unsigned int buttonVoltage;
   uint8_t button = BUTTON_NONE;   // return no button pressed if the below checks don't write to btn
   
   //read the button ADC pin voltage
   buttonVoltage = analogRead( BUTTON_ADC_PIN );
   //sense if the voltage falls within valid voltage windows
   if( buttonVoltage < ( RIGHT_10BIT_ADC + BUTTON_TOLERANCE ) )
   {
      button = BUTTON_RIGHT;
   }
   else if(   buttonVoltage >= ( UP_10BIT_ADC - BUTTON_TOLERANCE )
           && buttonVoltage <= ( UP_10BIT_ADC + BUTTON_TOLERANCE ) )
   {
      button = BUTTON_UP;
   }
   else if(   buttonVoltage >= ( DOWN_10BIT_ADC - BUTTON_TOLERANCE )
           && buttonVoltage <= ( DOWN_10BIT_ADC + BUTTON_TOLERANCE ) )
   {
      button = BUTTON_DOWN;
   }
   else if(   buttonVoltage >= ( LEFT_10BIT_ADC - BUTTON_TOLERANCE )
           && buttonVoltage <= ( LEFT_10BIT_ADC + BUTTON_TOLERANCE ) )
   {
      button = BUTTON_LEFT;
   }
   else if(   buttonVoltage >= ( SELECT_10BIT_ADC - BUTTON_TOLERANCE )
           && buttonVoltage <= ( SELECT_10BIT_ADC + BUTTON_TOLERANCE ) )
   {
      button = BUTTON_SELECT;
   }
   //handle button flags for just pressed and just released events
   if( ( buttonWas == BUTTON_NONE ) && ( button != BUTTON_NONE ) )
   {
      //the button was just pressed, set buttonJustPressed, this can optionally be used to trigger a once-off action for a button press event
      //it's the duty of the receiver to clear these flags if it wants to detect a new button change event
      buttonJustPressed  = true;
      buttonJustReleased = false;
   }
   if( ( buttonWas != BUTTON_NONE ) && ( button == BUTTON_NONE ) )
   {
      buttonJustPressed  = false;
      buttonJustReleased = true;
   }
   
   //save the latest button value, for change event detection next time round
   buttonWas = button;
   
   return( button );
}

void Display::error(char s[]){
    this->set_message(s, strlen(s), 0);
    this->set_message((char *)EMPTY_STRING, 0, 1);
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