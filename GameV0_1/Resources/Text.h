//
// Created by Hendrik Valcke on 20/06/2020.
//

#ifndef GAMEV0_1_TEXT_H
#define GAMEV0_1_TEXT_H

#include <iostream>


class Text {
public:
    Text( std::string text, int x, int y, int fontsize, std::string path){} ;
    virtual void setText(std::string text) = 0;

    virtual void generateTexture() = 0;

protected:
    std::string text;
    void* font;
};


#endif //GAMEV0_1_TEXT_H
