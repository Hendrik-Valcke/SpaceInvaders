//
// Created by hendr on 02/03/2020.
//

#ifndef GAMEV0_GAME_H
#define GAMEV0_GAME_H

#include "Factory.h"

class Game {
public:
    Game(Factory *cFactory);//constructor
    void runScreen();//screen
    void setFactory(Factory* sFactory);
private:
    Factory *factory;

};


#endif //GAMEV0_GAME_H
