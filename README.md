# Text Adventure Game

A code based created for Science Venture's RetroGaming program. This framework will allow students to create a text based adventure game.

## Getting Started

There are two steps: 

1. Define the map that will be used in the game. Fill out the `GameModel::build_map()` function  

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