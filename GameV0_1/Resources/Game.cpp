//
// Created by hendr on 02/03/2020.
//

#include <iostream>
#include "Game.h"
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