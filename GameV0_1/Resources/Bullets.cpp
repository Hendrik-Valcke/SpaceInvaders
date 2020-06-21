//
// Created by Hendrik Valcke on 20/06/2020.
//

#include "Bullets.h"
Bullets::Bullets(bool hostile,Sprite* sprite)
{
    isHostile = hostile;
    bulletSprite = sprite;
}
void Bullets::addBullet(int xPos, int yPos)
{
    bullets.push_back(new GameObject(xPos,yPos, BULLET_W, BULLET_H, BULLET_SPEED,bulletSprite));
}
bool Bullets::checkCollision(GameObject* target)
{
    int index = 0;
    while (index < bullets.size())
    {
        if (bullets[index]->getXpos()+BULLET_W <=0 or bullets[index]->getXpos() >= SCREEN_W or bullets[index]->getYpos()+BULLET_H <=0 or bullets[index]->getYpos() >= SCREEN_H )//only counts when the WHOLE bullet passed the border
        {
            bullets.erase(bullets.begin()+index);//if the bullet passes the border, delete bullet
        } else
        {//check for collsion with target
            if (bullets[index]->getXpos()+BULLET_W >= target->getXpos() //most right pixel of bullet 'is more right than'/=  most left pixel of target
                and bullets[index]->getXpos()<= target->getXpos()+target->getWidth() //most left pixel of bullet 'is more left than'/= most right pixel of target
                and bullets[index]->getYpos() + BULLET_H >= target->getYpos() //bottom pixel of bullet is lower/= top pixel of target
                and bullets[index]->getYpos() <= target->getYpos()+target->getWidth()) //top pixel of bullet is higher/= bottom pixel of target
            {
                bullets.erase(bullets.begin()+index);//if the bullet hits, delete bullet and return true
                return true;
            }
            index++;//no hit? continue iterating through bullets
        }
    }
    return false;//after iterating without collisions
    /*for (GameObject* x: bullets)
    {//y is higher towards bottom of screen
        //first: check if bullet is still within the borders of the screen
        if (x->getXpos()+BULLET_W <=0 or x->getXpos() >= SCREEN_W or x->getYpos()+BULLET_H <=0 or x->getYpos() >= SCREEN_H )//only counts when the WHOLE bullet passed the border
        {
            bullets.erase(bullets.begin()+index);//if the bullet passes the border, delete bullet
        } else
        {//check for collsion with target
            if (x->getXpos()+BULLET_W >= target->getXpos() //most right pixel of bullet 'is more right than'/=  most left pixel of target
                and x->getXpos()<= target->getXpos()+target->getWidth() //most left pixel of bullet 'is more left than'/= most right pixel of target
                and x->getYpos() + BULLET_H >= target->getYpos() //bottom pixel of bullet is lower/= top pixel of target
                and x->getYpos() <= target->getYpos()+target->getWidth()) //top pixel of bullet is higher/= bottom pixel of target
            {
                bullets.erase(bullets.begin()+index);//if the bullet hits, delete bullet and return true
                return true;
            }
            index++;//no hit? continue iterating through bullets
        }
    }*/

}
void Bullets::moveBullets()
{
    if (isHostile)//bullets go down so y increases
    {
        for (GameObject* x: bullets)
        {
            x->move(0,1);
        }
    } else //bullets go up so y decreases
    {
        for (GameObject* x: bullets)
        {
            x->move(0,-1);
        }
    }
}
std::vector<GameObject*> Bullets::getBulletVector()
{
    return bullets;
}