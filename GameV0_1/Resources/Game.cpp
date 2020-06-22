//
// Created by hendr on 02/03/2020.
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "Game.h"
#include "GameObject.h"
#include "GameController.h"
#include "Alien.h"
#include "EnemyHorde.h"
#include "Bullets.h"
#include "Text.h"

Game::Game(Factory *cFactory)
{
    factory =cFactory;
}

void Game::startGame()
{
    //let factory create window
    Window* screen = factory->createWindow();
    if(!screen->makeWindow())
    {
        isRunning= false;
        printf("\nWindow could not be created");
    }
    else
    {
        printf("\nWindow succesfully created");
        isRunning = true;
    }
    GameController::getInstance().setWindow(screen);

    //let factory create inputHandler
    InputHandler* iHandler=factory->createInputHandler();
    Input input;
    //some base values
    score=0;
    setupLevel(1);//set up all fields to correct value for level 1
    //let factory make Text for score - is indepenant from level
    scoreText = factory->createText("Score: 0",SCORE_X,SCORE_Y,20,"Fonts/8BitMadness.ttf");
    uint32_t catchupTime=0;//buffervalue for fps

    //setup is done, start gameloop
    while(isRunning)
    {
        //check if level should be ended - start new level?
        if(enemies->getRow(1)->empty() and enemies->getRow(2)->empty() and enemies->getRow(3)->empty())//all enemies are dead - go to next level
        {
            setupLevel(level+1);
        } else if (player->getHealth()<=0) //player died - reset to level 1
        {
            setupLevel(1);
            score=0;
        } else
        {
            //start timer for start of frame/gameLoopIteration
            uint32_t framestart = screen->sendTicks();
            //counters
            frameCounter++;
            if (frameCounter> 600)
            {frameCounter=0;}//to stop it from overflowing
            if (playerCooldDown >0)
            {
                playerCooldDown--;
            }
            if (enemyCoolDown >0)
            {
                enemyCoolDown--;
            }
            if (rapidFire >0)
            {
                rapidFire--;
            }

            //input + playermovement+shooting
            input.clearInput();
            iHandler->handleInput();
            input = iHandler->getInput();
            if (frameCounter%10==0)//move player every 10 frames (when required)
            {
                //check for border
                if (input.getRight()==1 and input.getLeft()==0 and player->getXpos()+player->getWidth()+player->getSpeed()<SCREEN_W)//going right
                {
                    player->move(1,0);
                } else if (input.getRight()==0 and input.getLeft()==1 and player->getXpos()-player->getSpeed()>0)
                {
                    player->move(- 1,0);
                }
            }

            if (input.isQuit())
            {
                isRunning = false;
            }
            if(input.isFire() and playerCooldDown<=0)
            {
                //make player bullet...
                playerBullets->addBullet(player->getXpos(),player->getYpos());
                if (rapidFire>0)
                {
                    playerCooldDown=MAX_PL_COOLDOWN/3;
                } else
                {
                    playerCooldDown=MAX_PL_COOLDOWN;
                }
            }
            //logica

            //move objects every 30 frames
            if (frameCounter % 30 == 0)
            {
                enemies->moveHorde();
                playerBullets->moveBullets();
                enemyBullets->moveBullets();
                if (bonus->getHealth()==1)//if there is a bonus alive
                {
                    if(bonus->getXpos()+BONUS_W>=0)
                    {
                        bonus->move(1,0);
                    } else
                    {
                        bonus->setHealth(0);
                    }
                }
            }
            //chance for enemyBullet every 60 frames
            if (enemyCoolDown<=0 and (frameCounter+10)% 60 == 0)
            {
                //random chance enemy shoots back
                if (!(enemies->getRow(1)->empty() and enemies->getRow(2)->empty() and enemies->getRow(3)->empty()))
                {
                    if (rand()%(100/level)==1)
                    {
                        int randomRow = enemies->returnRandomRow();
                        int randomEnemy = enemies->returnRandomEnemyOnRow(randomRow);
                        enemyBullets->addBullet(enemies->getRow(randomRow)->at(randomEnemy)->getXpos(),enemies->getRow(randomRow)->at(randomEnemy)->getYpos()); //create enemy bullet...
                        enemyCoolDown=MAX_EN_COOLDOWN;
                    }
                }
            }

            //chance for bonus every 60 frames
            if ((frameCounter+20)%60 == 0)
            {
                if (bonus->getHealth()==0)//only if there is no bonus alive
                {
                    if (rand()%2000==1)
                    {
                        bonus->setHealth(1);
                        bonus->setSpeed(-1);
                        bonus->setXpos(SCREEN_W);//right of screen
                    }
                }
            }
            //check all bullets for collisions or borders
            //collision? kill objects & adjust score/health/...
            for (int i = 1; i <= 3; ++i)
            {
                int index = 0;
                while(index < enemies->getRow(i)->size())
                {
                    if (playerBullets->checkCollision(enemies->getRow(i)->at(index)))
                    {
                        //collision? delete enemy
                        enemies->getRow(i)->erase(enemies->getRow(i)->begin()+index);//if an enemy gets deleted, the next one will appear at the same index so no i++
                        //adjust score
                        score= score+i*10;
                    } else
                    {
                        index++;//if no enemy gets deleted, go to next index
                    }
                }
            }
            if (bonus->getHealth()==1)
            {
                if (playerBullets->checkCollision(bonus))
                {
                    bonus->setHealth(0);
                    rapidFire= rapidFire+15000;
                    if (player->getHealth()+1< MAX_HEALTH)
                    {
                        player->setHealth(player->getHealth()+1);
                    }
                }
            }
            if (enemyBullets->checkCollision(player))
            {
                player->setHealth(player->getHealth()-1);
            }

            //render
            screen->applyTexture(0,0,SCREEN_W,SCREEN_H,background );//background
            for (int j = 0; j < player->getHealth(); ++j)
            {
                screen->applyTexture(SCREEN_W -3*HEALTH_W-j*HEALTH_W,HEALTH_H,HEALTH_W,HEALTH_H, healthSprite);//health
            }
            screen->renderGameObject(player);//player
            //enemies
            for (int i = 1; i <= 3; ++i)
            {
                for (Alien* x: *enemies->getRow(i))
                {
                    screen->renderGameObject(x);
                }
            }
            //bullets
            for (GameObject* x: playerBullets->getBulletVector())
            {
                screen->renderGameObject(x);
            }
            for (GameObject* x: enemyBullets->getBulletVector())
            {
                screen->renderGameObject(x);
            }
            //bonus
            if(bonus->getHealth()==1)
            {
                screen->renderGameObject(bonus);
            }

            //text
            if(frameCounter%30==0)
            {
                scoreText->setText("Score: "+ std::to_string(score));
            }

            screen->applyTextTexture(scoreText);
            screen->applyTextTexture(levelText);
            //last step of loop:
            //calculate time passed during this iteration of gameLoop
            uint32_t timePassed = screen->sendTicks()-framestart;
            //if timePassed < frametime: wait, if previous frames were too slow-> compensate to improve consistenct across multiple frames
            if (timePassed < FRAMES_PER_SEC/1000)
            {
                screen->delayFrame(FRAMES_PER_SEC/1000-timePassed/*-catchupTime*/);
                catchupTime = 0;
            }
            else //timePassed > frameDuration
            {
                catchupTime = (timePassed-catchupTime-FRAMES_PER_SEC/1000);
                //if the previous frames took way too long, catchupTime could become negative
                if (catchupTime<0)
                {
                    catchupTime = 0;
                }
            }
            screen->updateWindow();
        }

    }//repeat while game IsRunning

    //stop the game
    screen->closeWindow();//close everything and free memory

}

