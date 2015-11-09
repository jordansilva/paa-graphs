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
#include "src/algorithms/AStar.hpp"

#define INPUT_FOLDER "/Volumes/Tyr/Projects/UFMG/Disciplinas/PAA/TP 3/puzzle/puzzle/data/"

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

    string fInput = "";
    for (int i = 4; i <= 4; i++) {
        fInput = INPUT_FOLDER;
        fInput += "input" + to_string(i) + ".txt";
        cout << "input " << i << ".txt" << endl;
        
        if (i == 20)
            continue;
        
        Settings settings(fInput);
        
        //Elapsed Secs
        clock_t begin = clock();
        
        //Heuristic
        int heuristic = Method::MANHATTAN_HAMMING;
        Heuristic funcH(settings.getDimension(), heuristic);
        cout << funcH.calculate(settings.getMatrix()) << endl;

//        if (!funcH.isSolved()) {
//            cout << "Heurística não resolve puzzle " << settings.getDimension() << "x" << settings.getDimension() << "." << endl;
//            continue;
//        }
        
        //A*
        AStar aStar(settings.getMatrix(), settings.getDimension());
        list<Node> result = aStar.execute(funcH);
        if (result.size() > 0) {
            NodeHelper::printSolution(result);
        }
        else
            cout << "Sem solução" << endl;
        
        //Elapsed Secs
        clock_t end = clock();
        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        cout << "Time elapsed: " << elapsed_secs << endl;
        cout << endl;
    }
    
    return 0;
}
