//
//  Spring.cpp
//  FabricTerrain
//
//  Created by Craig Pickard on 5/17/15.
//
//

#include "Spring.h"

using namespace ci;
using namespace ci::app;


Spring::Spring(Node *from, Node *to, float restLength, float stiffness, float damping){
    
    this->from = from;
    this->to = to;
    this->restLength = restLength;
    this->stiffness = stiffness;
    this->damping = damping;
    
}

void Spring::update(){
    vec3 diff = to->mLoc - from->mLoc;
    diff = normalize(diff);
    diff *= restLength;
    vec3 target = from->mLoc + diff;
    vec3 force = target - to->mLoc;
    force *= 0.5;
    force *= stiffness;
    force *= 1 - damping;
    to->mVel += force;
    vec3 oppForce = (force *= -1);
    from->mVel += oppForce;
}


void Spring::render(){
    gl::enableAlphaBlending();
    gl::color( ci::ColorA(1.f,1.f,1.f, 0.05f) );
    gl::lineWidth(0.10);
    gl::enable(GL_LINE_SMOOTH);
    gl::drawLine(from->mLoc, to->mLoc);
}

/*
void Spring::setLength(float restLength);
    
void Spring::setStiffness(float stiffness);
    
void Spring::setDamping(float damping);
 */
    