void Game::setupLevel(int lvl)
{
    level=lvl;
    frameCounter=0;
    playerCooldDown=MAX_PL_COOLDOWN;
    enemyCoolDown=MAX_EN_COOLDOWN;
    rapidFire=0;
    background =factory->createSprite("Sprites/spaceTheme/background.png");
    playerSprite =factory->createSprite("Sprites/spaceTheme/playerShip.png");
    alien1Sprite =factory->createSprite("Sprites/spaceTheme/alien.png");
    alien2Sprite =factory->createSprite("Sprites/spaceTheme/alien2.png");
    alien3Sprite =factory->createSprite("Sprites/spaceTheme/alien3.png");
    bulletSprite =factory->createSprite("Sprites/spaceTheme/bullet.png");
    enemyBulletSprite =factory->createSprite("Sprites/spaceTheme/enemyBullet.png");
    bonusSprite =factory->createSprite("Sprites/spaceTheme/bonusGreen.png");
    healthSprite =factory->createSprite("Sprites/spaceTheme/life.png");

    enemies= new EnemyHorde(alien3Sprite,alien2Sprite, alien1Sprite);
    player = new GameObject(SCREEN_W/2,SCREEN_H -2*PLAYER_H ,PLAYER_W,PLAYER_H,PLAYER_SPEED,playerSprite);
    player->setHealth(MAX_HEALTH);
    bonus = new GameObject(BONUS_START_X, BONUS_START_Y, BONUS_W ,BONUS_H,BONUS_SPEED,bonusSprite);
    bonus->setHealth(0);
    enemyBullets = new Bullets(true, enemyBulletSprite);
    playerBullets = new Bullets(false, bulletSprite);

    levelText = factory->createText("Level 1",LEVEL_X,LEVEL_Y,20,"Fonts/8BitMadness.ttf");
    levelText->setText("Level:" + std::to_string(level));

}
