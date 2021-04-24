#include <chrono>
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
// #include <SDL2/SDL_mixer.h>
#include <SDL2_image/SDL_image.h>
#include <ResourceManager.hpp>
#include "TileComponent.hpp"
#include "GameEngineTile.hpp"
#include "Engine.hpp"
#include "PlayerScore.hpp"
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <pybind11/pybind11.h>
// #include "Vec2.hpp"

// #define r 1 
// #define c 1

// int WINDOW_WIDTH = 960;
// int WINDOW_HEIGHT = 640;
int FPS = 60;

int TILE_MAP_HEIGHT = 960;
int TILE_MAP_WIDTH = 320;
int TILE_SIZE = 32;
using json = nlohmann::json;
// std::map<std::vector<int>, int> tMap;
// std::map<int,std::vector<int>> tMap2;

// std::map<std::vector<int>, int> gridMap;


// // std::map<int::GameEngineTile> gridMap;
// // r= WINDOW_WIDTH/32;
// // c= WINDOW_HEIGHT/32;

// GameEngineTile tileCollection[1000]; //Vector needed 

// std::vector<TileComponent> tileArray;
// enum Buttons
// {
//     PaddleOneUp = 0,
//     PaddleOneDown,
//     PaddleTwoUp,
//     PaddleTwoDown,
// };


bool Engine::initialize() {
    
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }
    return true;
}

void Engine::setInit(int WINDOW_WIDTH1, int WINDOW_HEIGHT1,std::string tilepath1){
    this->WINDOW_WIDTH=WINDOW_WIDTH1;
    this->WINDOW_HEIGHT=WINDOW_HEIGHT1;
    this->tilepath=tilepath1;



}
std::string Engine::currentTileInfo(int x){
   return tileCollection[x].info();





}
int Engine::gridNumber(){
    return gridSelected;
}


int Engine::getTileNumber(int x, int y) {
    
    int _x = std::floor( x / TILE_SIZE);
    int _y = std::floor(y / TILE_SIZE);
    _x *= TILE_SIZE;
    _y *= TILE_SIZE;
    // std::cout << "The tile selected is: " << _x << " " << _y << std::endl;
    std::vector<int> tmp;
    tmp.push_back(_x);
    tmp.push_back(_y);
    // std::cout << "The tile Number is " << tMap.at(tmp) << std::endl;
    return tMap.at(tmp);
}
int Engine::getGridNumber(int x, int y) {
    
    int _x = std::floor( x / TILE_SIZE);
    int _y = std::floor(y / TILE_SIZE);
    _x *= TILE_SIZE;
    _y *= TILE_SIZE;
    // std::cout << "The tile selected is: " << _x << " " << _y << std::endl;
    std::vector<int> tmp;
    tmp.push_back(_x);
    tmp.push_back(_y);
    // std::cout << "The tile Number is " << grid.at(tmp) << std::endl;
    return gridMap.at(tmp);

}
void Engine::Collectable(){
    tileCollection[gridSelected].setCollectable();

    

}
void Engine::Gravity(){
    tileCollection[gridSelected].setGravity();


}
void Engine::Collidable(){
    tileCollection[gridSelected].setCollidable();


}
void Engine::Playable(){
    tileCollection[gridSelected].setPlayable();


}
void Engine::AI(){
    tileCollection[gridSelected].setAI();

}
bool Engine::getCollectableInfo(){
    tileCollection[gridSelected].setGravity();


}
bool Engine:: getGravityInfo(){
    return  tileCollection[gridSelected].getGravity();


}
bool Engine:: getCollidableInfo(){
        return  tileCollection[gridSelected].getCollidable();

    
}
bool Engine:: getPlayableInfo(){
    return  tileCollection[gridSelected].getPlayable();


    
}
bool Engine:: getAIInfo(){
    return  tileCollection[gridSelected].getAI();
    
}

void Engine :: generateTileSheetGrid()
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
            tMap2.insert({counter,tempVector});
            // std::cout << "X = " << x << std::endl;
            // std::cout << "Y = " << y << std::endl;
            // std::cout << " VAL = " << tMap.at(tempVector) << std::endl;

            x += TILE_SIZE;
            ++counter;
        }
        x = 0;
        y += TILE_SIZE;
    }
}

