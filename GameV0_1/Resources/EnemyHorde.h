//
// Created by Hendrik Valcke on 09/05/2020.
//

#ifndef GAMEV0_1_ENEMYHORDE_H
#define GAMEV0_1_ENEMYHORDE_H


#include <vector>
#include "Alien.h"

class EnemyHorde {
public:
    EnemyHorde(Sprite* sprite1,Sprite* sprite2,Sprite* sprite3);

private:
    std::vector<Alien*> row1;
    std::vector<Alien*> row2;
    std::vector<Alien*> row3;
};


#endif //GAMEV0_1_ENEMYHORDE_H
