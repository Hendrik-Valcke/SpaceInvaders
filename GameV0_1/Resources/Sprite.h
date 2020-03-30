//
// Created by hendr on 16/03/2020.
//

#ifndef GAMEV0_1_SPRITE_H
#define GAMEV0_1_SPRITE_H
#include <string>

class Sprite {
public:
virtual void setTexture(std::string path )=0;
virtual void* getTexture()=0;

private:

};


#endif //GAMEV0_1_SPRITE_H
