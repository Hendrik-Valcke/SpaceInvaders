//
// Created by Hendrik Valcke on 20/04/2020.
//

#ifndef GAMEV0_1_ALIEN_H
#define GAMEV0_1_ALIEN_H


#include "GameObject.h"

class Alien : public GameObject{
public:
    Alien(double cXpos, double cYpos, int cWidth, int cHeight, int cSpeed, Sprite *cSprite) ;
    //void move(double xDistance, double yDistance);
};


#endif //GAMEV0_1_ALIEN_H
