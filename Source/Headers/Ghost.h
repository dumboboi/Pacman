#pragma once
#include "SFML/Graphics.hpp"
#include "vector"
class Ghost
{
public:
	//Constructor that creates a ghost by Giving it a texture and which rectangle to take from the texture(They all from the same png for better performance).
	Ghost(std::string texture, sf::IntRect ghostType);
	//Drawing the ghost sprite on the screen - POINTER
	void draw(sf::RenderWindow* window,bool energizedPek);
	//Initialize a ghost color/starting position/heading position
	void init(std::string ghostColor,sf::Vector2f startingPosition, sf::Vector2f headingPosition);
	//update a ghost
	void update(std::vector<std::vector<char>>* lvl,sf::Vector2f pacPosition);
	//ghost pathing to a certain position given
	void gettingInPosition(std::vector<std::vector<char>>* lvl,sf::Vector2f headingPosition);
	//guarding a big coin
	void guardingBigCoin(std::vector<std::vector<char>>* lvl, sf::Vector2f pacPosition);
	//Reset ghost status
	void reset();
	//returns ghost global bounds
	sf::FloatRect getGlobalBounds();


	//variables
public:
	sf::Vector2f ghostPosition;

private:
	sf::Vector2f startingPosition;
	sf::Vector2f headingPosition;
	sf::Vector2f Destination;
	sf::Texture ghostTexture;
	sf::Sprite ghostSprite;
	std::string ghostColor;
	float ghostSpeed = 1.f;
	float followCoolDown ;
	float maxTimeToGetToPac;
	bool inPosition;
	bool newDestination;
	bool canFollow;

};

