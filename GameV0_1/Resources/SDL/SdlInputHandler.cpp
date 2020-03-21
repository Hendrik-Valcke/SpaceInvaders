//
// Created by hendr on 09/03/2020.
//

#include <SDL_events.h>
#include <iostream>
#include "SdlInputHandler.h"
/*SdlInputHandler::SdlInputHandler()
{

}*/

void SdlInputHandler::handleInput()
{
    SDL_Event e;
    while( SDL_PollEvent( &e ) != 0 )
    {
        //User requests quit
        if( e.type == SDL_QUIT )
        {
            std::cout << "input: quit";
        }
            //User presses a key
        else if( e.type == SDL_KEYDOWN )
        {
            //Select surfaces based on key press
            switch( e.key.keysym.sym )
            {
                case SDLK_UP:
                    std::cout << "input: up";
                    //gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ];
                    break;

                case SDLK_DOWN:
                    std::cout << "input: down";
                    //gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ];
                    break;

                case SDLK_LEFT:
                    std::cout << "input: left";
                    //gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ];
                    break;

                case SDLK_RIGHT:
                    std::cout << "input:right";
                    //gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ];
                    break;

                default:
                    std::cout << "input: default";
                    //gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];
                    break;
            }
        }
    }
}