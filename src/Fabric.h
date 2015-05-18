//
//  Fabric.h
//  FabricTerrain
//
//  Created by Craig Pickard on 5/18/15.
//
//

#pragma once


#include "Spring.h"
#include "Node.h"
#include <vector>
#include <stdio.h>


class Fabric{
public:
    ~Fabric();
    
    void update();
    void render();
    
    void addNode(Node *node );
    void destroyNode(Node *node);
    void addSpring(Spring *spring);
    void destroySpring(Spring *spring);
    
    std::vector<Node*> nodes;
    std::vector<Spring*> springs;
};