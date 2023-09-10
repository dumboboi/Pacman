#pragma once
#include <SFML/Graphics.hpp>
#include "vector"
class Pacman
{
public:
	Pacman();

	void update(std::vector<std::vector<char>>* lvl);
	void draw(sf::RenderWindow* window);
	void reset();
	sf::Vector2f getPosition() { return PacPos; }
	sf::FloatRect getGlobalBounds();


	//variables
	public:
	//pac's direction
	unsigned char Direction;
	//pacposition
	sf::Vector2f PacPos;
	//pac sprite
	sf::Sprite PacSprite;


	//variables
public:
	//count of big coin eaten
	unsigned short bigcoinCount;
	//true if pac ate big coins and false otherwise 
	bool Energized;
	//Timer when being energized.
	float EnergyTimer;
	//pac's speed
	float PacSpeed;
	//checks if pac has already ate 4 big coins
	bool VALID;
private:
	//pac's texture
	sf::Texture PacTexture;
	// this only change to 1/true when pac is facing left.(need this for animation)
	bool flipped;

};

