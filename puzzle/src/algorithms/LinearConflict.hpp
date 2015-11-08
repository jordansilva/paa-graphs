//
//  LinearConflict.hpp
//  puzzle
//
//  Created by Jordan Silva on 11/8/15.
//  Copyright © 2015 Jordan Silva. All rights reserved.
//

#ifndef LinearConflict_hpp
#define LinearConflict_hpp

#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

class LinearConflict {
private:
public:
    static float calculate(vector<char> vector, int dimension);
};

inline float LinearConflict::calculate(vector<char> vector, int dimension) {
    float distance = 0.f;
    for (int i = 0; i < vector.size(); i++) {
        for (int j = i+1; j < vector.size(); j++) {
            int row = i / dimension;
            int column = i % dimension;
            int row2 = j / dimension;
            int column2 = j % dimension;

            if (vector[i] != '_' && vector[j] != '_') {
                int target_row = vector[i] / dimension;
                int target_column = vector[i] % dimension;

                int target_row2 = vector[j] / dimension;

                if (row == target_row && row2 == target_row2 && target_row == target_row2) {
                    if (((column < column2) && (target_column >= column2)) || ((column > column2) && (target_column <= column2))) {
                        distance += 1;
                    }
                    
                }
            }
        }
    }
    return distance;
}


#endif /* LinearConflict_hpp */
