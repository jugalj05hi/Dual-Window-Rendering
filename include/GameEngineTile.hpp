#ifndef GameEngineTile_hpp
#define GameEngineTile_hpp
#include <SDL2/SDL.h>
#include<iostream>


class GameEngineTile{

    private:
       
        SDL_Rect src;
        SDL_Rect dest;
        int yPos;
        int xPos;
        SDL_Renderer* renderer_;
        // void Update(int x, int y);
        // void Render();
        int tileType=0;
        SDL_Texture* tex;
        bool isCollectable=false;
        bool isCollidable=false;
        bool isGravity=false;
        bool isPlayable=false;
        bool isAI=false;




        
        


    public:
        GameEngineTile();
        GameEngineTile(int x, int y, int type,SDL_Texture*text, SDL_Renderer* renderer);
        void Update(int x, int y, int z);
        void Render(SDL_Renderer* ren);
        void Reset();
        int GetTileType();
        void setCollectable();
        void setGravity();
        void setCollidable();
        void setPlayable();
        void setAI();
        bool getCollectable();
        bool getGravity();
        bool getCollidable();
        bool getPlayable();
        bool getAI();
        int getXPos();
        int getYPos();
        GameEngineTile* getObject();
        std::string info();

        
};





#endif
