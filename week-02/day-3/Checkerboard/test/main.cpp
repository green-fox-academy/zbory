#include <iostream>
#include <SDL.h>

//Screen dimension constants
const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 480;

//Draws geometry on the canvas
void draw();

//Draws a square
void drawSquare(int x, int y, int size);

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window *gWindow = nullptr;

//The window renderer
SDL_Renderer *gRenderer = nullptr;

void draw() {
    int size = 8;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i % 2 == 0) {
                if (j % 2 == 0) {
                    drawSquare(i * 60, j * 60, 60);
                } else {
                    std::cout << " ";
                }
            } else {
                if (j % 2 == 0) {
                    std::cout << " ";
                } else {
                    drawSquare(i * 60, j * 60, 60);
                }
            }
        }
        std::cout << std::endl;
    }
}

void drawSquare(int x, int y, int size) {
    SDL_Rect square = {x, y, size, size};
    SDL_SetRenderDrawColor(gRenderer, 184, 20, 206, 255);
    SDL_RenderFillRect(gRenderer, &square);
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(gRenderer, &square);
}

bool init() {
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create window
    gWindow = SDL_CreateWindow("Checkerboard", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
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

void close() {
    //Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
    gRenderer = nullptr;

    SDL_Quit();
}

int main(int argc, char *args[]) {
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