std::vector<int> Engine ::returnCoordinates(int type){
        return tMap2.at(type);


}
int Engine:: gridValue(){
    return gridSelected;
}
void Engine :: generateGameEngineGrid(SDL_Texture* tex,SDL_Renderer* renderEngine)
{
    int colss = std::floor(WINDOW_WIDTH / TILE_SIZE);
    int rowss = std::floor(WINDOW_HEIGHT / TILE_SIZE);
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
            tileCollection[counter]= GameEngineTile(x,y,counter,tex,renderEngine);
            // GameEngineTile tileCreated= new GameEngineTile(x)
            gridMap.insert({ tempVector, counter });
            // std::cout << "X = " << x << std::endl;
            // std::cout << "Y = " << y << std::endl;
            // std::cout << " VAL = " << tMap.at(tempVector) << std::endl;


            x += TILE_SIZE;
            ++counter;
        }
        x = 0;
        y += TILE_SIZE;
    }
}

void Engine::download() {
    json jObject;
    GameEngineTile* tileObject;
    json jsonArray = json::array();
    for (int i = 0; i < (WINDOW_HEIGHT * WINDOW_WIDTH);i++) {
        jObject.clear();
        tileObject = tileCollection[i].getObject();
        jObject["X"] = tileObject->getXPos();
        jObject["Y"] = tileObject->getYPos();
        jObject["AI"] = tileObject->getAI();
        jObject["Gravity"] = tileObject->getGravity();
        jObject["Collectable"] = tileObject->getCollectable();
        jObject["Collide"] = tileObject->getCollidable();
        jObject["Playable"] = tileObject->getPlayable();
        jObject["TileNumber"] = tileObject->GetTileType();
        jsonArray.push_back(jObject);
    }
    std::ofstream out("tileMap.txt");
    out << jsonArray.dump();
    // std::cout << jsonArray.dump() << std::endl;
}



