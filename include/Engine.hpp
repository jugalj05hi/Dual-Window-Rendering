#ifndef Engine_hpp
#define Engine_hpp
#include <SDL2/SDL.h>
#include<iostream>
#include"GameEngineTile.hpp"
#include"TileComponent.hpp"
#include<vector>
#include<map>
#include<string>
#include "json.hpp"
class Engine {

    private:
        int WINDOW_WIDTH;
        int WINDOW_HEIGHT;
        std::string tilepath;
        std::string tilepathC;

        
        std::map<std::vector<int>, int> tMap;
        std::map<int,std::vector<int>> tMap2;

        std::map<std::vector<int>, int> gridMap;
        int frameCount, timerFPS, lastFrame, fps;


        // std::map<int::GameEngineTile> gridMap;
        // r= WINDOW_WIDTH/32;
        // c= WINDOW_HEIGHT/32;

        GameEngineTile tileCollection[1000]; //Vector needed 
        GameEngineTile current;
        std::vector<TileComponent> tileArray;
        int gridSelected=0;
        TTF_Font* scoreFont;
        bool windowFlag = false;

        // SDL_Rect src;
        // SDL_Rect dest;
        // int yPos;
        // int xPos;
        // SDL_Renderer* renderer_;
        // // void Update(int x, int y);
        // // void Render();
        // int tileType=0;
        // SDL_Texture* tex;
        


    public:
        bool initialize();
        void setInit(int w, int h,std::string tilepath,std::string tilepath2);
        int getTileNumber(int x, int y);
        int getGridNumber(int x, int y);
        // int get
        std::string currentTileInfo(int x);
        void generateTileSheetGrid();
        int gridNumber();
        void Collectable();
        void Gravity();
        void Collidable();
        void Playable();
        void AI();
        bool getCollectableInfo();
        bool getGravityInfo();
        bool getCollidableInfo();
        bool getPlayableInfo();
        bool getAIInfo();
        int gridValue();
        void download();
         std::vector<int> returnCoordinates(int type);
        void generateGameEngineGrid(SDL_Texture* tex,SDL_Renderer* renderEngine);
        void Loop();

        
};



#endif
