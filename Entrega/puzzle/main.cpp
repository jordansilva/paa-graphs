//
//  main.cpp
//  puzzle
//
//  Created by Jordan Silva on 11/3/15.
//  Copyright © 2015 Jordan Silva. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include "src/helper/Settings.hpp"
#include "src/helper/NodeHelper.hpp"
#include "src/domain/Node.hpp"
#include "src/algorithms/AStar.hpp"

int main(int argc, const char * argv[]) {
    
    string fInput = "";
    
    if (argc == 2) {
        fInput = argv[1];
    }
    else {
        cout << "Entrada inválida" << endl;
        return 0;
    }

    //Reading files
    Settings settings(fInput);
    
    //Instance Heuristic
    int heuristic = Method::MANHATTAN_HAMMING;
    Heuristic funcH(settings.getDimension(), heuristic);

    //A*
    AStar aStar(settings.getMatrix(), settings.getDimension());
    list<Node> result = aStar.execute(funcH);
    NodeHelper::saveSolution(result);

    return 0;
}
