//
// Created by hendr on 02/03/2020.
//

#include "../Window.h"
#include "SdlFactory.h"
#include "SdlWindow.h"
#include "SdlInputHandler.h"
#include "SdlSprite.h"

Window* SdlFactory::createWindow() {
    Window *window = new SdlWindow;
    return window;
}

InputHandler* SdlFactory::createInputHandler()
{
    InputHandler* handler=new SdlInputHandler;
    return handler;
}

Sprite* SdlFactory::createSprite(std::string cPath)
{
    auto* sprite = new SdlSprite(cPath);
    sprite->setTexture(cPath);
    return sprite;
}
