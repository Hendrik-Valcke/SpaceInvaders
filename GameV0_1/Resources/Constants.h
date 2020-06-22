//
// Created by Hendrik Valcke on 20/06/2020.
//

#ifndef GAMEV0_1_CONSTANTS_H
#define GAMEV0_1_CONSTANTS_H
//list of commonly used values
//window
const int SCREEN_W = 1024;
const int SCREEN_H = 768;
const int FRAMES_PER_SEC=30;
//enemies
const int ENEMIES_PER_ROW = 6;
const int ENEMY_W = 64;
const int ENEMY_H = 64;
const int ENEMY_X_START=64;
const int ENEMY_Y_START=64;
const int ENEMY_SPEED = 1;
const int MAX_EN_COOLDOWN=300;
//player
const int MAX_HEALTH = 5;
const int PLAYER_H=64;
const int PLAYER_W=64;
const int PLAYER_SPEED = 1;
const int MAX_PL_COOLDOWN=3000;
//bullets
const int BULLET_W= 32;
const int BULLET_H= 32;
const int BULLET_SPEED = 2;
//bonus
const int BONUS_H=64;
const int BONUS_W=64;
const int BONUS_START_X= 0-BONUS_W;
const int BONUS_START_Y=BONUS_H/2;
const int BONUS_SPEED=1;
//health
const int HEALTH_W=32;
const int HEALTH_H=32;
//text
const int SCORE_X=32;
const int SCORE_Y=32;
const int LEVEL_X= SCREEN_W/2;
const int LEVEL_Y=32;



#endif //GAMEV0_1_CONSTANTS_H
