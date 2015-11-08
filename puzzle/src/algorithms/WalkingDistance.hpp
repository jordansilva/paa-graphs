//
//  WalkingDistance.hpp
//  puzzle
//
//  Created by Jordan Silva on 11/8/15.
//  Copyright © 2015 Jordan Silva. All rights reserved.
//

#ifndef WalkingDistance_hpp
#define WalkingDistance_hpp

#include <stdio.h>
#include <unordered_map>
#include <string>

#include "../helper/NodeHelper.hpp"

class WalkingDistance {
private:
    static int searchMax(vector<char> vector, int defaultValue);
    static int searchMin(vector<char> vector, int defaultValue);
    static int whichMatrix(unordered_map<int, vector<char> > *matrices, int i, bool isDown);
    static void print(unordered_map<int, std::vector<char> > matrices);
public:
    static float calculate(vector<char> vector, int dimension);
    
};

inline void WalkingDistance::print(unordered_map<int, std::vector<char> > matrices) {
    const char alphabet[6] = { 'A', 'B', 'C', 'D', 'E', 'F' };

    for (int j = 0; j < matrices.size(); j++) {
        for (auto s : matrices.at(j))
            cout << alphabet[(int)s] << " ";
        cout << endl;
    }
    cout << endl;
}

inline int WalkingDistance::searchMin(vector<char> vector, int defaultValue) {
    int result = defaultValue;
    for (int i = 0; i < vector.size(); i++) {
        if ((int)vector[i] < defaultValue) {
            result = (int)vector[i];
        }
    }
    
    return result;
}

inline int WalkingDistance::searchMax(vector<char> vector, int defaultValue) {
    int result = defaultValue;

    for (int i = 0; i < vector.size(); i++) {
        if ((int)vector[i] > defaultValue) {
            result = (int)vector[i];
        }
    }
    
    return result;
}


inline int WalkingDistance::whichMatrix(unordered_map<int, vector<char> > *matrices, int i, bool isDown) {

    int value = -1;
    int swipeIndex = i;
    
    if (isDown && i < matrices->size()-1) {
        value = searchMin(matrices->at(i+1), i+1);
        swipeIndex = i+1;
    }
    
    if (!isDown && i > 0) {
        value = searchMax(matrices->at(i-1), i-1);
        swipeIndex = i-1;
    }
    
    if (value != -1) {
        matrices->at(i).push_back(value);
        for (int j = 0; j < matrices->at(swipeIndex).size(); j++) {
            if (matrices->at(swipeIndex).at(j) == value) {
                matrices->at(swipeIndex).erase(matrices->at(swipeIndex).begin()+j);
                break;
            }
        }
    }
    
    return swipeIndex;
}

inline float WalkingDistance::calculate(vector<char> vector, int dimension) {
    
    char matrix_row[dimension][dimension];
    char matrix_column[dimension][dimension];
    
    //construct matrix
    for (int i = 0; i < vector.size(); i++) {
        int row = i / dimension;
        int column = i % dimension;

        if (vector[i] != (char)NodeHelper::BLANK) {
            int target_row = (vector[i]-1) / dimension;
            int target_column = (vector[i]-1) % dimension;
            
            matrix_row[row][column] = target_row;
            matrix_column[row][column] = target_column;
        }
        else {
            matrix_row[row][column] = dimension;
            matrix_column[row][column] = dimension;
        }
    }
    
    //by row
    unordered_map<int, std::vector<char> > matrices_row;
    unordered_map<int, std::vector<char> > matrices_column;
    
    for (int i = 0; i < dimension; i++) {
        std::vector<char> matrix_r;
        std::vector<char> matrix_c;
        
        for (int j = 0; j < dimension; j++) {
            if (matrix_row[i][j] != dimension)
                matrix_r.push_back(matrix_row[i][j]);
            
            if (matrix_row[j][i] != dimension)
                matrix_c.push_back(matrix_column[j][i]);
        }
        
        matrices_row.insert(make_pair(i, matrix_r));
        matrices_column.insert(make_pair(i, matrix_c));
    }
    
    //solve
    int matrixSolved = dimension;
    float distance = 0.f;
    
    int x = 0;

    bool direction = true;
    while (matrixSolved > 0) {
        matrixSolved = dimension;
        
        for (int i = 0; i < dimension; i++) {
            int indexMin = searchMin(matrices_row.at(i), i);
            
            print(matrices_row);
            
            if (indexMin == i && (matrices_row.at(i).size() == dimension || indexMin == dimension-1)) {
                matrixSolved--;
            }
            
            if (matrices_row.at(i).size() < dimension)
                whichMatrix(&matrices_row, i, direction);
        }
        
        direction = direction == false;
//        for (int i = dimension-1; i >= 0; i--) {
//            int indexMin = searchMin(matrices_row.at(i), i);
//            
//            print(matrices_row);
//            
//            if (indexMin == i && (matrices_row.at(i).size() == dimension || indexMin == dimension-1)) {
//                matrixSolved--;
//            }
//            
//            if (matrices_row.at(i).size() < dimension)
//                whichMatrix(&matrices_row, i, false);
//        }
        

        x++;
        if (x > 5)
            break;
    }
//    
//    for (auto m : matrices_row) {
//        for (auto s : m.second)
//            cout << alphabet[(int)s] << " ";
//        cout << endl;
//    }
    
//    //by row

//        int row = i / dimension;
//        int column = i % dimension;
//        
//        if (vector[i] != '_') {
//            //int target_row = (vector[i]-1) / dimension;
//            int target_column = (vector[i]-1) % dimension;
//            distance += abs(column - target_column);
//        }
//        
//    }
    return distance;
}

#endif /* WalkingDistance_hpp */
