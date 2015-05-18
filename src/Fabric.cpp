//
//  Fabric.cpp
//  FabricTerrain
//
//  Created by Craig Pickard on 5/18/15.
//
//

#include "Fabric.h"

Fabric::~Fabric(){
    for( std::vector<Node*>::iterator it = nodes.begin(); it != nodes.end(); ++it ){
        delete *it;
    }
    nodes.clear();
}

void Fabric::update(){
    for( std::vector<Node*>::iterator it = nodes.begin(); it != nodes.end(); ++it){
        (*it)->update();
    }
    for (std::vector<Spring*>::iterator it = springs.begin(); it != springs.end(); ++it){
        (*it)->update();
    }
}

void Fabric::render(){
    
    for( std::vector<Node*>::iterator it = nodes.begin(); it != nodes.end(); ++it ){
        (*it)->render();
    }
    
        for( std::vector<Spring*>::iterator it =
            springs.begin(); it != springs.end(); ++it ){
            (*it)->render();
        }
}

void Fabric::addNode(Node *node){
    nodes.push_back(node);
}

void Fabric::destroyNode(Node *node){
    std::vector<Node*>::iterator it = std::find( nodes.begin(), nodes.end(), node );
    delete *it;
    nodes.erase( it );
}

void Fabric::addSpring(Spring *spring){
    springs.push_back(spring);
}

void Fabric::destroySpring(Spring *spring){
    std::vector<Spring*>::iterator it; std::find(springs.begin(), springs.end(), spring);
    delete *it;
    springs.erase(it);
}