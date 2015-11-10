//
//  Settings.hpp
//  puzzle
//
//  Created by Jordan Silva on 11/03/15.
//  Copyright © 2015 Jordan Silva. All rights reserved.
//

#ifndef Settings_hpp
#define Settings_hpp

#include <stdio.h>
#include <string>
#include <string.h>
#include <fstream>
#include <iostream>
#include <vector>
#include "NodeHelper.hpp"

using namespace std;

class Settings {
public:
    Settings(string input);
    virtual ~Settings();
    
    int getDimension();
    vector<char> getMatrix();
    void printMatrix();
    
private:
    void init(string filename);
    
    int mDimension = 0;
    vector<char> mMatrix;
};

inline int Settings::getDimension() {
    return mDimension;
}

inline vector<char> Settings::getMatrix() {
    return mMatrix;
}

#endif /* Settings_hpp */
