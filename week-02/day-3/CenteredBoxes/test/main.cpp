#include <iostream>
#include <SDL.h>
#include <ctime>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Draws geometry on the canvas
void draw();

//Draw 3 squares
void drawThreeSquares();

//Draws a centered 'size' sized square
void drawCenteredSquare(int size);

//Random number from 0 to limit
int randomNumber(int limit) {


    int result = rand() % (limit + 1);
    std::cout << result << std::endl;
    return result;
};

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window *gWindow = nullptr;

//The window renderer
SDL_Renderer *gRenderer = nullptr;

void draw() {
    // create a square drawing function that takes 1 parameter:
    // the square size
    // and draws a square of that size to the center of the canvas.
    // draw at least 3 squares with that function.
    // the squares should not be filled otherwise they will hide each other
    // avoid code duplication.
    drawThreeSquares();
}

void drawThreeSquares() {
    SDL_SetRenderDrawColor(gRenderer, randomNumber(255), randomNumber(255), randomNumber(255), 255);
    for (int i = 0; i < 3; i++) {
        drawCenteredSquare(randomNumber(SCREEN_HEIGHT / 2));
    }
}

void drawCenteredSquare(int size) {
    SDL_Rect square = {SCREEN_WIDTH / 2 - size / 2, SCREEN_HEIGHT / 2 - size / 2, size, size};
    SDL_RenderDrawRect(gRenderer, &square);
}

bool init() {
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create window
    gWindow = SDL_CreateWindow("Center box function", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
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

    srand(time(0));
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
        SDL_Delay(3000);

        //Update screen
        SDL_RenderPresent(gRenderer);
    }

    //Free resources and close SDL
    close();

    return 0;
}