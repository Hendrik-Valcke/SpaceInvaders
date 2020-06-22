//
// Created by hendr on 02/03/2020.
//

#ifndef GAMEV0_GAME_H
#define GAMEV0_GAME_H

#include "Factory.h"
#include "EnemyHorde.h"
#include "Bullets.h"

class Game {
public:
    Game(Factory *cFactory);//constructor
        void startGame(); //starts game.
        void setupLevel(int level);//puts everything in starting position

private:
    Factory *factory;
    bool isRunning;
    int playerCooldDown;
    int enemyCoolDown;
    int score;
    int level;
    int frameCounter;
    int rapidFire;
    //sprites
    Sprite* background;
    Sprite* playerSprite;
    Sprite* alien1Sprite;
    Sprite* alien2Sprite;
    Sprite* alien3Sprite;
    Sprite* bulletSprite;
    Sprite* enemyBulletSprite;
    Sprite* bonusSprite;
    Sprite* healthSprite;
    //GameObjects
    EnemyHorde* enemies;
    GameObject *player;
    GameObject *bonus;
    Bullets* enemyBullets;
    Bullets* playerBullets;
    //text
    Text* scoreText;
    Text* levelText;

};


#endif //GAMEV0_GAME_H
