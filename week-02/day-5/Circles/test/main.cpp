#include <iostream>
#include <iostream>
#include <SDL.h>
#include <cmath>
#include "SDL2_gfxPrimitives.h"


//Screen dimension constants
const int SCREEN_WIDTH = 620;
const int SCREEN_HEIGHT = 620;
const double PI = 3.14159265;

//Draws geometry on the canvas
void draw();


//Draws da shit
void drawPattern(double x, double y, double radius);

//Draws a circle
void drawCircle(double x, double y, double radius);

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window *gWindow = nullptr;

//The window renderer
SDL_Renderer *gRenderer = nullptr;

int original_radius = 250.0;
bool starting_orientation = false;

void draw()
{
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
    drawPattern(SCREEN_WIDTH / 2.0, SCREEN_HEIGHT / 2.0, original_radius);
}

void drawPattern(double x, double y, double radius)
{
    if (radius < 10) return;

    drawCircle(x, y, radius);

    drawPattern(x + radius * cos(30 * PI / 180.0) / 2, y + radius * sin(30 * PI / 180) / 2, radius / 2);
    drawPattern(x - radius * cos(30 * PI / 180.0) / 2, y + radius * sin(30 * PI / 180) / 2, radius / 2);
    drawPattern(x, y - radius / 2, radius / 2);



}


void drawCircle(double x, double y, double radius)
{
    circleRGBA(gRenderer, x, y, radius, 0, 0, 0, 255);
}

bool init()
{
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create window
    gWindow = SDL_CreateWindow("Circles", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                               SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (gWindow == nullptr) {
        std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create renderer for window
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if (gRenderer == nullptr) {
        std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Initialize renderer color
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

    return true;
}

void close()
{
    //Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
    gRenderer = nullptr;

    SDL_Quit();
}

int main(int argc, char *args[])
{
    //Start up SDL and create window
    if (!init()) {
        std::cout << "Failed to initialize!" << std::endl;
        close();
        return -1;
    }

    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //While application is running
    while (!quit) {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            //User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        //Clear screen
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(gRenderer);

        draw();

        //Update screen
        SDL_RenderPresent(gRenderer);
    }

    //Free resources and close SDL
    close();

    return 0;
}