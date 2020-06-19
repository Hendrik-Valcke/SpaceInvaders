//
// Created by hendr on 02/03/2020.
//

#ifndef GAMEV0_FACTORY_H
#define GAMEV0_FACTORY_H

#include "Window.h"
#include "InputHandler.h"

class Factory {
public:
    virtual Window* createWindow()=0;
    virtual InputHandler* createInputHandler()=0;
    virtual Sprite* createSprite(std::string cPath)=0;
    //virtual void spawnEnemies()=0;

};

#endif //GAMEV0_FACTORY_H
