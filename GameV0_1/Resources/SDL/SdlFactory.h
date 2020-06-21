//
// Created by hendr on 02/03/2020.
//

#ifndef GAMEV0_SDLFACTORY_H
#define GAMEV0_SDLFACTORY_H


#include "../Window.h"
#include "../Factory.h"

class SdlFactory: public Factory{
    Window* createWindow() override;
    InputHandler* createInputHandler() override ;
    Sprite* createSprite(std::string cPath) override ;
    Text* createText(std::string text, int x, int y, int fontSize, std::string font) override ;
};


#endif //GAMEV0_SDLFACTORY_H
