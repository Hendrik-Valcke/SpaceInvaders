//
// Created by Hendrik Valcke on 09/05/2020.
//

#include "EnemyHorde.h"

#include "Constants.h"
EnemyHorde::EnemyHorde(Sprite* sprite3,Sprite* sprite2,Sprite* sprite1)
{

    for (int i = 0; i < 6; ++i)
    {
        row3.push_back(new Alien( ENEMY_X_START + i*3*ENEMY_W/2, ENEMY_Y_START, ENEMY_W, ENEMY_H, ENEMY_SPEED, sprite3));
    }
    for (int j = 0; j < 6; ++j)
    {
        row2.push_back(new Alien( ENEMY_X_START + j*3*ENEMY_W/2, 2*ENEMY_Y_START, ENEMY_W, ENEMY_H, ENEMY_SPEED, sprite2));
    }
    for (int k = 0; k < 6; ++k)
    {
        row1.push_back(new Alien( ENEMY_X_START + k*3*ENEMY_W/2, 3*ENEMY_Y_START, ENEMY_W, ENEMY_H, ENEMY_SPEED, sprite1));
    }
}

std::vector<Alien*> EnemyHorde::getRow(int row)
{
    switch(row) {
        case 1:
            return row1;
            break;
        case 2:
            return row2;
            break;
        case 3:
            return row3;
            break;
        default:
            return row3;
    }
}

void EnemyHorde::moveHorde()
{
    if (goingRight)
    {
        if( (row3[row3.size()-1]->getXpos() + ENEMY_W < SCREEN_W  )  or (row2[row2.size()-1]->getXpos() + ENEMY_W < SCREEN_W) or (row1[row1.size()-1]->getXpos() + ENEMY_W < SCREEN_W))
        {
            for (Alien* x: row3)
            {
                x->move(1,0);
            }
            for (Alien* x: row2)
            {
                x->move(1,0);
            }
            for (Alien* x: row1)
            {
                x->move(1,0);
            }
        } else
        {
            goingRight = false;
            if(row1[0]->getYpos() + ENEMY_H < SCREEN_H - 3*ENEMY_H or row2[0]->getYpos() + ENEMY_H < SCREEN_H - 3*ENEMY_H or row1[0]->getYpos() + ENEMY_H < SCREEN_H - 3*ENEMY_H)
            {
                for (Alien* x: row3)
                {
                    x->move(0,10);
                }
                for (Alien* x: row2)
                {
                    x->move(0,10);
                }
                for (Alien* x: row1)
                {
                    x->move(0,10);
                }
            }
        }

    } else
    {
        if((row3[0]->getXpos() > 0) or (row2[0]->getXpos() > 0) or (row1[0]->getXpos() > 0))
        {
            for (Alien* x: row3)
            {
                x->move(-1,0);
            }
            for (Alien* x: row2)
            {
                x->move(-1,0);
            }
            for (Alien* x: row1)
            {
                x->move(-1,0);
            }
        } else
        {
            goingRight = true;
            if(row1[0]->getYpos() + ENEMY_H < SCREEN_H - 3*ENEMY_H or row2[0]->getYpos() + ENEMY_H < SCREEN_H - 3*ENEMY_H or row1[0]->getYpos() + ENEMY_H < SCREEN_H - 3*ENEMY_H)
            {
                for (Alien* x: row3)
                {
                    x->move(0,10);
                }
                for (Alien* x: row2)
                {
                    x->move(0,10);
                }
                for (Alien* x: row1)
                {
                    x->move(0,10);
                }
            }
        }
    }


}

