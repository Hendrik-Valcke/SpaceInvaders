#include <iostream>
#include "Resources/Game.h"
#include "Resources/SDL/SdlFactory.h"

/*<<<<<<< Updated upstream
int main(int argc, const char* argv[]) {
    Game* myGame= new Game{new SdlFactory()};
    //myGame->runScreen();
    myGame->startGame();
=======*/
int main(int argc, char* argv[])
{
    Game* SpaceInvaders = new Game{new SdlFactory()};
    SpaceInvaders->startGame();
    printf("\nsucces!");
    return 0;
}
