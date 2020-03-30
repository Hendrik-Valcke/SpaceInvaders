//
// Created by hendr on 09/03/2020.
//

#ifndef GAMEV0_INPUTHANDLER_H
#define GAMEV0_INPUTHANDLER_H


#include "Input.h"

class InputHandler {
public:
    virtual void handleInput()=0;
    virtual Input getInput()=0;
};


#endif //GAMEV0_INPUTHANDLER_H
