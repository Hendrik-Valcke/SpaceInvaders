//
// Created by Hendrik Valcke on 20/06/2020.
//

#ifndef GAMEV0_1_TEXT_H
#define GAMEV0_1_TEXT_H

#include <iostream>
#include <string>

namespace TextSpace
{
class Text {//partially abstract class
public:
    Text( std::string text, int x, int y, int fontsize, std::string path);
    virtual void generateTexture() = 0;//make a texture from the text
    virtual void* getTexture()=0;//used to send a texture to the renderer in the game

    const std::string &getText() const;

    void setText(const std::string &text);

    int getCharSize() const;

    void setCharSize(int charSize);

    double getXPos() const;

    void setXPos(double xPos);

    double getYPos() const;

    void setYPos(double yPos);

    int getWidth() const;

    void setWidth(int width);

    int getHeight() const;

    void setHeight(int height);

protected:
    std::string text;
    void* font;
    int charSize;
    double xPos;
    double yPos;
    int width;
    int height;
};
}
#endif //GAMEV0_1_TEXT_H
