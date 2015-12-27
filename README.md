# Text Adventure Game

A code based created for Science Venture's RetroGaming program. This framework will allow students to create a text based adventure game.

## Getting Started

There are two steps to getting a simple game started. A simple example is provided: 

**Step 1:** Define the map that will be used in the game. Fill out the `Game::build_map()` within `Game.cpp`. 

```
void Game::build_map(){
    Space * start = add_space("Start", 0);
    Space * space_1 = add_space("Room 1", 1);
    Space * space_2 = add_space("Room 2", 2);
    Space * space_3 = add_space("Room 3", 3);
    Space * space_4 = add_space("Room 4", 4);
    Space * space_5 = add_space("Room 5", 5);
    Space * space_6 = add_space("Room 6", 6);
    Space * end = add_space("End", 7);
    connect(start, space_1, NORTH);
    connect(space_1, space_2, NORTH);
    connect(space_2, space_3, NORTH);
    connect(space_3, space_4, NORTH);
    connect(space_4, space_5, NORTH);
    connect(space_5, space_6, NORTH);
    connect(space_6, end, NORTH);
    set_root(start);
}
```

**Step 2:** Create the state-machine that defines the game flow. Fill out `Game::state_machine()` within `Game.cpp`.

```
void Game::state_machine(){
    uint8_t button = display->read_button();
    Space * current_space = player->get_current_space(); 
    if(current_space->get_id() == 7){
        display->say("You Win!");
    }else{
        display->say(current_space->get_name());
        if(button == BUTTON_UP){
            player->move_north();
        }
    }
}
```

## Code Structure

A 10,000 meter view of the code design. 

### Threading

Control is managed using a [Time Trigger Architecture](https://en.wikipedia.org/wiki/Time-triggered_architecture). Each thread is called periodically. Threads blocks, thus each thread must *completely finish* execution before the next is called.

There are two threads of control. The "display" thread continually updates the LCD display. The "game" thread runs a game state machine. Both threads call single functions repeatedly. 

### Code Design

This code follows a Model-View-Controller paradigm. The Model consists of a graph structure that represents the game map, this is accessible via the `GameModel`, `Map`, and `Space` classes. The view classes (`GameDisplay` and `Display`) provide a means of accessing the LCD hardware. The control exists within the `Game` class and is a state-machine. 

## Hardware Requirements

This code is intended to run on an Arduino UNO system augmented with a Liquid Crystal display and buttons. Helpful links: 

* [https://www.arduino.cc/](https://www.arduino.cc/) 
* [https://www.arduino.cc/en/Tutorial/HelloWorld](https://www.arduino.cc/en/Tutorial/HelloWorld) 