//
//  astar.cpp
//  puzzle
//
//  Created by Jordan Silva on 11/6/15.
//  Copyright © 2015 Jordan Silva. All rights reserved.
//

#include "astar.hpp"

astar::astar() {
    
}

astar::~astar() {
    
}

void astar::execute(Node initial, int dimension) {
    
    unordered_map<size_t, Node> closedList;
    priority_queue<Node, vector<Node>> queue;
    queue.push(initial);
    
    while (!queue.empty()) {
        Node currentNode = queue.top();
        queue.pop();
        closedList.insert(make_pair(currentNode._id, currentNode));
        
        //TODO: check if currNode is goal
        if (currentNode.heuristic == 0) {
            cout << "Achou Solução" << endl;
            NodeHelper::printMatrix(currentNode, dimension);
            break;
        }

        //generate each state node_sucessor
        for (int i = 1; i <= 4; i++) {
            Node successor(currentNode.matrix, currentNode._id, i);
            successor.depth = currentNode.depth + 1;

            if (successor._id == currentNode._id)
                continue;
            
            successor.heuristic = Manhattan::calculate(successor.matrix, dimension);
            successor.total = successor.heuristic + successor.depth;
            
            //Closed list
            unordered_map<size_t, Node>::const_iterator successorClosed = closedList.find(successor._id);
            if (successorClosed == closedList.end())
                queue.push(successor);
        }
    }
    
    cout << "Priority Size: " << queue.size() << endl;
    cout << "Closed Size: " << closedList.size() << endl;

}