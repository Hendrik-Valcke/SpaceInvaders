#include <iostream>
#include "Resources/Game.h"
#include "Resources/SDL/SdlFactory.h"

int main(int argc, const char* argv[]) {
    Game* myGame= new Game{new SdlFactory()};
    myGame->runScreen();
    return 0;
}
