//
// Created by Hendrik Valcke on 09/05/2020.
//

#ifndef GAMEV0_1_ENEMYHORDE_H
#define GAMEV0_1_ENEMYHORDE_H


#include <vector>
#include "Alien.h"

class EnemyHorde {
//class with 3 rows of vectors with aliens
public:
    EnemyHorde(Sprite* sprite1,Sprite* sprite2,Sprite* sprite3);
    void moveHorde();
    std::vector<Alien*>* getRow(int row);
    int returnRandomRow();//returns a random row that isnt empty
    int returnRandomEnemyOnRow(int row);//returns a random enemy on given row

private:
    std::vector<Alien*> row1;
    std::vector<Alien*> row2;
    std::vector<Alien*> row3;
    bool goingRight = true;

};


#endif //GAMEV0_1_ENEMYHORDE_H
