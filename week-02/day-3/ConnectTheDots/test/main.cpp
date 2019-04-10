#include <iostream>
#include <SDL.h>
#include <vector>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Draws geometry on the canvas
void draw(std::vector<std::vector<int>>);

//Draws a line
void drawLine(int x0, int y0, int x1, int y1);

//Connects dots with lines
void connectDots(std::vector<std::vector<int>> vector);

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window *gWindow = nullptr;

//The window renderer
SDL_Renderer *gRenderer = nullptr;

void draw(std::vector<std::vector<int>> vector) {
    // Create a function that takes 1 parameter:
    // An array of {x, y} points
    // and connects them with green lines.
    // Connect these to get a box: {{10, 10}, {290,  10}, {290, 290}, {10, 290}}
    // Connect these: {{50, 100}, {70, 70}, {80, 90}, {90, 90}, {100, 70}, {120, 100}, {85, 130}, {50, 100}}
    connectDots(vector);
}

void connectDots(std::vector<std::vector<int>> vector) {
    for (unsigned int i = 0; i < vector.size() - 1; i++) {
        drawLine(vector[i][0], vector[i][1], vector[i + 1][0], vector[i + 1][1]);
    }
    drawLine(vector[0][0], vector[0][1], vector[vector.size() - 1][0], vector[vector.size() - 1][1]);
}

void drawLine(int x0, int y0, int x1, int y1) {
    SDL_SetRenderDrawColor(gRenderer, 26, 204, 59, 255);
    SDL_RenderDrawLine(gRenderer, x0, y0, x1, y1);
}

bool init() {
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create window
    gWindow = SDL_CreateWindow("Connect the dots", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
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

    std::vector<std::vector<int>> box = {{10,  10},
                                         {290, 10},
                                         {290, 290},
                                         {10,  290}};

    std::vector<std::vector<int>> fox = {{50, 100}, {70, 70}, {80, 90}, {90, 90}, {100, 70}, {120, 100}, {85, 130}, {50, 100}};

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

        draw(fox);

        //Update screen
        SDL_RenderPresent(gRenderer);
    }

    //Free resources and close SDL
    close();

    return 0;
}