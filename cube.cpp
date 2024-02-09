#include "cube.hpp"

using std::cout, std::endl;

cube::cube(){
    levels = new level[LEVELS];
}

cube::~cube(){
    delete[] levels;
}

level& cube::operator[](int level){
    return levels[3-level];
}

level& cube::getLevel(int level){
    return levels[3-level];
}

void cube::reset(uint8_t level, bool negative){
    //if valid level, and not a negative reset we only reset this specific layer
    if(level < LEVELS && !negative){
        this->getLevel(level).reset();
        return;
    }

    for(uint8_t l = 0; l < LEVELS; l++){
        if(l == level) //skip the layer that we want negatively affected, if specified
            continue;

        this->getLevel(l).reset();
    }
}

std::ostream& operator<<(std::ostream& os, const cube& rhs){
    for(int i = 0; i < LEVELS; i++){
        os << "---Level " << i + 1 << "---" << endl;
        os << rhs.levels[i] << endl;
    }

    return os;
}

// -----------------test----------------------------------
// int main(){
//     cube c1, c2;

//     cout << "when initialized:" << endl << c1 << endl;

//     for(int i = 0; i < LEVELS; i++){
//         if(i % 2 == 0)
//             continue;

//         for(int j = 0; j < ROWS; j++){
//             c1.getLevel(i)[j][j] = 1;
//         }
//     }

//     cout << "every second layer diagonal:" << endl << c1 << endl;

//     c2.getLevel(2)[1][1] = 1;
//     c2.getLevel(2)[1][3] = 1;

//     cout << "second obj test:" << endl << c2 << endl;

//     c2.reset();

//     cout << "after reset:" << endl << c2 << endl;
// }