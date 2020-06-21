//
// Created by hendr on 02/03/2020.
//

#include "SdlWindow.h"
#include "../GameObject.h"
#include <SDL.h>
#include <stdio.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

SdlWindow::SdlWindow()
{
    width=SCREEN_W;
    height=SCREEN_H;
    title = "Space Invaders";
    path = "Sprites/background.png";
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
        gWindow = SDL_CreateWindow( title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, false );
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

bool SdlWindow::loadMedia()
{
    printf("\nloading media...");

    //Loading success flag
    bool success = true;

    //Load PNG texture
    gTexture = loadTexture( path.c_str() );
    if( gTexture == NULL )
    {
        printf( "Failed to load texture image!\n" );
        success = false;
    }

    return success;
}
//wordt niet meer gebruikt

SDL_Texture* SdlWindow::loadTexture( std::string path )
{
    printf("\nloading texture...");

    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
    if( newTexture == NULL )
    {
        printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    }

    //Get rid of old loaded surface
    SDL_FreeSurface( loadedSurface );
    }
return newTexture;
}

bool SdlWindow:: applyTexture(int sprDestX, int sprDestY, int sprWidth, int sprHeight, Sprite* spr)
{
    //printf("\napplying texture...");
    SDL_Rect destRect;
    destRect.x = sprDestX;
    destRect.y = sprDestY;
    destRect.w = sprWidth;
    destRect.h = sprHeight;
    SDL_RenderCopy( gRenderer, reinterpret_cast<SDL_Texture*>(spr->getTexture()), NULL, &destRect );
    return true; //nog condities adden
}

bool SdlWindow:: applyTextTexture( Text* text)
{
    //printf("\napplying texture...");
    SDL_Rect destRect;
    destRect.x = text->getXPos();
    destRect.y = text->getYPos();
    destRect.w = text->getWidth();
    destRect.h = text->getHeight();
    SDL_RenderCopy( gRenderer, reinterpret_cast<SDL_Texture*>(text->getTexture()), NULL, &destRect );
    return true; //nog condities adden
}

bool SdlWindow:: renderGameObject(GameObject* object)
{
    //fps->60 ->frameDuration = 60/1000 ms
    //uint32_t startTicks = SDL_GetTicks();//millisec
    //uint32_t frameDuration = FRAMES_PER_SEC/1000;
    //int catchupTime;

    SDL_Rect destRect;
    destRect.x = object->getXpos();
    destRect.y = object->getYpos();
    destRect.w = object->getWidth();
    destRect.h = object->getHeight();
    Sprite* spr = object->getObjectSprite();
    SDL_RenderCopy( gRenderer, reinterpret_cast<SDL_Texture*>(spr->getTexture()), NULL, &destRect );

    /*uint32_t timePassed = SDL_GetTicks()-startTicks;
    if (timePassed+catchupTime <= frameDuration)
    {
        SDL_Delay(frameDuration-timePassed-catchupTime);
        catchupTime = 0;
    }
    else //timePassed > frameDuration
        {
            catchupTime = (timePassed-catchupTime-frameDuration);
            if (catchupTime<0)
            {
                catchupTime = 0;
            }
        }*/


    return true; //nog condities adden
}
bool SdlWindow::applyMedia()
{
    //printf("\napplying media...");

    SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );
    return true;
}
bool SdlWindow:: updateWindow()
{
    //printf("\nupdating window...");

    SDL_RenderPresent( gRenderer );
    SDL_RenderClear(gRenderer);
    return true;

}
bool SdlWindow::closeWindow()
{
    //printf("\nclosing window...");

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
int SdlWindow::getHeight() {
    return height;
}
void SdlWindow::setHeight(int sHeight) {
     height=sHeight;
}
int SdlWindow::getWidth() {
    return width;
}
void SdlWindow::setWidth(int sWidth) {
    width=sWidth;
}
std::string SdlWindow::getTitle() {
    return title;
}
void SdlWindow::setTitle(std::string sTitle) {
    title=sTitle;
}
std::string SdlWindow::getPath() {
    return path;
}
void SdlWindow::setPath(std::string sPath) {
    path=sPath;
}



