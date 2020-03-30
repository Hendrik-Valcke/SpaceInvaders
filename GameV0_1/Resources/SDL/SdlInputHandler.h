//
// Created by hendr on 09/03/2020.
//

#ifndef GAMEV0_SDLINPUTHANDLER_H
#define GAMEV0_SDLINPUTHANDLER_H


#include "../InputHandler.h"
#include "../Input.h"

class SdlInputHandler : public InputHandler{
public:
    //SdlInputHandler();
    //~SdlInputHandler();
    void handleInput() override ;
    Input getInput() override { return input;}

private:
    Input input;
};


#endif //GAMEV0_SDLINPUTHANDLER_H
