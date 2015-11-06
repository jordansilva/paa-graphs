//
//  Node.hpp
//  puzzle
//
//  Created by Jordan Silva on 11/3/15.
//  Copyright © 2015 Jordan Silva. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

class Node {
private:
    void generate(vector<char> matrix);
    void generateHash();
    int getNextMovement(int position);
public:
    Node(vector<char> matrix, size_t parentId, int movement);
    virtual ~Node();

    size_t _id = 0;
    size_t _parent = 0;
    int movement = 0;
    
    vector<char> matrix;
    
    int depth = 0;
    float heuristic = 0.f;
    float total = 0;
    
    string getMovementLabel();
    
    float getDistance();
    
    bool operator<(const Node& rhs) const{
        return total > rhs.total;
    }
};

inline string Node::getMovementLabel() {
    switch (movement) {
        case 1:
            return "acima";
        case 2:
            return "direita";
        case 3:
            return "abaixo";
        case 4:
            return "esquerda";
        default:
            return "nenhum";
    }
}

inline float Node::getDistance() {
    return this->total;
}

#endif /* Node_hpp */
