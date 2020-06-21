//
// Created by hendr on 09/03/2020.
//

#include <SDL2/SDL_events.h>
#include <iostream>
#include "SdlInputHandler.h"


void SdlInputHandler::handleInput()
{
    SDL_Event e;
    input.clearInput();
    while( SDL_PollEvent( &e ) != 0 )
    {
        //User requests quit
        if( e.type == SDL_QUIT )
        {
            input.setQuit(true);
        }
            //User presses a key
        const Uint8* currentKeyStates = SDL_GetKeyboardState( nullptr );
        if( currentKeyStates[ SDL_SCANCODE_LEFT ] )
        {
            input.setLeft(1);
        }
        if( currentKeyStates[ SDL_SCANCODE_RIGHT ] )
        {
            input.setRight(1);
        }
        if( currentKeyStates[ SDL_SCANCODE_ESCAPE ] )
        {
            input.setQuit(true);
        }
        if( currentKeyStates[ SDL_SCANCODE_SPACE ] )
        {
            input.setFire(true);
        }


    }
}