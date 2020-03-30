//
// Created by hendr on 02/03/2020.
//

#include <iostream>
#include "Game.h"
#include "GameObject.h"
#include "GameController.h"

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
    Window *screen = factory->createWindow();
    InputHandler *iHandler=factory->createInputHandler();

    if( !screen->makeWindow() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !screen->loadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            iHandler->handleInput();

            screen->applyMedia();
            screen->updateWindow();
            _sleep(5000);

        }
    }

    //Free resources and close SDL
    screen->closeWindow();
}

void Game::startGame()
{
    Window* screen = factory->createWindow();
    GameController::getInstance().setWindow(screen);
    InputHandler* iHandler=factory->createInputHandler();
    if(!screen->makeWindow())
    {
        isRunning= false;
        printf("\nWindow could not be created");
    }
    Sprite* background =factory->createSprite("Sprites/background.png");
    Sprite* playerSprite =factory->createSprite("Sprites/playerShip.png");
    Sprite* alienSprite =factory->createSprite("Sprites/alien.png");
    GameObject *alien = new GameObject(620,420,50,50,alienSprite);
    GameObject *player = new GameObject(620,420,100,100,playerSprite);
    /*while(isRunning)
    {
        iHandler->handleInput();
        Input input = iHandler->getInput();
        if input.g
        //input
        //logica
        //render
    }
*/
    screen->applyTexture(0,0,640,480,background );
    screen->applyTexture(120,360,64,64,alienSprite );
    screen->applyTexture(320,360,128,128,playerSprite);
    screen->updateWindow();
    _sleep(1000);
    for (int i = 0; i < 150; ++i) {
        screen->applyTexture(0,0,640,480,background );
        screen->applyTexture(120,360,64,64,alienSprite );
        screen->applyTexture(320+i,360 ,100,100,playerSprite);
        screen->updateWindow();

        _sleep(50);
    }
    screen->closeWindow();

}
