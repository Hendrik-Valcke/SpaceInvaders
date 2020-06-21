//
// Created by hendr on 02/03/2020.
//

#include <iostream>
#include <vector>
#include "Game.h"
#include "GameObject.h"
#include "GameController.h"
#include "Alien.h"
#include "EnemyHorde.h"
#include "Bullets.h"

Game::Game(Factory *cFactory)
{
    factory =cFactory;
}

void Game::startGame()
{
    //create window
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

    //set up inputHandler
    InputHandler* iHandler=factory->createInputHandler();
    Input input;

    //load sprites
    Sprite* background =factory->createSprite("Sprites/spaceTheme/background.png");
    Sprite* playerSprite =factory->createSprite("Sprites/spaceTheme/playerShip.png");
    Sprite* alienSprite =factory->createSprite("Sprites/spaceTheme/alien.png");
    Sprite* alien2Sprite =factory->createSprite("Sprites/spaceTheme/alien2.png");
    Sprite* alien3Sprite =factory->createSprite("Sprites/spaceTheme/alien3.png");
    Sprite* bulletSprite =factory->createSprite("Sprites/spaceTheme/bullet.png");
    Sprite* enemyBulletSprite =factory->createSprite("Sprites/spaceTheme/enemyBullet.png");
    Sprite* bonusSprite =factory->createSprite("Sprites/spaceTheme/bonusGreen.png");

    //make enemies (bottom row is row1...)
    EnemyHorde* enemies= new EnemyHorde(alien3Sprite,alien2Sprite, alienSprite);

    //make player
    GameObject *player = new GameObject(SCREEN_W/2,SCREEN_H -2*PLAYER_H ,PLAYER_W,PLAYER_H,PLAYER_SPEED,playerSprite);
    player->setHealth(3);

    //make bulletVectors
    Bullets* enemyBullets = new Bullets(true, enemyBulletSprite);
    Bullets* playerBullets = new Bullets(false, bulletSprite);
    int frameCounter=0;
    uint32_t catchupTime;

    //setup is done, start gameloop
    while(isRunning)
    {
        //start timer for start of frame/gameLoopIteration
        uint32_t framestart = screen->sendTicks();

        //input + playermovement+shooting
        iHandler->handleInput();
        input = iHandler->getInput();
        //check for border
        if((player->getXpos() + (-input.getLeft()+input.getRight())*player->getSpeed()>0) && (player->getXpos()+player->getWidth() + (-input.getLeft()+input.getRight())*player->getSpeed() < screen->getWidth()))
        {
            player->setXpos(player->getXpos() +(-input.getLeft()+input.getRight()) * player->getSpeed());
        }
        else
        {
            player->setXpos(player->getXpos()+(-input.getLeft()+input.getRight())*__min(player->getXpos()-1,screen->getWidth()-(player->getXpos()+player->getWidth())));
        }
        if (input.isQuit())
        {
            isRunning = false;
        }
        if(input.isFire())
        {
            //make player bullet...
            playerBullets->addBullet(player->getXpos(),player->getYpos());
        }
        input.clearInput();

        //logica
            //move objects every 20 frames
            frameCounter++;
            if (frameCounter % 20 == 0)
            {
                enemies->moveHorde();
                playerBullets->moveBullets();
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
                } else
                {
                    index++;//if no enemy gets deleted, go to next index
                }
            }
        }

            //random chance enemy shoots back
                //create enemy bullet...
            //random chance bonus spawns

        //render
        screen->applyTexture(0,0,SCREEN_W,SCREEN_H,background );//background
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
            //bonus
        //last step of loop:
        //calculate time passed during this iteration of gameLoop
        uint32_t timePassed = screen->sendTicks()-framestart;
        //if timePassed < frametime: wait, if previous frames were too slow-> compensate to improve consistenct across multiple frames
        if (timePassed < FRAMES_PER_SEC/1000)
        {
            screen->delayFrame(FRAMES_PER_SEC/1000-timePassed-catchupTime);
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
    }//repeat while game IsRunning

    //stop the game
    screen->closeWindow();//close everything and free memory

}
