//
// Created by hendr on 02/03/2020.
//

#ifndef GAMEV0_WINDOW_H
#define GAMEV0_WINDOW_H
#include <string>
#include "Sprite.h"
#include "GameObject.h"
#include "Text.h"

class Window {
public:
    virtual uint32_t sendTicks()=0;
    virtual void delayFrame(uint32_t time)=0;

    virtual bool makeWindow() =0;
    //virtual bool loadMedia() =0;

    virtual bool applyTexture(int sprDestX, int sprDestY, int sprWidth, int sprHeight, Sprite* spr)=0;
    virtual bool applyTextTexture(Text* text)=0;
    virtual bool renderGameObject ( GameObject* object)=0;
    //virtual bool applyMedia()=0;
    virtual bool closeWindow()=0;
    virtual bool updateWindow()=0;
    //getters/setters
    //virtual int getHeight()=0;
    //virtual void setHeight(int sHeight)=0;
    //virtual int getWidth()=0;
    //virtual void setWidth(int sWidth)=0;
    //virtual std::string getTitle()=0;
    //virtual void setTitle(std::string sTitle)=0;
    //virtual std::string getPath()=0;
    //virtual void setPath(std::string sPath)=0;

private:
    //int height;
    //int width;
    //std::string title;
    //std::string path;
};


#endif //GAMEV0_WINDOW_H
