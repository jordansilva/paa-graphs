//
//  NodeHelper.hpp
//  puzzle
//
//  Created by Jordan Silva on 11/3/15.
//  Copyright © 2015 Jordan Silva. All rights reserved.
//

#ifndef NodeHelper_hpp
#define NodeHelper_hpp

#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include "../domain/Node.hpp"

using namespace std;

class NodeHelper {
private:
public:
    static bool checkSolvable(Node node, int dimension);
    static bool isInvertedMovement(int movement, int nextMovement);
    static void printMatrix(vector<char> matrix, int dimension);
    static void printMatrix(Node node, int dimension);
    static void printSolution(list<Node> nodes);
    static void saveSolution(list<Node> nodes);
    static Node generateGoal(int dimension);
    
    static unsigned long getNumberMovements(list<Node> nodes);
    static string getMovements(list<Node> nodes);
    
    static const char BLANK = '_';
};

enum Movement {
    NONE = 0,
    TOP = 1,
    RIGHT = 2,
    DOWN = 3,
    LEFT = 4
};

inline Node NodeHelper::generateGoal(int dimension) {
    vector<char> matrix;
    matrix.push_back((char)NodeHelper::BLANK);
    for (int i = 1; i < dimension*dimension; i++)
        matrix.push_back(i);
    
    Node goal(matrix, 0, Movement::NONE);
    return goal;
}

inline bool NodeHelper::isInvertedMovement(int movement, int nextMovement) {
    if ((movement == 1 && nextMovement == 3) || (movement == 3 && nextMovement == 1))
        return true;
    
    if ((movement == 2 && nextMovement == 4) || (movement == 4 && nextMovement == 2))
        return true;
    
    return false;
}

inline void NodeHelper::printMatrix(vector<char> matrix, int dimension) {
    for (unsigned int i = 0; i < matrix.size(); i++) {
        if (matrix[i] == BLANK)
            cout << matrix[i] << " ";
        else
            cout << (int)matrix[i] << " ";
        
        if ((i+1)%dimension == 0)
            cout << endl;
    }
}

inline void NodeHelper::printMatrix(Node node, int dimension) {
    
    cout << "Movement: " << node.getMovementLabel() << endl;
    cout << "Depth: " << node.depth << " Heuristic: " << node.heuristic << " Total: " << node.getDistance() << endl;
    printMatrix(node.matrix, dimension);
    cout << endl;
}

inline void NodeHelper::saveSolution(list<Node> nodes) {
    ofstream outputFile("output.txt");
    if (nodes.size() > 0) {
        outputFile << nodes.size() - 1 << endl;
        for(auto &item : nodes) {
            if (item._parent != 0)
                outputFile << item.getMovementLabel() << endl;
        }
    }
    else
        outputFile << "Sem solução" << endl;

    outputFile.close();
}

inline void NodeHelper::printSolution(list<Node> nodes) {
    string result = "";
    for(auto &item : nodes) {
        if (result.length() > 0)
            result += ", ";

        result += item.getMovementLabel();
    }
    
    cout << "Movimentos: " << nodes.size()-1 << endl;
    cout << result << endl;
}

inline unsigned long NodeHelper::getNumberMovements(list<Node> nodes) {
    return nodes.size() - 1;
}

inline string NodeHelper::getMovements(list<Node> nodes) {
    string result = "";
    for(auto &item : nodes) {
        if (result.length() > 0)
            result += ", ";
        
        result += item.getMovementLabel();
    }
    
    return result;
}


#endif /* NodeHelper_hpp */
