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
void GameEngineTile::Update(int x,int y, int z){
    std::cout<<"Update function from GameEngineTile";
    src.x=x;
    src.y=y;
    src.w=32;
    src.h=32;
    tileType=z;
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

int GameEngineTile::GetTileType(){
    return tileType;

}
void GameEngineTile::Reset(){
    src.x=NULL;
    src.y=NULL;
    tileType=0;
    isCollectable=false;
    isCollidable=false;
    isGravity=false;
    isPlayable=false;
    isAI=false;


    
}

void GameEngineTile::setCollectable(){
    isCollectable=!isCollectable;
    
}
void GameEngineTile::setGravity(){

    isGravity=!isGravity;

}
void GameEngineTile:: setCollidable(){
    isCollidable=!isCollidable;

}
void GameEngineTile:: setPlayable(){
    isPlayable=!isPlayable;

}
void GameEngineTile:: setAI(){
    isAI=!isAI;
    
}
////
bool GameEngineTile::getCollectable(){
    // isCollectable=!isCollectable;
    return isCollectable;
    
}
bool GameEngineTile::getGravity(){

    // isGravity=!isGravity;
    return isGravity;

}

bool GameEngineTile:: getCollidable(){
    return isCollidable;

}
bool GameEngineTile:: getPlayable(){
    return isPlayable;

}
bool GameEngineTile:: getAI(){
    return isAI;
    
}
std::string GameEngineTile::info(){
    // std::cout<<"X coodinate:"<<xPos<<"\n";
    // std::cout<<"Y"<<yPos<<"\n";
    // std::cout<<"is Collidable"<<isCollidable<<"\n";
    // std::cout<<"is AI"<<isAI<<"\n";
    // std::cout<<"is Collectable"<<isCollectable<<"\n";
    // std::cout<<"is Input:"<<isPlayable<<"\n";
    // std::cout<<"is Gravity:"<<isGravity<<"\n";
    std::string infoVal="X:"+std::to_string(xPos)+" Y:"+std::to_string(yPos)+
                        "AI: "+std::to_string(isAI)+
                        " Collectable:"+std::to_string(isCollectable)+
                        " Collidable:"+std::to_string(isCollidable)+
                        " Playable:"+std::to_string(isPlayable)+
                        " Gravity:"+std::to_string(isGravity);
     ;
    return infoVal;


}
