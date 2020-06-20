//
// Created by Hendrik Valcke on 20/06/2020.
//

#include "SdlText.h"
#include "../GameController.h"
#include "SdlWindow.h"
#include <iostream>
#include <SDL2/SDL_ttf.h>
SdlText::SdlText(std::string text, int x,int y, int charSize, std::string path ) : Text(text,x,y,charSize,path)
{
    font = TTF_OpenFont(path.c_str(),charSize);
    text = text;
    generateTexture();
}
void SdlText::generateTexture()
{
    SDL_Color color = {255,255,255};
    auto* textSurface = TTF_RenderUTF8_Solid(reinterpret_cast<TTF_Font*>(this->font), text.c_str(),color);
    auto* textWindow = GameController::getInstance().getWindow();
    auto* textSdlWindow = dynamic_cast<SdlWindow*>(textWindow);
    textTexture= SDL_CreateTextureFromSurface(textSdlWindow->getRenderer(),textSurface);
    width=textSurface->w;
    height = textSurface->h;
    SDL_FreeSurface(textSurface);
}

void* SdlText::getTexture()
{
    return textTexture;
}