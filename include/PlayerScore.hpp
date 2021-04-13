/*!
   \file "PlayerScore_h"
   \brief "This is a header file for the PlayerScore class."
   \author "Raaghavv Devgon"
   \date "18"/"Feb"/"2021"
*/
#ifndef PlayerScore_h
#define PlayerScore_h

// #include "Vec2.hpp"
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_image/SDL_image.h>

/** @class PlayerScore
 *  @brief Class to store the screen rendering of scores and lives.
 */

class PlayerScore{

public:
	/**
	* @brief <This function draws the component on to the screen.>
	* @details <Draws the image component on the screen>
	*/

	void Draw();
	/**
* @brief <This function draws the image on to the screen.>
* @details <Draws the image component on the screen>
*/
  void DrawImg();
	/**
* @brief <This function sets the image the component on to the screen.>
* @param [in] <filename> <filepath of the image>
* @details <Draws the text component on the screen>
*/
	void setImage(std::string filename);
	/**
	* @brief <This is the constructor which requires the postion,renderer object and the font.>
	* @param [in] <postion> <position of the Text>
	* @param [in] <ren> <renderer of the text>
	* @param [in] <font> <font of the text>
	* @return <It's a constructor, so it doesnt return anything.>
	* @details <Sets up the PlayerScore>
	*/
  PlayerScore(int position_x,int position_y, SDL_Renderer* renderer, TTF_Font* font);

	/**
* @brief <This function sets the score to be displayed>
* @details < function returns the sets the score to be displayed>
*/

	void SetScore(int score);
	/**
* @brief <This function draws the level text on to the screen.>
* @param [in] <stringMessage> <message to write on the screen>
* @param [in] <score> <score of the user>
* @details <Draws the text component on the screen>
*/

	void SetLevelMessage(std::string stringMessage,int score);
	/**
* @brief <This function displays the level text on to the screen.>
* @param [in] <str> <message to write on the screen>
* @details <Draws the text component on the screen>
*/
void DisplayMessage(std::string str);
/**
* @brief <This function displays the resets text on to the screen.>
* @details <resets the message>
*/
void ResetScore();

/**
* @brief <Destructor.>
* @details <Destructor>
*/
  ~PlayerScore();
private:
	SDL_Renderer* renderer;/*!< Render to load on */
	TTF_Font* font;/*!< Font to be loaded */
	SDL_Surface* surface{};/*!< Surface to write on */
	SDL_Texture* texture{};/*!<Texture to render */
	SDL_Texture* imgTexture;/*!<Texture to render */
	SDL_Rect rect{}; /*!<area to write */
	SDL_Rect img{};/*!<img area to write */
	// Vec2 position; /*!< Initial Position of the ball, when the object is created */
    int posX;
    int posY;



};
#endif
