//
// Created by hendr on 02/03/2020.
//

#ifndef GAMEV0_SDLWINDOW_H
#define GAMEV0_SDLWINDOW_H

#include <SDL2/SDL_video.h>
#include <SDL2/SDL_image.h>
#include "../Window.h"
#include "../Text.h"
#include <SDL2/SDL_ttf.h>
using namespace windowSpace;
namespace sdlWindowSpace{
class SdlWindow: public Window{//very similar to lazy foo's tutorial
public://many functians are bool instead of void, this can come in handy when checking for errors, a few of them don't have any conditions so the bool is useless
    SdlWindow();
    uint32_t sendTicks() override ;
    void delayFrame(uint32_t time) override ;
    bool makeWindow() override ;
    bool applyTexture(int sprDestX, int sprDestY, int sprWidth, int sprHeight, Sprite* spr) override ;
    bool applyTextTexture(Text* text) override ;
    bool renderGameObject(GameObject* object) override ;
    bool closeWindow() override;
    bool updateWindow() override;
    SDL_Renderer* getRenderer(){return gRenderer;}


private:
    std::string title;
    SDL_Window* gWindow = nullptr; //The window we'll be rendering to
    SDL_Renderer* gRenderer=nullptr;//the window renderer
};
}
#endif //GAMEV0_SDLWINDOW_H
