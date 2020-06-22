//
// Created by hendr on 02/03/2020.
//

#ifndef GAMEV0_WINDOW_H
#define GAMEV0_WINDOW_H
#include <string>
#include "Sprite.h"
#include "GameObject.h"
#include "Text.h"
using namespace TextSpace;
using namespace GameObjectSpace;
namespace windowSpace{
class Window {
public:
    virtual uint32_t sendTicks()=0;
    virtual void delayFrame(uint32_t time)=0;

    virtual bool makeWindow() =0;

    virtual bool applyTexture(int sprDestX, int sprDestY, int sprWidth, int sprHeight, Sprite* spr)=0;
    virtual bool applyTextTexture(Text* text)=0;
    virtual bool renderGameObject ( GameObject* object)=0;

    virtual bool closeWindow()=0;
    virtual bool updateWindow()=0;


};
}

#endif //GAMEV0_WINDOW_H
