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

    //make enemies
    //EnemyHorde* enemies= new EnemyHorde(alien3Sprite,alien2Sprite, alienSprite);

    std::vector < Alien* >
            alienVector(6);
    int teller = 0;
    for (Alien* x: alienVector)
    {
        //x= new Alien( 220 + teller*64, 120, 64, 64, 10, alienSprite);
        alienVector[teller]= new Alien( 64 + teller*80, 64, 64, 64, 10, alienSprite);
        teller++;
    }
    teller = 0;

    std::vector < Alien* >
            alienVector2(6);
    for (Alien* x: alienVector2)
    {
        //x= new Alien( 220 + teller*64, 120, 64, 64, 10, alienSprite);
        alienVector2[teller]= new Alien( 64 + teller*80, 128, 64, 64, 10, alien2Sprite);
        teller++;
    }

    //Alien *alien = new Alien(0, 0, 0, 0, 0, nullptr, 220, 120, 64, 64, 10, alienSprite);

    //make player
    GameObject *player = new GameObject(520,600,64,64,20,playerSprite);
    player->setHealth(3);


    //setup is done, start gameloop
    while(isRunning)
    {
        //input + playermovement+shooting
        iHandler->handleInput();
        input = iHandler->getInput();
        if((player->getXpos()+ (-input.getLeft()+input.getRight())*player->getSpeed()>0) && (player->getXpos()+player->getWidth() + (-input.getLeft()+input.getRight())*player->getSpeed() < screen->getWidth()  ))
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
        }
        input.clearInput();

        //logica
            //check all bullets for collisions or borders
                //collision? kill objects & adjust score/health/...
            //random chance enemy shoots back
            //create enemy bullet...
            //random chance bonus spawns
        //render
        screen->applyTexture(0,0,1024,768,background );//background
        screen->renderGameObject(player);//player
            //enemies
            //bullets
            //bonus
            for (Alien* x: alienVector)
            {
                screen->renderGameObject(x);
            }
            for (Alien* x: alienVector2)
            {
                screen->renderGameObject(x);
            }

            //screen->renderGameObject(alien);
        screen->updateWindow();
    }//repeat while game IsRunning

    //stop the game
    screen->closeWindow();//close everything and free memory

}
