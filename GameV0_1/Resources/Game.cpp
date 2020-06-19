//
// Created by hendr on 02/03/2020.
//

#include <iostream>
#include <vector>
#include "Game.h"
#include "GameObject.h"
#include "GameController.h"
#include "Alien.h"

Game::Game(Factory *cFactory)
{
    factory =cFactory;
}
void Game::setFactory(Factory* sFactory)
{
    factory = sFactory;
}
void Game::runScreen()
{

}

void Game::startGame()
{
    //create window
    Window* screen = factory->createWindow();
    GameController::getInstance().setWindow(screen);
    //set up inputHandler
    InputHandler* iHandler=factory->createInputHandler();
    Input input;
    if(!screen->makeWindow())
    {
        isRunning= false;
        printf("\nWindow could not be created");
    }else
    {
        printf("\nWindow succesfully created");
    }
    //load sprites
    Sprite* background =factory->createSprite("Sprites/spaceTheme/background.png");
    Sprite* playerSprite =factory->createSprite("Sprites/spaceTheme/playerShip.png");
    Sprite* alienSprite =factory->createSprite("Sprites/spaceTheme/alien.png");
    Sprite* alien2Sprite =factory->createSprite("Sprites/spaceTheme/alien2.png");
    Sprite* bulletSprite =factory->createSprite("Sprites/spaceTheme/bullet.png");
    Sprite* enemyBulletSprite =factory->createSprite("Sprites/spaceTheme/enemyBullet.png");
    //make enemies
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
    teller = 0;
    //Alien *alien = new Alien(0, 0, 0, 0, 0, nullptr, 220, 120, 64, 64, 10, alienSprite);
    GameObject *player = new GameObject(520,400,64,64,20,playerSprite);
    player->setHealth(3);


    while(isRunning)
    {
        //input + moven
        input.clearInput();
        iHandler->handleInput();
        input = iHandler->getInput();
        if((player->getXpos()+ (-input.getLeft()+input.getRight())*player->getSpeed()>0) && (player->getXpos()+player->getWidth() + (-input.getLeft()+input.getRight())*player->getSpeed() <screen->getWidth()  ))
        {
            player->setXpos(player->getXpos() +(-input.getLeft()+input.getRight()) * player->getSpeed());
        } else
        {
            player->setXpos(player->getXpos()+(-input.getLeft()+input.getRight())*__min(player->getXpos()-1,screen->getWidth()-(player->getXpos()+player->getWidth())));
        }

        if (input.isQuit())
        {
            isRunning = false;
        }


        //logica
        //render
        screen->applyTexture(0,0,1024,768,background );
        screen->renderGameObject(player);
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
    }
    //stop de game


    screen->closeWindow();

}
