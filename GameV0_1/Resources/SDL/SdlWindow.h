//
// Created by hendr on 02/03/2020.
//

#ifndef GAMEV0_SDLWINDOW_H
#define GAMEV0_SDLWINDOW_H

#include <SDL_video.h>
#include <SDL_image.h>
#include "../Window.h"

class SdlWindow: public Window{
public:
    SdlWindow();
    ~SdlWindow();
    bool makeWindow() override ;
    bool applyTexture(int sprDestX, int sprDestY, int sprWidth, int sprHeight, Sprite* spr) override ;
    bool loadMedia() override ;
    SDL_Texture* loadTexture( std::string path )  ;
    bool closeWindow() override;
    bool updateWindow() override;
    bool applyMedia() override;


    /*
    SDL_Surface* loadSurface(std::string);
    SDL_Surface* loadPng(std::string);
    void stretchMedia() override ;
    bool applyMedia() override ;
    bool closeWindow() override;
    bool updateWindow() override;
     */
    //getters en setters
    int getHeight()override;
    void setHeight(int sHeight) override;
    int getWidth() override;
    void setWidth(int sWidth) override;
    std::string getTitle() override;
    void setTitle(std::string sTitle) override;
    std::string getPath() override;
    void setPath(std::string sPath) override;

    SDL_Renderer* getRenderer(){return gRenderer;}


private:
    int width;
    int height;
    std::string title;
    std::string path;

    SDL_Texture* loadtexture= nullptr;
    SDL_Window* gWindow = nullptr; //The window we'll be rendering to
    SDL_Renderer* gRenderer=nullptr;//the window renderer
    SDL_Texture* gTexture=nullptr;

    /*
    SDL_Surface* screenSurface = nullptr;//The surface contained by the window
    SDL_Surface* stretchedSurface = nullptr;
    SDL_Surface* image = nullptr;//The image we will load and show on the screen (stretched)*/
};

#endif //GAMEV0_SDLWINDOW_H
