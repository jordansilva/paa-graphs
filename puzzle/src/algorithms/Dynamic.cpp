//
//  Dynamic.cpp
//  Assassins Greed
//
//  Created by Jordan Silva on 10/11/15.
//  Copyright © 2015 Jordan Silva. All rights reserved.
//

#include "Dynamic.hpp"

Dynamic::Dynamic(vector<int> foes, vector<int> levels, bool debug) {
    execute(&foes, &levels, debug);
}

Dynamic::~Dynamic() {
    
}


vector<int> Dynamic::execute(vector<int>* foes, int level, int *minRequired) {

    map<int, int> trace;
    vector<int> mins(level+1);
    vector<int> prev(level+1);
    
    fill(mins.begin(), mins.end(), INT32_MAX);
    for(int i = 0; i < foes->size(); i++)
        trace.insert(make_pair<int,int>((int)foes->at(i),0));

    mins[0] = 0;
    for(int i = 1; i <= level; i++) {
        int bestCoin = -1;
        for(int j = 0; j < foes->size() && foes->at(j) <= i;j++) {
            if(mins[i - foes->at(j)] + 1 < mins[i]) {
                mins[i] = mins[i - foes->at(j)] + 1;
                bestCoin = j;
                prev[i] = i - foes->at(j);
            }
        }
        
        if(bestCoin != -1)
            trace[i] = foes->at(bestCoin);
    }
    
    *minRequired = mins[level];
    int curr=level;
    vector<int> result;
    while(curr > 0) {
        result.push_back(trace[curr]);
        curr=prev[curr];
    }
    
    return  result;
}

void Dynamic::execute(vector<int>* foes, vector<int>* levels, bool debug) {
    
    ofstream myfile;
    myfile.open("output.txt");

    for (int i = 0; i < levels->size(); i++) {
        clock_t begin = clock();
        
        Level level(levels->at(i));
        
        //Getting level
        int minRequired = 0;
        vector<int> result = execute(foes, level.getDifficulty(), &minRequired);
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

