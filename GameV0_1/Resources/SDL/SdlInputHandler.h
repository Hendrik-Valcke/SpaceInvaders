//
// Created by hendr on 09/03/2020.
//

#ifndef GAMEV0_SDLINPUTHANDLER_H
#define GAMEV0_SDLINPUTHANDLER_H


#include "../InputHandler.h"
#include "../Input.h"
using namespace inputSpace;
using namespace inputHandlerSpace;
namespace sdlInputHandlerSpace{
class SdlInputHandler : public InputHandler{
public:

    void handleInput() override ;
    Input getInput() override { return input;}

private:
    Input input;
};
}

#endif //GAMEV0_SDLINPUTHANDLER_H
