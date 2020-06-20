//
// Created by Hendrik Valcke on 23/03/2020.
//

#ifndef GAMEV0_1_GAMECONTROLLER_H
#define GAMEV0_1_GAMECONTROLLER_H


#include "Window.h"

class GameController {
public:
    GameController() = default;

    //~GameController();

    static GameController &getInstance()
    {
        static GameController instance; // Creeër een instance
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
