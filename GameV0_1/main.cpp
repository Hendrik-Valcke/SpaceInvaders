#include <iostream>
#include "Resources/Game.h"
#include "Resources/SDL/SdlFactory.h"


int main(int argc, char* argv[])
{
    Game* SpaceInvaders = new Game{new SdlFactory()};
    SpaceInvaders->startGame();
    printf("\nsucces!");
    return 0;
}
