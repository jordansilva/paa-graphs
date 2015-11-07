//
//  astar.hpp
//  puzzle
//
//  Created by Jordan Silva on 11/6/15.
//  Copyright © 2015 Jordan Silva. All rights reserved.
//

#ifndef astar_hpp
#define astar_hpp

#include <stdio.h>
#include <queue>
#include "Heuristic.hpp"
#include "../helper/NodeHelper.hpp"
#include "../domain/Node.hpp"

using namespace std;

class AStar {
private:
    Node initial;
    int dimension;
public:
    AStar(vector<char> matrix, int dimension);
    virtual ~AStar();
    
    list<Node> execute(Heuristic heuristic);
};

#endif /* AStar_hpp */
