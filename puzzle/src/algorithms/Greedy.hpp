//
//  Greedy.hpp
//  Assassins Greed
//
//  Created by Jordan Silva on 10/11/15.
//  Copyright © 2015 Jordan Silva. All rights reserved.
//

#ifndef Greedy_hpp
#define Greedy_hpp

#include <stdio.h>

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include "../domain/Node.hpp"

using namespace std;

class Greedy {
public:
    Greedy(vector<int> foes, vector<int> levels, bool debug);
    virtual ~Greedy();
private:
    void execute(vector<int>* foes, vector<int>* levels, bool debug);
    vector<int> execute(vector<int>* foes, int &level, vector<int> &result);
};

#endif /* Greedy_hpp */
