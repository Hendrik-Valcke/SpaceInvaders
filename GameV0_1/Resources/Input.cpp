//
// Created by Hendrik Valcke on 24/03/2020.
//

#include "Input.h"

void Input::clearInput()
{
    up= 0;
    down= 0;
    left= 0;
    right= 0;
    fire= false;
    quit= false;
}

int Input::getLeft() const {
    return left;
}

void Input::setLeft(int left) {
    Input::left = left;
}

int Input::getRight() const {
    return right;
}

void Input::setRight(int right) {
    Input::right = right;
}

int Input::getUp() const {
    return up;
}

void Input::setUp(int up) {
    Input::up = up;
}

int Input::getDown() const {
    return down;
}

void Input::setDown(int down) {
    Input::down = down;
}

bool Input::isFire() const {
    return fire;
}

void Input::setFire(bool fire) {
    Input::fire = fire;
}

bool Input::isQuit() const {
    return quit;
}

void Input::setQuit(bool quit) {
    Input::quit = quit;
}


