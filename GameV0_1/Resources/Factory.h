//
// Created by hendr on 02/03/2020.
//

#ifndef GAMEV0_FACTORY_H
#define GAMEV0_FACTORY_H

#include "Window.h"
#include "InputHandler.h"
#include "Text.h"
using namespace windowSpace;
using namespace inputHandlerSpace;
class Factory {//the abstract factory
public:
    virtual Window* createWindow()=0;
    virtual InputHandler* createInputHandler()=0;
    virtual Sprite* createSprite(std::string cPath)=0;
    virtual Text* createText(std::string text, int x, int y, int fontSize, std::string font) = 0;

};

#endif //GAMEV0_FACTORY_H
