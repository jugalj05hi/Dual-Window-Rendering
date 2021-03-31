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
        int tileType;
        SDL_Texture* tex;
        


    public:
        GameEngineTile();
        GameEngineTile(int x, int y, int type,SDL_Texture*text, SDL_Renderer* renderer);
        void Update(int x, int y);
        void Render(SDL_Renderer* ren);
};





#endif
