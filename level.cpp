#include "level.hpp"

using std::cout, std::endl;

level::level(){
    row_ptrs = new uint8_t*[ROWS];

    for(int row = 0; row < ROWS; row++){
        row_ptrs[row] = new uint8_t[COLS];

        for(int col = 0; col < COLS; col++){
            row_ptrs[row][col] = 0;
        }
    }
}

level::~level(){
    for(int row = 0; row < ROWS; row++){
        delete[] row_ptrs[row];
    }

    delete[] row_ptrs;
}

uint8_t* level::operator[](int row){
    return row_ptrs[row];
}

std::ostream& operator<<(std::ostream& os, const level& rhs){
    for(int row = 0; row < ROWS; row++){
        os << (int)rhs.row_ptrs[row][0];

        for(int col = 1; col < COLS; col++){
            os << ' ' << (int)rhs.row_ptrs[row][col];
        }

        if(row != ROWS - 1)
            os << std::endl;
    }

    return os;
}

std::vector<uint8_t> level::send(uint8_t brightness){
    std::vector<uint8_t> ans = {0, 0}; //first element is first half of grid, second is second half

    for(int row = 0; row < ROWS; row++){
        for(int col = 0; col < COLS; col++){
            //will update the correct element's integer with a 1 if our desired brightness is above
            //our current brightness, or a 0 otherwise
            ans[row/2] += brightness < row_ptrs[row][col] ? 1 : 0; 

            //we dont want to bit shift if we're in the last of our 16 bits
            if((row % 2 == 1) && col == COLS - 1)
                continue;
            
            ans[row/2] <<= 1; //bit shift to make space for the next bit
        }
    }

    return ans;
}

void level::reset(){
    for(int row = 0; row < ROWS; row++){
        for(int col = 0; col < COLS; col++){
            row_ptrs[row][col] = 0;
        }
    }
}

//---------------test-------------------------------------
// int main(){
//     level l1;

//     cout << "when initialized:" << endl << l1 << endl;

//     l1[1][2] = true;

//     cout << "second row, third column true" << endl << l1 << endl;

//     l1[1][2] = false;

//     for(int i = 0; i < 4; i++){
//         l1[i][i] = true;
//     }

//     cout << "diagonal" << endl << l1 << endl;

//     cout << "first 16 (base 10): " << (int)l1.send(1).at(0) << endl;
//     cout << "second 16 (base 10): " << (int)l1.send(1)[1] << endl;
// }