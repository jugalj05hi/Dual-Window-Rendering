/*
 *  @file   ResourceManager.hpp
 *  @brief  ResourceManager class interface 
 *  @date   2021-03-12
 ***********************************************/
#ifndef ResourceManager_hpp
#define ResourceManager_hpp
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
// #include <SDL2/SDL_mixer.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2_image/SDL_image.h>
#include <unordered_map>
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <string>
/**
 * The resource manager is responsible for handling and managing resources regarding the game
 */
class ResourceManager
{
private:
  /**
    * Hashmap used to keep track of Images where path to image is key and its Spritesheet is value
    */
  std::map<std::string, SDL_Texture *> textureMap;

  /**
   * Hashmap used to keep track of Images where path to image is key and its SDL_Surface is value
   */
  std::map<std::string, SDL_Surface *> surfaceMap;

  /**
    * Hashmap used to keep track of fonts where path to font is key and its TTF_Font class is value
    */
  std::map<std::string, TTF_Font *> fontMap;

  /**
    * Hashmap used to keep track of musics where path to music is key and its Mix_Music class is value
    */
  std::map<std::string, Mix_Music *> soundMap;

  /**
      * * Hashmap used to keep track of musics where path to sound effect is key and its Mix_Chunk class is value
    */
  std::map<std::string, Mix_Chunk *> soundEffectMap;

  /**
     * * Hashmap used to keep track of English to French translation where english word is key and its french counterpart class is value
   */
  std::map<std::string, std::string> languageMap;

  /**
      * The lanugage flag to know which language is currently in use
      */
  int language;

  /**
      * Constructor of class Resource Manager
      */
  ResourceManager() {}

public:
  /**
   * Loads the Resources in advance
   */
  void StartUp(SDL_Renderer* renderer);
  /**
    * Method used to get instance of ResourceManager class
    * @return static instance of Resource Manager class
    */
  static ResourceManager &getInstance();

  /**
    * Method used to load Spritesheet of Images from their path
    * @param filePath path where image is stored
    * @return Spritesheet of respective image in the form of SDL_Surface*
    */
  SDL_Texture *loadTexture(std::string filePath, SDL_Renderer *renderer);

  /**
    * Method used to load Spritesheet of Images from their path
    * @param filePath path where image is stored
    * @return Spritesheet of respective image in the form of SDL_Surface*
    */
  SDL_Surface *loadSurface(std::string filePath, SDL_Renderer *renderer);

  /**
    * Method used to load TTF_Font object of respective font from its path
    * @param filePath path where font is stored
    * @return TTF_Font object of respective font
    */
  TTF_Font *loadFont(std::string filePath, int fontSize);

  /**
    * Method used to load Mix_Music object of respective music from its path
    * @param filePath path where music is stored
    * @return Mix_Music object of respective music
    */
  Mix_Music *loadMusic(std::string filePath);
  /**
    * Method used to load Mix_Chunk object of respective music from its path
    * @param filePath path where music is stored
    * @return Mix_Chunk object of respective music
    */
  Mix_Chunk *loadWAV(std::string filePath);

  /**
     *Metohd used to set translation words in LanguageMap
     * @param english the english word
     * @param french It's french counterpart
     */
  void setWords(std::string english, std::string french);

  /**
     *Method used to get words based on the language, i.e English or French
     * @param phrase The english phrase/words
     * @return Either a French Phrase or an English Phrase based on the language selected
     */
  std::string getWords(std::string phrase);

  /**
     *Method to set language so other methods can know which language phrase to return
     * @param languageCode 1 for english and 0 for french
     */
  void setLanguage(int languageCode);
  /**
     *Method to load the words from multiple scripts in the script folder. Right now only English and French is supported
     */
  void loadWords();
};
#endif
