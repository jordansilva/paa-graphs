//
//  Heuristic.hpp
//  puzzle
//
//  Created by Jordan Silva on 11/7/15.
//  Copyright © 2015 Jordan Silva. All rights reserved.
//

#ifndef Heuristic_hpp
#define Heuristic_hpp

#include <stdio.h>
#include "Manhattan.hpp"
#include "MisplacedTiles.hpp"

class Heuristic {
private:
    int method;
    int dimension;
    
public:
    Heuristic(int dimension, int method) {
        this->dimension = dimension;
        this->method = method;
    };
    virtual ~Heuristic() { };
    
    float calculate(vector<char> vector);
    bool isSolved();
};

enum Method {
    MANHATTAN = 1,
    MISPLACED_TILES = 2
};

inline bool Heuristic::isSolved() {
    switch (this->method) {
        case Method::MANHATTAN:
            return true;
        case Method::MISPLACED_TILES:
            return (dimension != 4);
        default:
            return true;
    }
}

inline float Heuristic::calculate(vector<char> vector) {
    switch (this->method) {
        case Method::MANHATTAN:
            return Manhattan::calculate(vector, this->dimension);
        case Method::MISPLACED_TILES:
            return MisplacedTiles::calculate(vector, this->dimension);
        default:
            return -1;
    }    
}


#endif /* Heuristic_hpp */
