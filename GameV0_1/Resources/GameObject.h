//
// Created by hendr on 16/03/2020.
//

#ifndef GAMEV0_1_GAMEOBJECT_H
#define GAMEV0_1_GAMEOBJECT_H


#include "Sprite.h"

class GameObject {
public:
    GameObject();
    GameObject(int cXpos, int cYpos, int width, int height, Sprite* cSprite);
private:
    int xpos;
    int ypos;
    int width;
    int height;
    Sprite* objectSprite;

};


#endif //GAMEV0_1_GAMEOBJECT_H
