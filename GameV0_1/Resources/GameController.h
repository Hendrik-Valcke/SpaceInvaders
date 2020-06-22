//
// Created by Hendrik Valcke on 23/03/2020.
//

#ifndef GAMEV0_1_GAMECONTROLLER_H
#define GAMEV0_1_GAMECONTROLLER_H

#include "Window.h"
using namespace windowSpace;
class GameController {//used for when sdl objects have to interact with each other
public:
    GameController() = default;


    static GameController &getInstance()
    {
        static GameController instance; // 1 instance
        return instance;
    }

    GameController(GameController const &) = delete;

    void operator=(GameController const &) = delete;

    void setWindow(Window *sWindow){fWindow=sWindow;}
    Window* getWindow(){return fWindow;}


private:
    Window* fWindow;

};


#endif //GAMEV0_1_GAMECONTROLLER_H
