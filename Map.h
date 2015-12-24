#ifndef MAP_H
#define MAP_H

#include <Arduino.h>

#define MAX_SPACES 8
#define MAX_ADJ_SPACES 4
#define MAX_OBJECTS 4
#define MAX_STRING_LEN 16

/* 
* There is a restriction on the amount of memory the space
*/


/**
* Size: MAX_STRING_LEN, 16.
*/
class Object {
    private:
        char name[MAX_STRING_LEN];
    public:
        Object();
};

/*
* Size: MAX_STRING_LEN + 32*MAX_ADJ_SPACES + SIZE_OBJECT*MAX_OBJECTS, 210
*/
class Space {
    private:

        char name[MAX_STRING_LEN];

        uint8_t adjacent_spaces_count;
        uint8_t num_objects;

        Space * adjacent_spaces[MAX_ADJ_SPACES];
        Object objects[MAX_OBJECTS];

    public:
        Space();

        void set_name(const char name[]);

        char * get_name();

        void add_adjacent(Space * dest);

        Space * get_adjacent(uint8_t index);

        void init(); 
};

/*
* Size: MAX_SPACES * SIZE_SPACE
*/
class Map {
    private:
        uint8_t num_spaces; 

        Space * root_space; 

        Space spaces[MAX_SPACES];
    public:
        Map();

        Space * add_space(const char S[]);

        void set_root(Space * s); 

        Space * get_root(); 
};


#endif // MAP_H
