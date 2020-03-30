//
// Created by Hendrik Valcke on 23/03/2020.
//

#include <string>
#include "SdlSprite.h"
#include "../GameController.h"
#include "SdlWindow.h"

SdlSprite::SdlSprite(std::string cPath )
{
    path = cPath;
}
void SdlSprite::setTexture(std::string path)
{
    printf("\nloading texture...");

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        auto* gWindow = GameController::getInstance().getWindow();
        auto* gSdlWindow = dynamic_cast<SdlWindow*>(gWindow);

        //Create texture from surface pixels
        texture = SDL_CreateTextureFromSurface( gSdlWindow->getRenderer(), loadedSurface );
        if( texture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }
}
void* SdlSprite::getTexture()
{
    return texture;
}