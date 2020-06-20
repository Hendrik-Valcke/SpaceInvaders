#include <iostream>
#include "Resources/Game.h"
#include "Resources/SDL/SdlFactory.h"

int main(int argc, char* argv[]) {
    printf("\ntest");
    Game* myGame= new Game{new SdlFactory()};
    myGame->startGame();
    printf("\nsucces!");
    return 0;
}
