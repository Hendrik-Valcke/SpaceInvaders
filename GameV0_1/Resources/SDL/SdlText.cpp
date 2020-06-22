//
// Created by Hendrik Valcke on 20/06/2020.
//
#include <string>
#include "SdlText.h"
#include "../GameController.h"
#include "SdlWindow.h"
#include <iostream>
#include <SDL2/SDL_ttf.h>
using namespace sdlWindowSpace;

SdlText::SdlText(std::string text, int x,int y, int charSize, std::string path ) : Text(text,x,y,charSize,path)
{
    //insert constructor from Text Class
    font = TTF_OpenFont(path.c_str(),charSize);
    if( font == NULL )
    {
        printf( "Failed to load font! SDL_ttf Error: %s\n", TTF_GetError() );
    }
    setText(text);
    //generateTexture();
}
void SdlText::generateTexture()
{

    auto* textSurface = TTF_RenderUTF8_Solid(reinterpret_cast<TTF_Font*>(this->font), this->text.c_str(),{255,255,255});
    if( textSurface == NULL )
    {
        printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
    }
    else
    {
        auto* window=GameController::getInstance().getWindow();
        auto* sdlWindow = dynamic_cast<SdlWindow*>(window);

        //SDL_DestroyTexture(textTexture);
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