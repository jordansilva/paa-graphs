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
    
    unordered_map<size_t, Node> openList;
    unordered_map<size_t, Node> closedList;
    priority_queue<Node, vector<Node>> queue;
    queue.push(initial);
    
    while (!queue.empty()) {
        Node currentNode = queue.top();
        queue.pop();
        openList.erase(currentNode._id);
        closedList.insert(make_pair(currentNode._id, currentNode));

        
//        for (int x = 0; x < currentNode.matrix.size(); x++) {
//            if (currentNode.matrix[x] == 95)
//                cout << currentNode.matrix[x] << " ";
//            else
//                cout << (int)currentNode.matrix[x] << " ";
//        }
//        cout << currentNode.getMovementLabel();
//        cout << endl;
        
//        cout << "-----------" << endl;
//        cout << "current" << endl;
//        NodeHelper::printMatrix(currentNode, dimension);
//        cout << endl;
        
        //TODO: check if currNode is goal
        if (currentNode.heuristic == 0) {
            cout << "Achou Solução" << endl;
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
            
            //Open list
            unordered_map<size_t, Node>::const_iterator successorOpen = openList.find(successor._id);
            if (successorOpen != openList.end())
            {
                Node tmp = successorOpen->second;
                if (tmp.getDistance() < successor.getDistance())
                    continue;
                else
                    openList.erase(successorOpen->first);
            }
            
            //Closed list
            unordered_map<size_t, Node>::const_iterator successorClosed = closedList.find(successor._id);
            if (successorClosed != closedList.end())
            {
                Node tmp = successorClosed->second;
                if (tmp.getDistance() < successor.getDistance())
                    continue;
                else
                    closedList.erase(successorClosed->first);
            }
            
            //set parent (already seted)
            //set h to be estimated distance to node_goal
            
            //add node to open list
            //NodeHelper::printMatrix(successor, dimension);
            
            openList.insert(make_pair(successor._id, successor));
            queue.push(successor);
        }
        
    }
    
    cout << "Priority Size: " << queue.size() << endl;
    cout << "Open Size: " << openList.size() << endl;
    cout << "Closed Size: " << closedList.size() << endl;

}