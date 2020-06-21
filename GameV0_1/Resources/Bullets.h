//
// Created by Hendrik Valcke on 20/06/2020.
//

#ifndef GAMEV0_1_BULLETS_H
#define GAMEV0_1_BULLETS_H


#include <vector>
#include "GameObject.h"

class Bullets {
public:
    Bullets(bool isHostile,Sprite* sprite);
    void addBullet(int xPos, int yPos);
    bool checkCollision( GameObject* target);
    void moveBullets();
    std::vector<GameObject*>getBulletVector();

private:
    std::vector<GameObject*> bullets;
    bool isHostile;
    Sprite* bulletSprite;
};


#endif //GAMEV0_1_BULLETS_H
