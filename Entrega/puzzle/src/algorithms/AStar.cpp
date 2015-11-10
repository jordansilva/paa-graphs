//
//  AStar.cpp
//  puzzle
//
//  Created by Jordan Silva on 11/6/15.
//  Copyright © 2015 Jordan Silva. All rights reserved.
//

#include "AStar.hpp"

AStar::AStar(vector<char> matrix, int dimension) {
    this->dimension = dimension;
    this->initial.generate(matrix);
}

AStar::~AStar() {
    
}

list<Node> AStar::execute(Heuristic heuristic) {
    
    bool isSolvable = NodeHelper::checkSolvable(this->initial, this->dimension);
    list<Node> result;
    result.clear();
    
    if (isSolvable) {
        Node goal = NodeHelper::generateGoal(this->dimension);
        
        //Calcule heuristic to initial node
        this->initial.heuristic = heuristic.calculate(this->initial.matrix);
        
        //Nodes open (to visit)
        priority_queue<Node, vector<Node>> queue;
        queue.push(this->initial);

        //Nodes visited
        unordered_map<size_t, Node> closedList;
        size_t last_id = 0;
        while (!queue.empty()) {
            Node currentNode = queue.top();
            queue.pop();
            
            if (closedList.find(currentNode._id) == closedList.end())
                closedList.insert(make_pair(currentNode._id, currentNode));
            else if (closedList.at(currentNode._id).total >= currentNode.total)
                closedList.at(currentNode._id) = currentNode;
            
            //Check if Node is goal
            //if (currentNode.heuristic == 0) {
            if (currentNode._id == goal._id) {
                last_id = currentNode._id;
                break;
            }

            //generate each state node_sucessor
            for (int i = 1; i <= 4; i++) {
                Node successor(currentNode.matrix, currentNode._id, i);
                if (successor.invalid)
                    continue;
                
                successor.depth = currentNode.depth + 1;
                successor.heuristic = heuristic.calculate(successor.matrix);
                successor.total = successor.heuristic + successor.depth;
                
                //Closed list
                unordered_map<size_t, Node>::const_iterator successorClosed = closedList.find(successor._id);
                if (successorClosed == closedList.end() || successorClosed->second.total > successor.total)
                    queue.push(successor);
            }
        }
        
        while (last_id != 0) {
            if (closedList.find(last_id) != closedList.end()) {
                Node n = closedList.at(last_id);
                result.push_back(n);
                last_id = n._parent;
            }
            else
                break;
        }
        
        result.reverse();
    }
    
    return result;
}