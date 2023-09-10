#pragma once
#include "SFML/Graphics.hpp"

class Animation
{

public:
	Animation();
	void pac(sf::Sprite* pacSprite,unsigned char Direction);
	void coinAnim(sf::Sprite* coinSprite);
	void redGhost(sf::Sprite* ghostSprite);
	void blueGhost(sf::Sprite* ghostSprite);
	void pinkGhost(sf::Sprite* ghostSprite);
	void orangeGhost(sf::Sprite* ghostSprite);
	void scaredGhost(sf::Sprite* ghostSprite);


private:
	float pacanimtimer;
	float coinanimtimer;
	float redghosttimer;
	float blueghosttimer;
	float pinkghosttimer;
	float orangeghosttimer;
	float scaredghosttimer;

};

