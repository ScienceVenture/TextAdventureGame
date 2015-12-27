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

        uint8_t space_id; 
        uint8_t adjacent_spaces_count;
        uint8_t num_objects;

        Space * adjacent_spaces[MAX_ADJ_SPACES];
        Object objects[MAX_OBJECTS];

    public:

        Space();

        void set_name(const char name[]);

        char * get_name();

        // Add a connection from this space to the destination using 
        // @param i to index into the adjacent_spaces array. 
        //
        void add_adjacent(Space * dest, uint8_t i);

        Space * get_adjacent(uint8_t index);

        uint8_t get_id(); 

        void set_id(uint8_t id);

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

        int8_t find_unused_id(); 

    public:

        Map();

        Space * add_space(const char S[], uint8_t id);

        Space * add_space(const char S[]);

        void set_root(Space * s); 

        Space * get_root(); 

};


#endif // MAP_H