void Engine::Loop() {

    if (!initialize()) std::cout << "Failed at SDL_Init()" << std::endl;
    else {
        SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
        TTF_Init();
        Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
        SDL_Window* window = SDL_CreateWindow("Pong", 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT+100, SDL_WINDOW_SHOWN);
        SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
        // SDL_Texture* texture2 = ResourceManager::getInstance().loadTexture("./assets/Tileset.png", renderer);

        SDL_Window* subWindow = SDL_CreateWindow("Sub Window", WINDOW_WIDTH, 0, 960, 320, 0);
        SDL_Renderer* subRenderer = SDL_CreateRenderer(subWindow, -1, 0);
        SDL_Texture* texture = ResourceManager::getInstance().loadTexture(tilepath, subRenderer);
        SDL_Texture* texture2 = ResourceManager::getInstance().loadTexture(tilepath, renderer);
        scoreFont=ResourceManager::getInstance().loadFont("./assets/DejaVuSansMono.ttf",20);
            // scoreFont = resourceManager.loadFont(SCORE_FONT, 30);
        if (scoreFont==NULL){
            std::cout<<"NULL";
        }
        PlayerScore level(10,WINDOW_HEIGHT+10,renderer,scoreFont);



        generateTileSheetGrid();
        generateGameEngineGrid(texture2,renderer);
        


        bool running = true;
        bool buttons[4] = {};
        float dt = 0.0f;
        int playerOneScore = 0;
        int playerTwoScore = 0;
        static int lastTime = 0;
        bool winner = false;
        int xMos, yM;
        int tileSelected=0;
        // int gridSelected=0;

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
                    else if (event.key.keysym.sym == SDLK_a)
                    {
                        // current.setAI();   
                        // std::cout<<"Current Tile Selected"<<tileSelected<<std::endl;
                        // gridSelected=getGridNumber(event.button.x,event.button.y);
                        // std::vector<int> temp=tMap2.at(tileSelected);
                        // std::cout<<"Current Grid Selected"<<gridSelected<<std::endl;
                        tileCollection[gridSelected].setAI();
                        // current=tileCollection[gridSelected];

                        // buttons[Buttons::PaddleOneUp] = true;
                    }
                    else if (event.key.keysym.sym == SDLK_c)

                    {   tileCollection[gridSelected].setCollidable();
                        // current.setCollidable();   
                        // buttons[Buttons::PaddleOneUp] = true;
                    }
                    else if (event.key.keysym.sym == SDLK_p)
                    {
                        // current.setPlayable();   
                        tileCollection[gridSelected].setPlayable();
                        // buttons[Buttons::PaddleOneUp] = true;
                    }
                    else if (event.key.keysym.sym == SDLK_g)
                    {   tileCollection[gridSelected].setGravity();
                        // current.setGravity();   
                        // buttons[Buttons::PaddleOneUp] = true;
                    }
                    else if (event.key.keysym.sym == SDLK_s)
                    {
                        // buttons[Buttons::PaddleOneDown] = true;
                    }
                    else if (event.key.keysym.sym == SDLK_UP)
                    {
                        // buttons[Buttons::PaddleTwoUp] = true;
                    }
                    else if (event.key.keysym.sym == SDLK_DOWN)
                    {
                        // buttons[Buttons::PaddleTwoDown] = true;
                    }


                }
                else if (event.type == SDL_MOUSEBUTTONDOWN) {
                    try{
                    switch (event.button.button) {
                    case SDL_BUTTON_LEFT:
                        std::cout << "Left button pressed" << std::endl;
                        if (event.button.windowID == 2) {
                            tileSelected = getTileNumber(event.button.x, event.button.y);


                            // std::cout << "Clicked in TILE MAP WINDOW" << std::endl;
                            // std::cout << "XcoordinateT " << event.button.x << "\n";
                            // std::cout << "YCoordinateT" << event.button.y << "\n";
                            // int _x = std::floor( event.button.x / TILE_SIZE);
                            // int _y = std::floor(event.button.y/ TILE_SIZE);
                            // _x *= TILE_SIZE;
                            // _y *= TILE_SIZE;



                        }
                        if (event.button.windowID == 1) {
                            std::cout << "Clicked in Game WINDOW" << std::endl;
                            // std::cout << "Xcoordinate" << event.button.x << "\n";
                            // std::cout << "YCoordinate" << event.button.y << "\n"; 
                            // int _x = std::floor( event.button.x / TILE_SIZE);
                            // int _y = std::floor(event.button.y / TILE_SIZE);
                            // _x *= TILE_SIZE;
                            // _y *= TILE_SIZE;
                            // std::cout << "Xcoordinate" << _x << "\n";
                            // std::cout << "YCoordinate" << _y << "\n"; 
                            std::cout << "Current Tile Selected" << tileSelected << std::endl;
                            gridSelected = getGridNumber(event.button.x, event.button.y);
                            std::vector<int> temp = tMap2.at(tileSelected);
                            std::cout << "Current Grid Selected" << gridSelected << std::endl;
                            tileCollection[gridSelected].Update(temp.at(0), temp.at(1), tileSelected);
                            // current=tileCollection[gridSelected];




                        // tileCollection[gridSelected].Update()



                        }
                        break;
                    case SDL_BUTTON_RIGHT:
                        // std::cout << "Right button pressed" << std::endl;

                        // std::cout<<"Window ID"<<event.button.windowID<<"\n";
                        // SDL_MouseButtonEvent 
                        gridSelected = getGridNumber(event.button.x, event.button.y);
                        std::vector<int> temp = tMap2.at(tileSelected);
                        std::cout << "Current Grid Selected" << gridSelected << std::endl;
                        if (tileCollection[gridSelected].GetTileType() != 0) {
                            tileCollection[gridSelected].Reset();

                        }
                        // tileCollection[gridSelected].Update(temp.at(0),temp.at(1),tileSelected)
                        break;
                    }
                    }
                    catch (...) {
                        std::cout << "Please select the tile and then click on canvas" << std::endl;
                    }

                }
                else if (event.type==SDL_MOUSEBUTTONUP){

                    switch (event.button.button)
                    {
                    case SDL_BUTTON_LEFT:
                        std::cout<<"Left Button pressed"<<std::endl;
                        if(event.button.windowID==2){
                            //  tileSelected=getTileNumber(event.button.x, event.button.y);

                        }
                        if(event.button.windowID==1){
                            // gridSelected=getGridNumber(event.button.x,event.button.y);
                            // tileCollection[gridSelected].Update()
                            



                        }
                        /* code */
                        break;
                    
                    default:
                        break;
                    }


                }
            }
            // std::cout<<"Grid Selected "<<gridSelected<<"\n";
            // currentTileInfo(gridSelected);
            // current.info();
            // currentTileInfo(2);
            level.DisplayMessage(currentTileInfo(gridSelected));

            SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0xFF);
            SDL_SetRenderDrawColor(subRenderer, 0x0, 0x0, 0x0, 0xFF);

            SDL_RenderClear(renderer);
            SDL_RenderClear(subRenderer);

            // Drawing the net
            SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
            SDL_SetRenderDrawColor(subRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

            

            frameCount++;
            timerFPS = SDL_GetTicks() - lastFrame;
            if (timerFPS < (1000 / FPS)) {
                SDL_Delay((1000 / FPS) - timerFPS);
            }
            // std::cout << "FPS: " << fps << std::endl;
            SDL_RenderCopy(subRenderer,texture,NULL,NULL);
            for(int i=0; i <600;i++){
                tileCollection[i].Render(renderer);
            
            } 
            // for(int y=0; x<=WINDOW_HEIGHT; y+=32){
            //     SDL_RenderDrawLine(renderer,)
            // }
        //    SDL_SetRenderDrawColor(renderer,0xFF,0xFF,0xFF,0xFF);
        //     for(int x=0; x<WINDOW_WIDTH;x+=32){
        //         for (int y = 0; y < WINDOW_HEIGHT; y+=32)
        //         {
        //             SDL_RenderDrawPoint(renderer,x,y,WINDOW_WIDTH,WINDOW_HEIGHT);
        //         }
                
        //     }
         for (int x = 0; x < 1 + WINDOW_WIDTH;x += 32) {
            SDL_RenderDrawLine(renderer, x, 0, x, WINDOW_HEIGHT);
        }

        for (int y = 0; y < 1 + WINDOW_HEIGHT;y += 32) {
            SDL_RenderDrawLine(renderer, 0, y, WINDOW_WIDTH, y);
        }
        for (int x = 0; x < 1 + 960;x += 32) {
            SDL_RenderDrawLine(subRenderer, x, 0, x, 320);
        }

        for (int y = 0; y < 1 + 320;y += 32) {
            SDL_RenderDrawLine(subRenderer, 0, y, 960, y);
        }

            // for (int x = 0; x < 1 + WINDOW_WIDTH;
            //     x += grid_cell_size) {
            //     SDL_RenderDrawLine(renderer, x, 0, x, WINDOW_WIDTH);
            // }

            // for (int y = 0; y < 1 + WINDOW_HEIGHT;
            //     y += grid_cell_size) {
            //     SDL_RenderDrawLine(renderer, 0, y, WINDOW_HEIGHT, y);
            // }
            level.Draw();

            SDL_RenderPresent(renderer);
            SDL_RenderPresent(subRenderer);


            auto stopTime = std::chrono::high_resolution_clock::now();
            dt = std::chrono::duration<float, std::chrono::milliseconds::period>(stopTime - startTime).count();


          
        }
        
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    // return 0;
}
// int init(){
//     Engine ob = Engine();
//     std::cout<<"IM IN MAIN";
//     ob.Loop();
//     return 0;
// }
// Include the pybindings

