//
// Created by Hendrik Valcke on 24/03/2020.
//

#include "Input.h"

void Input::clearInput()
{
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


