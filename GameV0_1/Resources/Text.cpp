//
// Created by Hendrik Valcke on 21/06/2020.
//

#include "Text.h"

Text::Text(std::string text, int x, int y, int size, std::string path)
{
    xPos=x;
    yPos=y;
    text=text;
    charSize=size;
}

const std::string &Text::getText() const {
    return text;
}

void Text::setText(const std::string &text) {
    Text::text = text;
}

int Text::getCharSize() const {
    return charSize;
}

void Text::setCharSize(int charSize) {
    Text::charSize = charSize;
}

double Text::getXPos() const {
    return xPos;
}

void Text::setXPos(double xPos) {
    Text::xPos = xPos;
}

double Text::getYPos() const {
    return yPos;
}

void Text::setYPos(double yPos) {
    Text::yPos = yPos;
}

int Text::getWidth() const {
    return width;
}

void Text::setWidth(int width) {
    Text::width = width;
}

int Text::getHeight() const {
    return height;
}

void Text::setHeight(int height) {
    Text::height = height;
}

