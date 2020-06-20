//
// Created by Hendrik Valcke on 20/06/2020.
//

#ifndef GAMEV0_1_BULLETS_H
#define GAMEV0_1_BULLETS_H


#include <vector>
#include "GameObject.h"

class Bullets {
public:
    void addBullet(int xPos, int yPos);
    void checkCollision( GameObject target);

private:
    std::vector<GameObject*> Bullets;
    bool isHostile;
};


#endif //GAMEV0_1_BULLETS_H
