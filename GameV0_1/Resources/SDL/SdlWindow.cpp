//
// Created by hendr on 02/03/2020.
//

#include "SdlWindow.h"
#include "../GameObject.h"
#include <SDL.h>
#include <stdio.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
using namespace windowSpace;
using namespace sdlWindowSpace;
SdlWindow::SdlWindow()
{
    title = "Space Invaders";
}
uint32_t SdlWindow::sendTicks()
{
    return SDL_GetTicks();
}

void SdlWindow::delayFrame(uint32_t time)
{
    SDL_Delay(time);
}

bool SdlWindow::makeWindow()
{
    printf("\nmaking window...");
    //Initialization flag
    bool success = true;
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
        }

        //Create window
        gWindow = SDL_CreateWindow( title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_W, SCREEN_H, false );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    success = false;
                }
                //Initialize SDL_ttf
                if( TTF_Init() == -1 )
                {
                    printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
                    success = false;
                }
            }
        }
    }
    return success;
}

bool SdlWindow:: applyTexture(int sprDestX, int sprDestY, int sprWidth, int sprHeight, Sprite* spr)
{
    SDL_Rect destRect;
    destRect.x = sprDestX;
    destRect.y = sprDestY;
    destRect.w = sprWidth;
    destRect.h = sprHeight;
    SDL_RenderCopy( gRenderer, reinterpret_cast<SDL_Texture*>(spr->getTexture()), NULL, &destRect );
    return true;
}

bool SdlWindow:: applyTextTexture( Text* text)
{
    SDL_Rect destRect;
    destRect.x = text->getXPos();
    destRect.y = text->getYPos();
    destRect.w = text->getWidth();
    destRect.h = text->getHeight();
    SDL_RenderCopy( gRenderer, reinterpret_cast<SDL_Texture*>(text->getTexture()), NULL, &destRect );
    return true;
}

bool SdlWindow:: renderGameObject(GameObject* object)
{
    SDL_Rect destRect;
    destRect.x = object->getXpos();
    destRect.y = object->getYpos();
    destRect.w = object->getWidth();
    destRect.h = object->getHeight();
    Sprite* spr = object->getObjectSprite();
    SDL_RenderCopy( gRenderer, reinterpret_cast<SDL_Texture*>(spr->getTexture()), NULL, &destRect );
    return true;
}
bool SdlWindow:: updateWindow()
{
    SDL_RenderPresent( gRenderer );
    SDL_RenderClear(gRenderer);
    return true;

}
bool SdlWindow::closeWindow()
{
    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
    return true; // nog condities adden
}




