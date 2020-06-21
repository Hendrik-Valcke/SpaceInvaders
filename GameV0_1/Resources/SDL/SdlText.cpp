//
// Created by Hendrik Valcke on 20/06/2020.
//
#include <string>
#include "SdlText.h"
#include "../GameController.h"
#include "SdlWindow.h"
#include <iostream>
#include <SDL2/SDL_ttf.h>
SdlText::SdlText(std::string text, int x,int y, int charSize, std::string path ) : Text(text,x,y,charSize,path)
{
    //insert cosntructor from Text Class
    font = TTF_OpenFont(path.c_str(),charSize);
    //font = TTF_OpenFont("Fonts/8BitMadness.ttf",charSize);
    if( font == NULL )
    {
        printf( "Failed to load font! SDL_ttf Error: %s\n", TTF_GetError() );
    }
    generateTexture();
}
void SdlText::generateTexture()
{

    SDL_Surface* textSurface = TTF_RenderUTF8_Solid(reinterpret_cast<TTF_Font*>(this->font), text.c_str(),{255,255,255});
    //SDL_Surface* textSurface = TTF_RenderUTF8_Solid(reinterpret_cast<TTF_Font*>(this->font), "test",{255,255,255});
    if( textSurface == NULL )
    {
        printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
    }
    else
    {
        auto* sdlWindow = dynamic_cast<SdlWindow*>(GameController::getInstance().getWindow());
        textTexture= SDL_CreateTextureFromSurface(sdlWindow->getRenderer(),textSurface);
        if( textTexture == NULL )
        {
            printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
        }
        else
        {
            //Get image dimensions
            width=textSurface->w;
            height= textSurface->h;
        }
    }
    SDL_FreeSurface(textSurface);
}

void* SdlText::getTexture()
{
    return textTexture;
}