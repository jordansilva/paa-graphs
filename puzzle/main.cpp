//
//  main.cpp
//  puzzle
//
//  Created by Jordan Silva on 11/3/15.
//  Copyright © 2015 Jordan Silva. All rights reserved.
//

#include <iostream>
#include "src/helper/Settings.hpp"
#include "src/helper/NodeHelper.hpp"
#include "src/domain/Node.hpp"
#include "src/algorithms/astar.hpp"

#define INPUT_3 "/Volumes/Tyr/Projects/UFMG/Disciplinas/PAA/TP 3/puzzle/puzzle/data/input.txt"
#define INPUT_4 "/Volumes/Tyr/Projects/UFMG/Disciplinas/PAA/TP 3/puzzle/puzzle/data/input4.txt"

int main(int argc, const char * argv[]) {
//    string fInput = "";
//    bool fDebug = false;
//    
//    if (argc > 1) {
//        fInput = argv[1];
//        if (argc > 2)
//            fDebug = (bool)argv[2];
//    }
//    else {
//        cout << "Entrada inválida" << endl;
//        return 0;
//    }
    
    string fInput = INPUT_4;
    
    Settings settings(fInput);
    NodeHelper::printMatrix(settings.getMatrix(), settings.getDimension());
    cout << endl;
    
    clock_t begin = clock();
    
    Node node1(settings.getMatrix(), 0, Movement::NONE);
    node1.depth = 0;
    node1.heuristic = Manhattan::calculate(node1.matrix, settings.getDimension());
    node1.total = node1.depth + node1.heuristic;
    
    astar::execute(node1, settings.getDimension());
    
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << "Time elapsed: " << elapsed_secs << endl;
//
//    cout << "State 1" << endl;
//    ;
//    NodeHelper::printMatrix(node1.matrix, settings.getSize());
//    cout << endl;
//    
//    cout << "State 2" << endl;
//    Node node2(node1.matrix, 1, Movement::LEFT);
//    NodeHelper::printMatrix(node2.matrix, settings.getSize());
//    cout << endl;
    
//    //Greedy
//    cout << "Greedy" << endl;
//    Greedy agAlgorithm(settings.getFoes(), settings.getLevels(), fDebug);
    
    return 0;
}
