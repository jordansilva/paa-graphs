//
//  NodeHelper.hpp
//  puzzle
//
//  Created by Jordan Silva on 11/3/15.
//  Copyright © 2015 Jordan Silva. All rights reserved.
//

#ifndef NodeHelper_hpp
#define NodeHelper_hpp

#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "../domain/Node.hpp"

using namespace std;

class NodeHelper {
private:
public:
    static void printMatrix(vector<char> matrix, int size);
    static void printMatrix(Node node, int size);
    
    static const char BLANK = '_';
};

enum Movement {
    NONE = 0,
    TOP = 1,
    RIGHT = 2,
    DOWN = 3,
    LEFT = 4
};

inline void NodeHelper::printMatrix(vector<char> matrix, int dimension) {
    for (int i = 0; i < matrix.size(); i++) {
        if (matrix[i] == BLANK)
            cout << matrix[i] << " ";
        else
            cout << (int)matrix[i] << " ";
        
        if ((i+1)%dimension == 0)
            cout << endl;
    }
}

inline void NodeHelper::printMatrix(Node node, int dimension) {
    
    cout << "Movement: " << node.getMovementLabel() << endl;
    cout << "Depth: " << node.depth << " Heuristic: " << node.heuristic << " Total: " << node.getDistance() << endl;
    printMatrix(node.matrix, dimension);
    cout << endl;
}



#endif /* NodeHelper_hpp */
