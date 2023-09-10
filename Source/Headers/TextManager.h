#pragma once
#include "SFML/Graphics.hpp"

//this is a class that manage texts , we use this so the Game class looks cleaner and not messy.
class TextsManager
{


public:
	TextsManager();
	//Functions that draws "Pac-Man" title on the window- POINTER
	void drawTitle(sf::RenderWindow* window);
	//This functions draws Score to the screen - RECURSIVE
	void drawScore(sf::RenderWindow* window, unsigned short Score ,int t);
	//---------------------//
	//This functions draw highscore on the window
	void drawHighScore(sf::RenderWindow* window);
	//This function draws my name Alex Simovski - POINTER
	void drawCredit(sf::RenderWindow* window);
	//This funnction draws a countdown  - POINTER
	void drawStartingTime(sf::RenderWindow* window,const float startingTimer);
	//This function updates highscore if we get a higher score
	void updateHighScoretxt(std::string str);
	//Drawing You won you can skip or keep playing for highscore - POINTER
	void drawYouWonYouCanSkip(sf::RenderWindow* window, const short Score);
	//Animation for text - POINTER
	void TextAnimation(sf::Text* text);


	//these are private variables that we use in functions
	public:
	sf::Texture titleTexture;
	sf::Sprite titleSprite;
	sf::Font font;
	sf::Text play;
	sf::Text HighScore;
	sf::Text Score;
	sf::Text Credit;
	sf::Text ScoreNUM;
	sf::Text Starting;
	std::vector<sf::Text>Scoretxts;
	sf::Text YouWonYouCanSkipText;
	sf::Text tip;
	int i = 0;
	short Loop = 1;
};

