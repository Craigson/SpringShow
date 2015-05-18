//
//  Spring.h
//  FabricTerrain
//
//  Created by Craig Pickard on 5/17/15.
//
//

#pragma once
#include "Node.h"

class Spring {
public:
    
    Spring (Node *from, Node *to, float restLength, float stiffness, float damping);
    
    void update();
    
    void render();
    
    void setLength(float restLength);
    
    void setStiffness(float stiffness);
    
    void setDamping(float damping);
    
    Node *from;
    Node *to;
    
    float restLength;
    float stiffness;
    float damping;
    
};