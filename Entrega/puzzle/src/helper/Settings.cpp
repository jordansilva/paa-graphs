//
//  Settings.cpp
//  Puzzle
//
//  Created by Jordan Silva on 11/03/15.
//  Copyright © 2015 Jordan Silva. All rights reserved.
//

#include "Settings.hpp"

Settings::Settings(string input) {
    init(input);
}

Settings::~Settings() {
}

void Settings::init(string filename) {

    try {
        string line = "";
        ifstream infileFoes(filename);
        if (!infileFoes.good())
            throw std::runtime_error("Arquivo " + filename + " não encontrado!");
        
        //First line
        getline(infileFoes, line);
        this->mDimension = stoi(line);

        while (infileFoes >> line) {
            if (*line.c_str() != NodeHelper::BLANK)
                this->mMatrix.push_back(stoi(line));
            else
                this->mMatrix.push_back((char)NodeHelper::BLANK);
        }
    }
    catch (const std::exception& e) {
        cout << e.what() << endl;
    }
}


