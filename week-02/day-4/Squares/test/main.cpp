#include <iostream>
#include <iostream>
#include <SDL.h>

//Screen dimension constants
const int SCREEN_WIDTH = 729;
const int SCREEN_HEIGHT = 730;

//Draws geometry on the canvas
void draw();

//Draws rectangle
void drawRect(double x, double y, double size);

//Draws da shit
void drawPattern(double x, double y, double size);

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window *gWindow = nullptr;

//The window renderer
SDL_Renderer *gRenderer = nullptr;

void draw()
{

//    drawPattern(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, SCREEN_WIDTH / 3);
    drawPattern(SCREEN_WIDTH / 2.0, SCREEN_HEIGHT / 2.0, SCREEN_WIDTH / 3.0);
}

void drawPattern(double x, double y, double size)
{
    if (size < 1) return;

    drawRect(x - size / 2, y - 3 * size / 2, size);
    drawRect(x - 3 * size / 2, y - size / 2, size);
    drawRect(x + size / 2, y - size / 2, size);
    drawRect(x - size / 2, y + size / 2, size);

    drawPattern(x, y - size, size / 3);
    drawPattern(x + size, y, size / 3);
    drawPattern(x, y + size, size / 3);
    drawPattern(x - size, y, size / 3);

}


void drawRect(double x, double y, double size)
{
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
    SDL_Rect rectangle = {x, y, size, size};
    SDL_RenderDrawRect(gRenderer, &rectangle);
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
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0x00, 0xFF);
        SDL_RenderClear(gRenderer);

        draw();

        //Update screen
        SDL_RenderPresent(gRenderer);
    }

    //Free resources and close SDL
    close();

    return 0;
}