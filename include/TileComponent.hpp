#ifndef TileComponent_hpp
#define TileComponent_hpp
#include <SDL2/SDL.h>



class TileComponent {
public:
    TileComponent(int x, int y, int type, SDL_Renderer* renderer);
    SDL_Rect src;
    SDL_Rect dest;
    int yPos;
    int xPos;
    SDL_Renderer* renderer;
    void Update();
    void Render();
    int tileType;
};


#endif