namespace py = pybind11;


// Creates a macro function that will be called
// whenever the module is imported into python
// 'mygameengine' is what we 'import' into python.
// 'm' is the interface (creates a py::module object)
//      for which the bindings are created.
//  The magic here is in 'template metaprogramming'
PYBIND11_MODULE(mygameengine, m){
    m.doc() = "our game engine as a library"; // Optional docstring

    py::class_<Engine>(m, "Engine")
            .def(py::init())  
            .def("setInit",&Engine::setInit)  

            // .def(py::setInit<int,int,std::string>(), py::arg("WINDOW_WIDTH"), py::arg("WINDOW_HEIGHT"),py::arg("tilepath"))   // our constructor // our constructor
            .def("getTileNumber", &Engine::getTileNumber) // Expose member methods
            .def("getGridNumber", &Engine::getGridNumber) 
            .def("currentTileInfo", &Engine::currentTileInfo)
            .def("gridNumber", &Engine::gridNumber)
            .def("getGravity", &Engine::getGravityInfo) // Expose member methods
            .def("getCollectable", &Engine::getCollectableInfo) // Expose member methods
            .def("getCollidable", &Engine::getCollidableInfo) // Expose member methods
            .def("getPlayable", &Engine::getPlayableInfo) // Expose member methods
            .def("getAI", &Engine::getAIInfo) // Expose member methods
            .def("Gravity", &Engine::Gravity) // Expose member methods
            .def("Collectable", &Engine::Collectable) // Expose member methods
            .def("Collidable", &Engine::Collidable) // Expose member methods
            .def("Playable", &Engine::Playable) // Expose member methods
            .def("AI", &Engine::AI) // Expose member methods
            .def("gridSelected", &Engine::gridValue)
            .def("Loop", &Engine::Loop);
            
            // .def("DrawRectangle", &Engine::DrawRectangle) ;
// We do not need to expose everything to our users!
//            .def("getSDLWindow", &SDLGraphicsProgram::getSDLWindow, py::return_value_policy::reference) 
}



