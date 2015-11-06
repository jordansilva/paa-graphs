//
//  Dynamic.hpp
//  Assassins Greed
//
//  Created by Jordan Silva on 10/11/15.
//  Copyright © 2015 Jordan Silva. All rights reserved.
//

#ifndef Dynamic_hpp
#define Dynamic_hpp


#include <stdio.h>

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <ctime>
#include <utility>
#include "../domain/Level.hpp"

using namespace std;

class Dynamic {
public:
    Dynamic(vector<int> foes, vector<int> levels, bool debug);
    virtual ~Dynamic();
private:
    void execute(vector<int>* foes, vector<int>* levels, bool debug);
    vector<int> execute(vector<int>* foes, int level, int *minRequired);
};

#endif /* Dynamic_hpp */
