//
// Created by Hendrik Valcke on 20/06/2020.
//

#ifndef GAMEV0_1_BULLETS_H
#define GAMEV0_1_BULLETS_H


#include <vector>
#include "GameObject.h"
using namespace GameObjectSpace;
class Bullets {//vector of bullets with extra functions
public:
    Bullets(bool isHostile,Sprite* sprite); //includes sprite with texture
    void addBullet(int xPos, int yPos);
    bool checkCollision( GameObject* target); //check all the bullets from the vector and check if they collide with target
    void moveBullets();//move function from gameObject on all bullets from vector
    std::vector<GameObject*>getBulletVector();

private:
    std::vector<GameObject*> bullets;
    bool isHostile;//are the bullets from an enemy or not?
    Sprite* bulletSprite;
};


#endif //GAMEV0_1_BULLETS_H
