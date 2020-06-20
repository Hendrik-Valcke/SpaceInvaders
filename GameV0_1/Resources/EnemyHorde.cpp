//
// Created by Hendrik Valcke on 09/05/2020.
//

#include "EnemyHorde.h"

EnemyHorde::EnemyHorde(Sprite* sprite3,Sprite* sprite2,Sprite* sprite1)
{

    for (int i = 0; i < 6; ++i)
    {
        row3.push_back(new Alien( 64 + i*80, 64, 64, 64, 10, sprite3));
    }
    for (int j = 0; j < 6; ++j)
    {
        row2.push_back(new Alien( 64 + j*80, 64, 64, 64, 10, sprite2));
    }
    for (int k = 0; k < 6; ++k)
    {
        row1.push_back(new Alien( 64 + k*80, 64, 64, 64, 10, sprite1));
    }

}

