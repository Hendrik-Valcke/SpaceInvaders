//
// Created by Hendrik Valcke on 20/06/2020.
//

#ifndef GAMEV0_1_SDLTEXT_H
#define GAMEV0_1_SDLTEXT_H


#include "../Text.h"
#include <iostream>
#include <SDL2/SDL_ttf.h>

class SdlText: public Text{
public:
    SdlText(std::string text,int x, int y, int size, std::string path) ;
    void generateTexture() override;
    void* getTexture() override ;

private:
    SDL_Texture* textTexture;
};


#endif //GAMEV0_1_SDLTEXT_H
