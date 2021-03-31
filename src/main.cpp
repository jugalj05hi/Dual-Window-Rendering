#include <chrono>
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2_image/SDL_image.h>
#include <ResourceManager.hpp>
#include "TileComponent.hpp"
#include <string>
#include <iostream>
#include <map>
#include <vector>

const int WINDOW_WIDTH = 960;
const int WINDOW_HEIGHT = 640;
const int FPS = 60;

const int TILE_MAP_HEIGHT = 960;
const int TILE_MAP_WIDTH = 320;
const int TILE_SIZE = 32;
std::map<std::vector<int>, int> tMap;

std::vector<TileComponent> tileArray;
enum Buttons
{
    PaddleOneUp = 0,
    PaddleOneDown,
    PaddleTwoUp,
    PaddleTwoDown,
};
bool init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }
    return true;
}
void getTileNumber(int x, int y) {
    
    int _x = std::floor( x / TILE_SIZE);
    int _y = std::floor(y / TILE_SIZE);
    _x *= TILE_SIZE;
    _y *= TILE_SIZE;
    std::cout << "The tile selected is: " << _x << " " << _y << std::endl;
    std::vector<int> tmp;
    tmp.push_back(_x);
    tmp.push_back(_y);
    std::cout << "The tile Number is " << tMap.at(tmp) << std::endl;

}
int frameCount, timerFPS, lastFrame, fps;
void generateTileSheetGrid()
{
    int colss = std::floor(TILE_MAP_HEIGHT / TILE_SIZE);
    int rowss = std::floor(TILE_MAP_WIDTH / TILE_SIZE);
    int counter = 1;
    int x = 0, y = 0;
    std::vector<int> tempVector;
    for (int i = 0; i < rowss; i++)
    {
        for (int j = 0; j < colss; j++)
        {
            tempVector.clear();
            tempVector.push_back(x);
            tempVector.push_back(y);
            tMap.insert({ tempVector, counter });
            std::cout << "X = " << x << std::endl;
            std::cout << "Y = " << y << std::endl;
            std::cout << " VAL = " << tMap.at(tempVector) << std::endl;

            x += TILE_SIZE;
            ++counter;
        }
        x = 0;
        y += TILE_SIZE;
    }
}



int main() {

    if (!init()) std::cout << "Failed at SDL_Init()" << std::endl;
    else {
        SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
        TTF_Init();
        Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
        SDL_Window* window = SDL_CreateWindow("Pong", 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
        SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

        SDL_Window* subWindow = SDL_CreateWindow("Sub Window", WINDOW_WIDTH, 0, 960, 320, 0);
        SDL_Renderer* subRenderer = SDL_CreateRenderer(subWindow, -1, 0);
        SDL_Texture* texture = ResourceManager::getInstance().loadTexture("./assets/Tileset.png", subRenderer);
        generateTileSheetGrid();


        bool running = true;
        bool buttons[4] = {};
        float dt = 0.0f;
        int playerOneScore = 0;
        int playerTwoScore = 0;
        static int lastTime = 0;
        bool winner = false;
        int xMos, yM;

        while (running) {

            auto startTime = std::chrono::high_resolution_clock::now();
            lastFrame = SDL_GetTicks();
            if (lastFrame >= (lastTime + 1000)) {
                lastTime = lastFrame;
                fps = frameCount;
                frameCount = 0;
            }

            SDL_Event event;
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                {
                    running = false;
                }
                else if (event.type == SDL_KEYDOWN)
                {
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                    {
                        running = false;
                    }
                    else if (event.key.keysym.sym == SDLK_w)
                    {
                        buttons[Buttons::PaddleOneUp] = true;
                    }
                    else if (event.key.keysym.sym == SDLK_s)
                    {
                        buttons[Buttons::PaddleOneDown] = true;
                    }
                    else if (event.key.keysym.sym == SDLK_UP)
                    {
                        buttons[Buttons::PaddleTwoUp] = true;
                    }
                    else if (event.key.keysym.sym == SDLK_DOWN)
                    {
                        buttons[Buttons::PaddleTwoDown] = true;
                    }


                }
                else if(event.type==SDL_MOUSEBUTTONDOWN){

                    switch(event.button.button){
                        case SDL_BUTTON_LEFT:
                            std::cout << "Left button pressed" << std::endl;
                            if (event.button.windowID == 2) {

                                
                                // std::cout << "Clicked in TILE MAP WINDOW" << std::endl;
                                // std::cout << "Xcoordinate" << event.button.x << "\n";
                                // std::cout << "YCoordinate" << event.button.y << "\n";
                                getTileNumber(event.button.x, event.button.y);

                            }
                            break;
                        case SDL_BUTTON_RIGHT:
                            // std::cout << "Right button pressed" << std::endl;
                            
                            // std::cout<<"Window ID"<<event.button.windowID<<"\n";
                            // SDL_MouseButtonEvent 
                            break;   
                    }

                }
            }
            


            SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0xFF);
            SDL_RenderClear(renderer);
            SDL_RenderClear(subRenderer);

            // Drawing the net
            SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
            

            frameCount++;
            timerFPS = SDL_GetTicks() - lastFrame;
            if (timerFPS < (1000 / FPS)) {
                SDL_Delay((1000 / FPS) - timerFPS);
            }
            // std::cout << "FPS: " << fps << std::endl;
            SDL_RenderCopy(subRenderer,texture,NULL,NULL);
            SDL_RenderPresent(renderer);
            SDL_RenderPresent(subRenderer);


            auto stopTime = std::chrono::high_resolution_clock::now();
            dt = std::chrono::duration<float, std::chrono::milliseconds::period>(stopTime - startTime).count();


          
        }
        
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    return 0;
}