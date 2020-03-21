//
// Created by hendr on 02/03/2020.
//

#include "SdlWindow.h"
#include <SDL.h>
#include <stdio.h>
#include <iostream>

SdlWindow::SdlWindow()
{
    width=640;
    height=480;
    title = "please work :)";
    path = "Sprites/background.png";
}

bool SdlWindow::makeWindow()
{
    printf("\nmaking window...");
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
        }

        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    success = false;
                }
            }
        }
    }
    return success;
}

bool SdlWindow::loadMedia()
{
    printf("\nloading media...");

    //Loading success flag
    bool success = true;

    //Load PNG texture
    gTexture = loadTexture( path.c_str() );
    if( gTexture == NULL )
    {
        printf( "Failed to load texture image!\n" );
        success = false;
    }

    return success;
}

SDL_Texture* SdlWindow::loadTexture( std::string path )
{
    printf("\nloading texture...");

    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
    if( newTexture == NULL )
    {
        printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    }

    //Get rid of old loaded surface
    SDL_FreeSurface( loadedSurface );
    }
return newTexture;
}

bool SdlWindow::applyMedia()
{
    printf("\napplying media...");

    SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );
    return true;
}
bool SdlWindow:: updateWindow()
{
    printf("\nupdating window...");

    SDL_RenderPresent( gRenderer );
    return true;

}
bool SdlWindow::closeWindow()
{
    printf("\nclosing window...");

    SDL_DestroyWindow(gWindow);
}

//surface versie
/*bool SdlWindow::makeWindow()
{
    bool success = true;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )//Initialize SDL
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success=false;
    }
    else {//Create window
        gWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
        if (gWindow == NULL) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        } else {//Get window surface
            //screenSurface = SDL_GetWindowSurface(window);
            //Initialize PNG loading
            int imgFlags = IMG_INIT_PNG;
            if( !( IMG_Init( imgFlags ) & imgFlags ) )
            {
                printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                success = false;
            }
            else
            {
                //Get window surface
                gScreenSurface = SDL_GetWindowSurface( gWindow );
            }//end png section
        }
    }
    printf( "makewindow:1\n" );
    return success;
}

SDL_Surface* SdlWindow::loadSurface( std::string path )//load surface with string: path
{
    SDL_Surface *optimizedSurface = NULL;//The final optimized image

    SDL_Surface *loadedSurface = SDL_LoadBMP(path.c_str()); //Load image at specified path
    if (loadedSurface == NULL) {
        printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
    }
    else
    {
        optimizedSurface = SDL_ConvertSurface( loadedSurface, screenSurface->format, 0 ); //Convert surface to screen format
        if( optimizedSurface == NULL )
        {
            printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }

        SDL_FreeSurface( loadedSurface ); //Get rid of old loaded surface
    }
    printf( "loadsurface:1\n" );

    return optimizedSurface;
}

SDL_Surface* SdlWindow::loadPng( std::string path )//load surface with string: path
{
    SDL_Surface *optimizedSurface = NULL;//The final optimized image

    SDL_Surface *loadedSurface = IMG_Load(path.c_str()); //Load image at specified path
    if (loadedSurface == NULL) {
        printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
    }
    else
    {
        optimizedSurface = SDL_ConvertSurface( loadedSurface, screenSurface->format, 0 ); //Convert surface to screen format
        if( optimizedSurface == NULL )
        {
            printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }

        SDL_FreeSurface( loadedSurface ); //Get rid of old loaded surface
    }
    printf( "loadsurface:1\n" );

    return optimizedSurface;
}

bool SdlWindow::loadMedia()
{
    bool success = true;
    //Load stretching surface
    //image = loadSurface( path.c_str() );
    image = loadPng(path.c_str());
    if( image == NULL )
    {
        printf( "Failed to load stretching image!\n" );
        success = false;
    }
    printf( "loadmedia:1\n" );

    return success;
}
void SdlWindow::stretchMedia()
{
    //Apply the image stretched
    SDL_Rect stretchRect;
    stretchRect.x = 0;
    stretchRect.y = 0;
    stretchRect.w = width;
    stretchRect.h = height;
    SDL_BlitScaled( image, NULL, screenSurface, &stretchRect );

    printf( "stretchmedia:1\n" );
    std::cout << "height:"  << height    ;

}


bool SdlWindow::closeWindow() {
    //Deallocate surface
    SDL_FreeSurface( image );
    image = NULL;
    //Destroy window
    SDL_DestroyWindow( window );
    window = NULL;
    printf( "closewindow:1\n" );

    return true;//later nog condities toevoegen
}

bool SdlWindow::updateWindow() {
    //Update the surface
    SDL_UpdateWindowSurface( window );
    printf( "updatewindow:1\n" );

    return true;//later nog condities toevoegen
}
bool SdlWindow::applyMedia() {
    //Apply the image
    SDL_BlitSurface( image, NULL, screenSurface, NULL );
    printf( "applymedia:1\n" );

    return true;//later nog condities toevoegen
}*/

int SdlWindow::getHeight() {
    return height;
}
void SdlWindow::setHeight(int sHeight) {
     height=sHeight;
}
int SdlWindow::getWidth() {
    return width;
}
void SdlWindow::setWidth(int sWidth) {
    width=sWidth;
}
std::string SdlWindow::getTitle() {
    return title;
}
void SdlWindow::setTitle(std::string sTitle) {
    title=sTitle;
}
std::string SdlWindow::getPath() {
    return path;
}
void SdlWindow::setPath(std::string sPath) {
    path=sPath;
}



