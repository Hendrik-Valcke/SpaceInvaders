#include "GameObject.h"

using namespace GameObjectSpace;

GameObject::GameObject(double cXpos, double cYpos, int cWidth,int cHeight,int cSpeed, Sprite* cSprite )
{
    xpos= cXpos;
    ypos= cYpos;
    width=cWidth;
    height= cHeight;
    speed = cSpeed;
    objectSprite = cSprite;
}

int GameObject::getSpeed() const {
    return speed;
}

void GameObject::setSpeed(int speed) {
    GameObject::speed = speed;
}

double GameObject::getXpos() const {
    return xpos;
}

void GameObject::setXpos(double xpos) {
    GameObject::xpos = xpos;
}

double GameObject::getYpos() const {
    return ypos;
}

void GameObject::setYpos(double ypos) {
    GameObject::ypos = ypos;
}

int GameObject::getWidth() const {
    return width;
}

void GameObject::setWidth(int width) {
    GameObject::width = width;
}

int GameObject::getHeight() const {
    return height;
}

void GameObject::setHeight(int height) {
    GameObject::height = height;
}

Sprite *GameObject::getObjectSprite() const {
    return objectSprite;
}

void GameObject::setObjectSprite(Sprite *objectSprite) {
    GameObject::objectSprite = objectSprite;
}

int GameObject::getHealth() const {
    return health;
}
void GameObject::setHealth(int health) {
    GameObject::health = health;
}
void GameObject::move(double xDistance, double yDistance) {
    xpos = xpos + xDistance * speed;
    ypos = ypos + yDistance * speed;
}





