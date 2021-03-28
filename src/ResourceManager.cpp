/*
 *  @file   ResourceManager.cpp
 *  @brief  ResourcesManager class function implementations
 *  @date   2021-03-12
 ***********************************************/
#include "ResourceManager.hpp"
void ResourceManager::StartUp(SDL_Renderer* renderer) {
    // loadTexture(TILE_SHEET, renderer);
    // loadTexture(COIN_SPRITE, renderer);
    // loadTexture(DINO_SPRITE, renderer);
    // loadTexture(ENEMY_AI_SPRITE, renderer);
    // loadTexture(WIN_SPRITE, renderer);
    // loadTexture(BG_IMAGE, renderer);
    // loadTexture(SCREEN_START, renderer);
    // loadTexture(SCREEN_LOSE, renderer);
    // loadTexture(SCREEN_WIN, renderer);
    // loadTexture(IMG_HEART, renderer);
    // loadWAV(JUMP_SOUND);
    // loadWAV(DEATH_SOUND);
    // loadWAV(EAT_SOUND);
    // loadWAV(JUMP_SOUND);
}
ResourceManager &ResourceManager::getInstance()
{
    static ResourceManager *instance = new ResourceManager();
    return *instance;
}

SDL_Texture *ResourceManager::loadTexture(std::string filePath, SDL_Renderer *renderer)
{
    if (textureMap.find(filePath) != textureMap.end())
    {
        return textureMap.at(filePath);
    }
    else
    {
        // create resource
        SDL_Texture *texture = IMG_LoadTexture(renderer, filePath.c_str());
        // store in dict
        textureMap[filePath] = texture;
        if (textureMap[filePath] == NULL) {
            SDL_Log("Failed to insert into Texture Map");
            std::cout << filePath << std::endl;
        }
        return texture;
    }
}
SDL_Surface *ResourceManager::loadSurface(std::string filePath, SDL_Renderer *renderer)
{
    if (surfaceMap.find(filePath) != surfaceMap.end())
    {
        return surfaceMap.at(filePath);
    }
    else
    {
        SDL_Surface *surface = IMG_Load(filePath.c_str());
        surfaceMap[filePath] = surface;
        if (surfaceMap[filePath] == NULL)
            SDL_Log("Failed to insert into Surface Map");
        return surface;
    }
}

TTF_Font *ResourceManager::loadFont(std::string filePath, int fontSize)
{
    if (fontMap.find(filePath) != fontMap.end())
    {
        return fontMap.at(filePath);
    }
    else
    {
        //Initialize SDL_ttf
        if (TTF_Init() == -1)
        {
            SDL_Log("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        }
        // create resource
        TTF_Font *font = TTF_OpenFont(filePath.c_str(), fontSize);
        // store in dict
        fontMap.insert({filePath, font});
        if (fontMap.at(filePath) != font)
            SDL_Log("Failed to insert into map");
        return font;
    }
}

Mix_Music *ResourceManager::loadMusic(std::string filePath)
{
    if (soundMap.find(filePath) != soundMap.end())
    {
        return soundMap.at(filePath);
    }
    else
    {
        // create resource
        Mix_Music *sound = Mix_LoadMUS(filePath.c_str());
        // store in dict
        soundMap[filePath] = sound;
        return sound;
    }
}

Mix_Chunk *ResourceManager::loadWAV(std::string filePath)
{
    if (soundEffectMap.find(filePath) != soundEffectMap.end())
    {
        return soundEffectMap.at(filePath);
    }
    else
    {
        // create resource
        Mix_Chunk *sound = Mix_LoadWAV(filePath.c_str());
        // store in dict
        soundEffectMap[filePath] = sound;
        return sound;
    }
}

void ResourceManager::setWords(std::string english, std::string french)
{

    languageMap.insert({english, french});
}

std::string ResourceManager::getWords(std::string word)
{
    if (!language)
    {
        std::string s = word;
        try
        {
            return languageMap.find(s)->second.c_str();
        }
        catch (std::out_of_range &e)
        {
            std::cout << "Something broke in getwords" << std::endl;
        }
    }
    return word;
}

void ResourceManager::setLanguage(int languageCode)
{
    language = languageCode;
}

void ResourceManager::loadWords()
{
    std::ifstream english("./assets/scripts/english.txt");
    std::ifstream french("./assets/scripts/french.txt");
    std::string en;
    std::string fr;
    if (english && french)
    {

        while (std::getline(english, en, '\n') && std::getline(french, fr, '\n'))
        {

            setWords(en, fr);
        }
    }
}
