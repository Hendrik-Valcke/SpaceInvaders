//
// Created by hendr on 02/03/2020.
//
#include <string>
#include "../Window.h"
#include "SdlFactory.h"
#include "SdlWindow.h"
#include "SdlInputHandler.h"
#include "SdlSprite.h"
#include "SdlText.h"
//using namespace windowSpace;
using namespace sdlWindowSpace;
using namespace sdlInputHandlerSpace;
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

Text* SdlFactory::createText(std::string text, int x, int y, int fontSize, std::string font)
{
    return new SdlText(text, x, y, fontSize, font);
}

