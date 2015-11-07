//
//  Manhattan.hpp
//  puzzle
//
//  Created by Jordan Silva on 11/6/15.
//  Copyright © 2015 Jordan Silva. All rights reserved.
//

#ifndef Manhattan_hpp
#define Manhattan_hpp

#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

class Manhattan {
private:
public:
    static float calculate(vector<char> vector, int dimension);
};

inline float Manhattan::calculate(vector<char> vector, int dimension) {
    float distance = 0.f;
    for (int i = 0; i < vector.size(); i++) {
        int row = i / dimension;
        int column = i % dimension;
        
//        int target_row = 0;
//        int target_column = 0;
        
        if (vector[i] != '_') {
            int target_row = vector[i] / dimension;
            int target_column = vector[i] % dimension;
        
            distance += abs(row - target_row) + abs(column - target_column);
        }
        
    }
    return distance;
}

#endif /* Manhattan_hpp */
