//
// Created by hendr on 16/03/2020.
//

#ifndef GAMEV0_1_GAMEOBJECT_H
#define GAMEV0_1_GAMEOBJECT_H
#include "Sprite.h"
#include "Constants.h"

class GameObject {
public:
    //GameObject();
    GameObject(double cXpos, double cYpos, int width, int height,int speed, Sprite* cSprite);

    void moveObject(bool left, bool up);
    void shoot(bool direction);

    int getSpeed() const;

    void setSpeed(int xpos);

    double getXpos() const;

    void setXpos(double xpos);

    double getYpos() const;

    void setYpos(double ypos);

    int getWidth() const;

    void setWidth(int width);

    int getHeight() const;

    void setHeight(int height);

    Sprite *getObjectSprite() const;

    void setObjectSprite(Sprite *objectSprite);

    int getHealth() const;

    void setHealth(int health);

protected:
    int xpos;
    int ypos;
    int width;
    int height;
    int speed;
    int health;
    Sprite* objectSprite;

};


#endif //GAMEV0_1_GAMEOBJECT_H
