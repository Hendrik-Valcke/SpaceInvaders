//
// Created by hendr on 09/03/2020.
//

#ifndef GAMEV0_INPUTHANDLER_H
#define GAMEV0_INPUTHANDLER_H


#include "Input.h"
using namespace inputSpace;
namespace inputHandlerSpace{
class InputHandler {//handles the input object
public:
    virtual void handleInput()=0;
    virtual Input getInput()=0;
};
}

#endif //GAMEV0_INPUTHANDLER_H
