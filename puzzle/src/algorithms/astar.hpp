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
#include "Manhattan.hpp"
#include "../helper/NodeHelper.hpp"
#include "../domain/Node.hpp"

using namespace std;

class astar {
private:
public:
    astar();
    virtual ~astar();
    
    static void execute(Node initial, int dimension);
};

#endif /* astar_hpp */
