//
// Created by hendr on 02/03/2020.
//

#include "../Window.h"
#include "SdlFactory.h"
#include "SdlWindow.h"
#include "SdlInputHandler.h"

Window* SdlFactory::createWindow() {
    Window *screen = new SdlWindow;
    return screen;
}

InputHandler* SdlFactory::createInputHandler()
{
    InputHandler* iHandler=new SdlInputHandler;
    return iHandler;
}
