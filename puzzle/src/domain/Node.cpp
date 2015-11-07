//
//  Node.cpp
//  puzzle
//
//  Created by Jordan Silva on 11/3/15.
//  Copyright © 2015 Jordan Silva. All rights reserved.
//

#include "Node.hpp"

Node::Node() {
}

Node::Node(vector<char> matrix, size_t parentId, int movement) {
    this->_id = 0;
    this->depth = 0;
    this->_parent = parentId;
    this->movement = movement;

    generate(matrix);
}

Node::~Node() {
    
}

void Node::generate(vector<char> parentMatrix) {
    
    int blankPosition = -1;
    for (int i = 0; i < parentMatrix.size(); i++) {
        if (parentMatrix[i] == '_')
            blankPosition = i;
        
        this->matrix.push_back(parentMatrix[i]);
    }
    
    //change position
    int nextPosition = getNextMovement(blankPosition);
    if (blankPosition != -1 && blankPosition != nextPosition)
        swap(this->matrix[blankPosition], this->matrix[nextPosition]);
    
    //_id
    generateHash();
}

void Node::generateHash() {
    if(this->_id == 0){
        size_t hashNum = 0;
        for(size_t i = 0; i < this->matrix.size(); i++){
            int elem = this->matrix[i];
            hashNum ^= std::hash<int>()(elem) + 0x9e3779b9 + (hashNum << 6) + (hashNum >> 2);
        }
        this->_id = hashNum;
    }
}

int Node::getNextMovement(int position) {

    int dimension = sqrt(this->matrix.size());
    int row = position / dimension;
    int column = position % dimension;

    switch (this->movement) {
        case 1:
            //UP
            if (row > 0)
                return position - dimension;
            else
                return position;
        case 2:
            //RIGHT
            if (column < dimension - 1)
                return position + 1;
            else
                return position;
        case 3:
            //DOWN
            if (row < dimension - 1)
                return position + dimension;
            else
                return position;
        case 4:
            //LEFT
            if (column > 0)
                return position - 1;
            else
                return position;
        default:
            return position;
    }
}