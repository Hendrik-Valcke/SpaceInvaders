//
// Created by Hendrik Valcke on 20/04/2020.
//

#include "Alien.h"
Alien::Alien( double cXpos, double cYpos, int cWidth, int cHeight, int cSpeed, Sprite *cSprite) : GameObject(cXpos, cYpos, cWidth, cHeight, cSpeed, cSprite) {

}
void Alien::move(double xDistance, double yDistance)
{
    this->setXpos(this->getXpos()+xDistance*this->getSpeed());
    this->setYpos(this->getYpos()+yDistance*this->getSpeed());
}