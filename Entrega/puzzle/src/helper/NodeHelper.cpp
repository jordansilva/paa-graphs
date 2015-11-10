//
//  NodeHelper.cpp
//  puzzle
//
//  Created by Jordan Silva on 11/3/15.
//  Copyright © 2015 Jordan Silva. All rights reserved.
//

#include "NodeHelper.hpp"

bool NodeHelper::checkSolvable(Node node, int dimension) {
    int inversion = 0;
    int blankRow = -1;
    
    for (unsigned int i = 0; i < node.matrix.size(); i++) {
        if (node.matrix[i] == (char)NodeHelper::BLANK)
        {
            blankRow = i / dimension;
            continue;
        }
        
        for (unsigned int j = i+1; j < node.matrix.size(); j++) {
            if (node.matrix[j] == (char)NodeHelper::BLANK)
                continue;

            if ((int)node.matrix[i] > (int)node.matrix[j])
                inversion++;
        }
    }
    
    bool isDimensionEven = dimension%2 == 0;
    bool isBlankEven = ((dimension - blankRow) % 2) == 0;
    bool isInversionEven = inversion % 2 == 0;
    
    return (!isDimensionEven && isInversionEven) || (isDimensionEven && (isBlankEven == isInversionEven));
}