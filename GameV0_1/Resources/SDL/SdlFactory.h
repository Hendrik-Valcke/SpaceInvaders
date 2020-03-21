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
};


#endif //GAMEV0_SDLFACTORY_H
