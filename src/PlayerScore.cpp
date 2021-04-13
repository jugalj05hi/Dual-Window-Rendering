#include <SDL2/SDL.h>



#include <stdio.h>
#include <string>
#include<iostream>
// #include "Vec2.hpp"
#include "PlayerScore.hpp"
#include <SDL2_ttf/SDL_ttf.h>
PlayerScore::PlayerScore(int posX, int posY, SDL_Renderer* renderer, TTF_Font* font)
		: posX(posX),posY(posY),renderer(renderer), font(font){
   // renderer=render;
   // font=fontVal;
   surface = TTF_RenderText_Solid(font, "0", {0xFF, 0xFF, 0xFF, 0xFF});
	 texture = SDL_CreateTextureFromSurface(renderer, surface);

	  int width, height;
		SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);

		rect.x = static_cast<int>(posX);
    printf("%d",rect.x);
		rect.y = static_cast<int>(posY);
    printf("%d",rect.y);

		rect.w = width;
		rect.h = height;
}
PlayerScore::~PlayerScore(){
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}
void PlayerScore::Draw(){
  SDL_RenderCopy(renderer,texture,nullptr,&rect);
}

void PlayerScore::SetScore(int score){
		SDL_FreeSurface(surface);
		SDL_DestroyTexture(texture);

		surface = TTF_RenderText_Solid(font, std::to_string(score).c_str(), {0xFF, 0xFF, 0xFF, 0xFF});
		texture = SDL_CreateTextureFromSurface(renderer, surface);

		int width, height;
		SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
		rect.w = width;
		rect.h = height;

}
void PlayerScore::DisplayMessage(std::string message){
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);

	surface = TTF_RenderText_Solid(font, message.c_str(), {0xFF, 0xFF, 0xFF, 0xFF});
	texture = SDL_CreateTextureFromSurface(renderer, surface);

	int width, height;
	SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
	rect.w = width;
	rect.h = height;
	


}
 void PlayerScore::ResetScore(){
	 SDL_FreeSurface(surface);
	 SDL_DestroyTexture(texture);

	 surface = TTF_RenderText_Solid(font, "0", {0xFF, 0xFF, 0xFF, 0xFF});
	 texture = SDL_CreateTextureFromSurface(renderer, surface);
	 int width, height;
 	 SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
 	 rect.w = width;
 	 rect.h = height;
 }
 void PlayerScore::SetLevelMessage(std::string stringMessage,int score){
 		SDL_FreeSurface(surface);
 		SDL_DestroyTexture(texture);
		std::string message=stringMessage+""+std::to_string(score);

 		surface = TTF_RenderText_Solid(font, message.c_str(), {0xFF, 0xFF, 0xFF, 0xFF});
 		texture = SDL_CreateTextureFromSurface(renderer, surface);

 		int width, height;
 		SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
 		rect.w = width;
 		rect.h = height;

 }
 void PlayerScore::setImage(std::string filename){
	 imgTexture=IMG_LoadTexture(renderer,filename.c_str());


	 img.x = static_cast<int>(this->posX)/5;
	 // printf("%d",rect.x);
	 img.y = static_cast<int>(this->posY);
	 // printf("%d",rect.y);

	 img.w = 30;
	 img.h = 30;
 }
 void PlayerScore::DrawImg(){
   SDL_RenderCopy(renderer,imgTexture,nullptr,&img);
 }
