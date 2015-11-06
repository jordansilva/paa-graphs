//
//  BruteForce.hpp
//  Assassins Greed
//
//  Created by Jordan Silva on 10/11/15.
//  Copyright © 2015 Jordan Silva. All rights reserved.
//

#ifndef BruteForce_hpp
#define BruteForce_hpp

#include <stdio.h>

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <ctime>
#include "../domain/Level.hpp"

using namespace std;

class BruteForce {
public:
    BruteForce(vector<int> foes, vector<int> levels, bool debug);
    virtual ~BruteForce();
private:
    void execute(vector<int>* foes, vector<int>* levels, bool debug);
    vector<int> execute(vector<int>* foes, int level, vector<int> &optimal, vector<int> *current);
};

#endif /* BruteForce_hpp */
