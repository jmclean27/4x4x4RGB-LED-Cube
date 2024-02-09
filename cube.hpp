#pragma once
#include "level.hpp"

#define LEVELS 4

class cube{
    public:
    /*
        constructor generates a LEVELS size(default 4) array of levels

        @param none

        @return none
    */
    cube();

    //frees up the dynamically allocated memory
    ~cube();

    /*
        defines bracket operator to return wanted level object

        @param (int)level the wanted level

        @return (level&) - reference to level object
    */
    level& operator[](int level);

    /*
        returns wanted level object

        @param (int)level the wanted level

        @return (level&) - reference to level object
    */
    level& getLevel(int level);

    /*
        resets the cube based on 3 configurations:
        - reset() will set the entire cube to 0.
        - reset(layer) will only reset the specific layer
        - reset(layer, true) will reset everything EXCEPT the specific layer

        Parameters:
        (uint8_t)level - the level you want to affect -> defaults to LEVELS + 1
        (bool)negative - whether you want a "negative" reset -> defaults to false

        Returns:
        none
    */
    void reset(uint8_t level = LEVELS + 1, bool negative = false);

    /*
        generates ostream object in order to print elements of the cube
        with proper format. Calls the level class implementation for extraction

        @param (std::ostream&)os the output stream object
        @param (level&)rhs the cube to be printed

        @return (std::ostream&) output stream object that can be printed via std::cout 
    */
    friend std::ostream& operator<<(std::ostream& os, const cube& rhs);

    private:
    level* levels; //points to array of level objects
};