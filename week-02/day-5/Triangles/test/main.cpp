#include <iostream>
#include <iostream>
#include <SDL.h>
#include <cmath>


//Screen dimension constants
const int SCREEN_WIDTH = 620;
const int SCREEN_HEIGHT = 620;

//Draws geometry on the canvas
void draw();


//Draws da shit
void drawPattern(double x, double y, double side, bool orientation);

//Draws a triangle
void drawTriangle(double x, double y, double side, bool orientation);

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window *gWindow = nullptr;

//The window renderer
SDL_Renderer *gRenderer = nullptr;

int side = 500.0;
bool starting_orientation = false;

void draw()
{
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
    drawPattern(SCREEN_WIDTH / 2.0, SCREEN_HEIGHT / 2.0, side, starting_orientation);
}

void drawPattern(double x, double y, double side, bool orientation)
{
    if (side < 2) return;

    drawTriangle(x, y, side, orientation);

    drawPattern(x + side / 4, y - ((side * sqrt(3) / 2) / 3 - ((side / 2) * sqrt(3) / 2) / 3), side / 2, orientation);
    drawPattern(x - side / 4, y - ((side * sqrt(3) / 2) / 3 - ((side / 2) * sqrt(3) / 2) / 3), side / 2, orientation);
    drawPattern(x, y + (2 * (side * sqrt(3) / 2) / 3 - (2 * (side / 2) * sqrt(3) / 2) / 3), side / 2, orientation);


}


void drawTriangle(double x, double y, double side, bool orientation)
{
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
    if (orientation) {
        SDL_RenderDrawLine(gRenderer, x, y - 2 * (side * sqrt(3) / 2) / 3, x + side / 2, y + (side * sqrt(3) / 2) / 3);
        SDL_RenderDrawLine(gRenderer, x + side / 2, y + (side * sqrt(3) / 2) / 3, x - side / 2,
                           y + (side * sqrt(3) / 2) / 3);
        SDL_RenderDrawLine(gRenderer, x - side / 2, y + (side * sqrt(3) / 2) / 3, x, y - 2 * (side * sqrt(3) / 2) / 3);
    } else {
        SDL_RenderDrawLine(gRenderer, x, y + 2 * (side * sqrt(3) / 2) / 3, x + side / 2, y - (side * sqrt(3) / 2) / 3);
        SDL_RenderDrawLine(gRenderer, x + side / 2, y - (side * sqrt(3) / 2) / 3, x - side / 2,
                           y - (side * sqrt(3) / 2) / 3);
        SDL_RenderDrawLine(gRenderer, x - side / 2, y - (side * sqrt(3) / 2) / 3, x, y + 2 * (side * sqrt(3) / 2) / 3);
    }
}

bool init()
{
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create window
    gWindow = SDL_CreateWindow("Line in the middle", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
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