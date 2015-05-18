#include "Node.h"

using namespace ci;
using namespace ci::app;

Node::Node(const vec3& loc){
    this->mLoc = loc;
    isLocked = false;
    mVel = vec3(0.,0.,0.);
    
    maxVel = 5.;
    damping = 1.;
}


void Node::repel(vec3 force)
{
  //  float dist = distance(mLoc,force);
}


void Node::update(){
    if (isLocked == false){
        /*
        float d = distance(mLoc, _pos);
        if (d < 5){
            mVel += _force;
        }
        mLoc += mVel;
        mVel *= (1 - damping);
         */
    }
}

void Node::render(){
    gl::color(ColorA(1.,1.,1.,1.));
    gl::pointSize(2.);
    gl::vertex(mLoc);
    gl::drawSphere(mLoc, 1);
   // gl::drawSolidRect(Rectf()
}

float Node::getX(){
    return mLoc.x;
}

float Node::getY(){
    return mLoc.y;
}

float Node::getZ(){
    return mLoc.z;
}

void Node::setDamping(float _damping){
    damping = _damping;
}

void Node::lock(){
    isLocked = !isLocked;
}
