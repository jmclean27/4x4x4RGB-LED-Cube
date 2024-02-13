#pragma once
#include <iostream>
#include <vector>
#include <cstdint>

#define ROWS 4
#define COLS 4

class level{
    public:
    /*
        constructor generates a ROWSxCOLS matrix (default 4x4)
        of all false values

        @param none

        @return none
    */
    level();

    //frees up the dynamically allocated memory
    ~level();

    /*
        defines bracket operator to return pointer to array for proper row

        @param (int)row the wanted row

        @return (bool*) - pointer to row array
    */
    uint8_t* operator[](int row);

    // void operator=(uint8_t* arr);

    /*
        generates ostream object in order to print elements of the matrix
        with proper format

        @param (std::ostream&)os the output stream object
        @param (level&)rhs the matrix to be printed

        @return (std::ostream&) output stream object that can be printed via std::cout 
    */
    friend std::ostream& operator<<(std::ostream& os, const level& rhs);

    /*
        reads our matrix, and generates a bitwise representation of on/off per LED.
        - will compare the brightness value in memory to current brightness when displaying
        - first element represents first half of grid, second element represents second half

        Parameters:
        (uint8_t)brightness - the brightness value we compare to our matrix values to decide
        if we send a 1 or 0

        Returns:
        (std::vector<uint8_t) the vector with integers representing on/off state for each LED
        - first element is first half of grid, second element is second half
    */
    std::vector<uint8_t> send(uint8_t brightness);

    //sets every LED to 0 in memory
    void reset();

    private:
    uint8_t** row_ptrs; //points to array of pointers, each of which point to array holding a row
};