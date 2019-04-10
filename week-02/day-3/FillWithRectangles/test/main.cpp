// Exercise:
// draw four different size and color rectangles.
// avoid code duplication.

#include <iostream>
#include <SDL.h>
#include <ctime>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Draws a rectangle in a random color
void drawRectangle(int x, int y, int w, int h);

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//Drawing function
void draw();

//Random number from 0 to limit
int randomNumber(int limit){
    //srand(time(0));

    int result =  rand() % (limit + 1);
    std::cout << result << std::endl;
    return result;
};

//The window we'll be rendering to
SDL_Window* gWindow = nullptr;

//The window renderer
SDL_Renderer* gRenderer = nullptr;

void draw(int rectangles[4][4] ){

    drawRectangle(rectangles[0][0], rectangles[0][1], rectangles[0][2], rectangles[0][3]);
    drawRectangle(rectangles[1][0], rectangles[1][1], rectangles[1][2], rectangles[1][3]);
    drawRectangle(rectangles[2][0], rectangles[2][1], rectangles[2][2], rectangles[2][3]);
    drawRectangle(rectangles[3][0], rectangles[3][1], rectangles[3][2], rectangles[3][3]);
}

void drawRectangle(int x, int y, int w, int h){
    SDL_Rect rectangle = {x, y, w, h};
    SDL_SetRenderDrawColor(gRenderer, randomNumber(255), randomNumber(255), randomNumber(255), 255);
    SDL_RenderFillRect(gRenderer, &rectangle);
}

bool init()
{
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create window
    gWindow = SDL_CreateWindow( "Four rectangles", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( gWindow == nullptr )
    {
        std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create renderer for window
    gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
    if( gRenderer == nullptr )
    {
        std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Initialize renderer color
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

    return true;
}

void close()
{
    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = nullptr;
    gRenderer = nullptr;

    SDL_Quit();
}

int main( int argc, char* args[] )
{
    //Start up SDL and create window
    if( !init() )
    {
        std::cout << "Failed to initialize!" << std::endl;
        close();
        return -1;
    }

    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //Rectangle data
    int randomRectangleData[4][4] = {{randomNumber(SCREEN_WIDTH), randomNumber(SCREEN_HEIGHT), randomNumber(100), randomNumber(100)},
                           {randomNumber(SCREEN_WIDTH), randomNumber(SCREEN_HEIGHT), randomNumber(100), randomNumber(100)},
                           {randomNumber(SCREEN_WIDTH), randomNumber(SCREEN_HEIGHT), randomNumber(100), randomNumber(100)},
                           {randomNumber(SCREEN_WIDTH), randomNumber(SCREEN_HEIGHT), randomNumber(100), randomNumber(100)}};

    int rectangleData[4][4] = {{10, 10, 30, 40},
                               {300, 200, 100, 200},
                               {500, 400, 30, 40},
                               {100, 120, 120, 120}};

    //While application is running
    while( !quit ) {
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

        //--------------------------------------------
        draw(rectangleData);
        //--------------------------------------------

        //Update screen
        SDL_RenderPresent(gRenderer);
    }

    //Free resources and close SDL
    close();

    return 0;
}