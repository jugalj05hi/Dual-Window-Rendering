#include "GameEngineTile.hpp"
GameEngineTile::GameEngineTile(){

}
GameEngineTile::GameEngineTile(int x, int y, int type,SDL_Texture* texture, SDL_Renderer* ren) 
{
    xPos=x;
    yPos=y;
    renderer_=ren;
    dest.x=xPos;
    dest.y=yPos;
    dest.w=32;
    dest.h=32;
    tileType=type;
    tex=texture;


}
void GameEngineTile::Update(int x,int y){
    std::cout<<"Update function from GameEngineTile";
    src.x=x;
    src.y=y;
    src.w=32;
    src.h=32;
    if(tex==NULL){
        std::cout<<"YES";
    }
    std::cout<<"src X "<<x;
    std::cout<<"\nsrc Y "<<y;
    std::cout<<"\ndest x "<<dest.x;
    std::cout<<"\ndest y "<<dest.y;


}


void GameEngineTile::Render(SDL_Renderer* r1){
    if(r1==NULL){
        std::cout<<"ERROR";
    }
    SDL_RenderCopy(r1,tex,&src,&dest);

    // SDL_RenderCopy(tex,&src,&dest,renderer);
}