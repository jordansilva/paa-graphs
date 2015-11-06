//
//  BruteForce.cpp
//  Assassins Greed
//
//  Created by Jordan Silva on 10/11/15.
//  Copyright © 2015 Jordan Silva. All rights reserved.
//

#include "BruteForce.hpp"


BruteForce::BruteForce(vector<int> foes, vector<int> levels, bool debug) {
    execute(&foes, &levels, debug);
}

BruteForce::~BruteForce() {
    
}

vector<int> BruteForce::execute(vector<int>* foes, int level, vector<int> &optimal, vector<int> *current) {
   
   if (level == 0) {
       if (optimal.size() > current->size())
           optimal = *current;
       
       return optimal;
   }

   for (int i = 0; i < foes->size(); i++) {
       if (foes->at(i) <= level && current->size() + 1 < optimal.size()) {
           vector<int> tmp = *current;
           tmp.push_back(foes->at(i));

           execute(foes, level - foes->at(i), optimal, &tmp);
       }
   }

   return optimal;
}

void BruteForce::execute(vector<int>* foes, vector<int>* levels, bool debug) {
    sort(foes->begin(), foes->end(), greater<int>());
    
    ofstream myfile;
    myfile.open("output.txt");

    for (int i = 0; i < levels->size(); i++) {
        clock_t begin = clock();
        
        Level level(levels->at(i));
        
        //Getting level
        vector<int> optimal(level.getDifficulty() + 1);
        fill(optimal.begin(), optimal.end(), INT32_MAX);
        
        vector<int> tmp;
        vector<int> result = execute(foes, level.getDifficulty(), optimal, &tmp);
        level.addFoes(optimal);
        
        //Printing
        clock_t end = clock();
        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  
        myfile << level.toString();
        if (i+1 < levels->size())
            myfile << "\n";

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

