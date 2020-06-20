//
// Created by Hendrik Valcke on 23/03/2020.
//

#ifndef GAMEV0_1_SDLSPRITE_H
#define GAMEV0_1_SDLSPRITE_H


#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>
#include "../Sprite.h"

class SdlSprite: public Sprite{
public:
    SdlSprite(std::string cPath);
    void setTexture(std::string cPath) override;
    void* getTexture() override ;

private:
    SDL_Texture* texture;
    std::string path;
};


#endif //GAMEV0_1_SDLSPRITE_H
