//
//  MisplacedTiles.hpp
//  puzzle
//
//  Created by Jordan Silva on 11/7/15.
//  Copyright © 2015 Jordan Silva. All rights reserved.
//
//  a.k.a Hamming Distance - heuristic

#ifndef MisplacedTiles_hpp
#define MisplacedTiles_hpp

#include <stdio.h>
#include "../helper/NodeHelper.hpp"

class MisplacedTiles {
private:
public:
    static float calculate(vector<char> vector, int dimension);
};

inline float MisplacedTiles::calculate(vector<char> vector, int dimension) {
    float distance = 0.f;
    for (int i = 0; i < vector.size(); i++) {
        if (vector[i] != (char)NodeHelper::BLANK && (int)vector[i] != i)
            distance++;
    }
    return distance;
}


#endif /* MisplacedTiles_hpp */
