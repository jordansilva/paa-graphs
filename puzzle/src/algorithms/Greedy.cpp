//
//  Greedy.cpp
//  Assassins Greed
//
//  Created by Jordan Silva on 10/11/15.
//  Copyright © 2015 Jordan Silva. All rights reserved.
//

#include "Greedy.hpp"

#include <algorithm>
#include <ctime>

Greedy::Greedy(vector<int> foes, vector<int> levels, bool debug) {
    execute(&foes, &levels, debug);
}

Greedy::~Greedy() {
    
}

vector<int> Greedy::execute(vector<int>* foes, int &level, vector<int> &result) {
    
    sort(foes->begin(), foes->end(), greater<int>());
    
    if (level == 0)
        return result;
    
    for (int i = 0; i < foes->size(); i++) {
        if (foes->at(i) <= level) {
            int count = level / foes->at(i);
            result.insert(result.end(), count, foes->at(i));
            level -= foes->at(i)*count;
        }
    }
    
    return result;
}

void Greedy::execute(vector<int>* foes, vector<int>* levels, bool debug) {

    ofstream myfile;
    myfile.open("output.txt");

    for (int i = 0; i < levels->size(); i++) {
        clock_t begin = clock();
        
        Level level(levels->at(i));
        
        //Getting level
        vector<int> tmp;
        int tmpLevel = level.getDifficulty();
        vector<int> result = execute(foes, tmpLevel, tmp);
        level.addFoes(result);

        myfile << level.toString();
        if (i+1 < levels->size())
            myfile << "\n";

        //Printing
        clock_t end = clock();
        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

        if (debug) {
            cout << "Level: " << level.getDifficulty() << endl;
            level.print();
            cout << endl;
            cout << "Time elapsed: " << elapsed_secs << endl;
            cout << endl;
        }
    }

    myfile.close();
}

