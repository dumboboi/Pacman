#include "Animation.h"


Animation::Animation():
	//giving time for timers.
	pacanimtimer(45),
	coinanimtimer(240),
	redghosttimer(192),
	blueghosttimer(192),
	pinkghosttimer(192),
	orangeghosttimer(192),
	scaredghosttimer(80)
{
}


//pek's animation
void Animation::pac(sf::Sprite* pacSprite, unsigned char Direction)
{
	//pek's animation is made with 3 frames so it only need a short timer. so i made it 60ms.
	if (pacanimtimer >= 30)
	{
		if(Direction ==2)
			//looking right
			pacSprite->setTextureRect(sf::IntRect(32, 16, 32, 32));
		else if(Direction == 1)
			//looking left
			pacSprite->setTextureRect(sf::IntRect(194, 16, 32, 32));
		else if(Direction == 4)
			pacSprite->setTextureRect(sf::IntRect(194, 48, 32, 32));
		else if (Direction == 3)
			pacSprite->setTextureRect(sf::IntRect(194, 209, 32, 32));


	}else if(pacanimtimer >= 15)
	{
		if (Direction == 2)
			pacSprite->setTextureRect(sf::IntRect(64, 16, 32, 32));
		else if (Direction == 1)
			pacSprite->setTextureRect(sf::IntRect(162, 16, 32, 32));
		else if (Direction == 4)
			pacSprite->setTextureRect(sf::IntRect(194, 80, 32, 32));
		else if (Direction == 3)
			pacSprite->setTextureRect(sf::IntRect(194, 177, 32, 32));
	}
	else if (pacanimtimer >= 0)
	{
		if (Direction == 2)
			pacSprite->setTextureRect(sf::IntRect(96,16, 32, 32));
		else if (Direction == 1)
			pacSprite->setTextureRect(sf::IntRect(130, 16, 32, 32));
		else if (Direction == 4)
			pacSprite->setTextureRect(sf::IntRect(194, 112, 32, 32));
		else if (Direction == 3)
			pacSprite->setTextureRect(sf::IntRect(194, 145, 32, 32));
	}
	else{
		//timer goes back up
		pacanimtimer = 45;
	}
	//timer decreases
	pacanimtimer--;
}

//Coins animation
void Animation::coinAnim(sf::Sprite* coinSprite)
{
	//coins animation is made with 8 frames so it need longer timer than pek's animation timer. so i made it 240ms. so every frame takes 40s.
	if (coinanimtimer >= 210)
	{
		coinSprite->setTextureRect(sf::IntRect(0, 0, 32, 32));
	}
	else if (coinanimtimer >= 180)
	{

		coinSprite->setTextureRect(sf::IntRect(32,0, 32, 32));
	}
	else if (coinanimtimer >= 150)
	{
		coinSprite->setTextureRect(sf::IntRect(64, 0, 32, 32));

	}
	else if (coinanimtimer >= 120)
	{
		coinSprite->setTextureRect(sf::IntRect(96, 0, 32, 32));
	}
	else if (coinanimtimer >= 90)
	{
		coinSprite->setTextureRect(sf::IntRect(128, 0, 32, 32));
	}
	else if (coinanimtimer >= 60)
	{
		coinSprite->setTextureRect(sf::IntRect(160, 0, 32, 32));
	}
	else if (coinanimtimer >= 30)
	{
		coinSprite->setTextureRect(sf::IntRect(192, 0, 32 ,32));
	}
	else if (coinanimtimer >= 0)
	{
		coinSprite->setTextureRect(sf::IntRect(224, 0, 32, 32));
	}
	else {
		//timer goes back up
		coinanimtimer = 240;
	}
	//timer decreases
	coinanimtimer--;
}

//Red ghost animation
void Animation::redGhost(sf::Sprite* ghostSprite)
{
	if (redghosttimer >= 168)
	{
		ghostSprite->setTextureRect(sf::IntRect(0, 64, 16, 16));
	}
	else if (redghosttimer >= 144)
	{

		ghostSprite->setTextureRect(sf::IntRect(17, 64, 16, 16));
	}
	else if (redghosttimer >= 120)
	{
		ghostSprite->setTextureRect(sf::IntRect(33, 64, 16, 16));
	}
	else if (redghosttimer >= 96)
	{
		ghostSprite->setTextureRect(sf::IntRect(49, 64, 16, 16));
	}
	else if (redghosttimer >= 72)
	{
		ghostSprite->setTextureRect(sf::IntRect(65, 64, 16, 16));
	}
	else if (redghosttimer >= 48)
	{
		ghostSprite->setTextureRect(sf::IntRect(81, 64, 16, 16));
	}
	else if (redghosttimer >= 24)
	{
		ghostSprite->setTextureRect(sf::IntRect(97, 64, 16, 16));
	}
	else if (redghosttimer >= 0)
	{
		ghostSprite->setTextureRect(sf::IntRect(113, 64, 16, 16));
	}
	else {
		//timer goes back up
		redghosttimer = 192;
	}
	//timer decreases
	redghosttimer--;
}
//Blue ghost animation
void Animation::blueGhost(sf::Sprite* ghostSprite)
{
	if (blueghosttimer >= 168)
	{
		ghostSprite->setTextureRect(sf::IntRect(0, 96, 16, 16));
	}
	else if (blueghosttimer >= 144)
	{

		ghostSprite->setTextureRect(sf::IntRect(17, 96, 16, 16));
	}
	else if (blueghosttimer >= 120)
	{
		ghostSprite->setTextureRect(sf::IntRect(33, 96, 16, 16));
	}
	else if (blueghosttimer >= 96)
	{
		ghostSprite->setTextureRect(sf::IntRect(49, 96, 16, 16));
	}
	else if (blueghosttimer >= 72)
	{
		ghostSprite->setTextureRect(sf::IntRect(65, 96, 16, 16));
	}
	else if (blueghosttimer >= 48)
	{
		ghostSprite->setTextureRect(sf::IntRect(81, 96, 16, 16));
	}
	else if (blueghosttimer >= 24)
	{
		ghostSprite->setTextureRect(sf::IntRect(97, 96, 16, 16));
	}
	else if (blueghosttimer >= 0)
	{
		ghostSprite->setTextureRect(sf::IntRect(113, 96, 16, 16));
	}
	else {
		//timer goes back up
		blueghosttimer = 192;
	}
	//timer decreases
	blueghosttimer--;

}
//Pink ghost animation
void Animation::pinkGhost(sf::Sprite* ghostSprite)
{
	if (pinkghosttimer >= 168)
	{
		ghostSprite->setTextureRect(sf::IntRect(0, 80, 16, 16));
	}
	else if (pinkghosttimer >= 144)
	{

		ghostSprite->setTextureRect(sf::IntRect(17, 80, 16, 16));
	}
	else if (pinkghosttimer >= 120)
	{
		ghostSprite->setTextureRect(sf::IntRect(33, 80, 16, 16));
	}
	else if (pinkghosttimer >= 96)
	{
		ghostSprite->setTextureRect(sf::IntRect(49, 80, 16, 16));
	}
	else if (pinkghosttimer >= 72)
	{
		ghostSprite->setTextureRect(sf::IntRect(65, 80, 16, 16));
	}
	else if (pinkghosttimer >= 48)
	{
		ghostSprite->setTextureRect(sf::IntRect(81, 80, 16, 16));
	}
	else if (pinkghosttimer >= 24)
	{
		ghostSprite->setTextureRect(sf::IntRect(97, 80, 16, 16));
	}
	else if (pinkghosttimer >= 0)
	{
		ghostSprite->setTextureRect(sf::IntRect(113, 80, 16, 16));
	}
	else {
		//timer goes back up
		pinkghosttimer = 192;
	}
	//timer decreases
	pinkghosttimer--;

}

//Orange ghost animation
void Animation::orangeGhost(sf::Sprite* ghostSprite)
{
	if (orangeghosttimer >= 168)
	{
		ghostSprite->setTextureRect(sf::IntRect(0, 112, 16, 16));
	}
	else if (orangeghosttimer >= 144)
	{

		ghostSprite->setTextureRect(sf::IntRect(17, 112, 16, 16));
	}
	else if (orangeghosttimer >= 120)
	{
		ghostSprite->setTextureRect(sf::IntRect(33, 112, 16, 16));
	}
	else if (orangeghosttimer >= 96)
	{
		ghostSprite->setTextureRect(sf::IntRect(49, 112, 16, 16));
	}
	else if (orangeghosttimer >= 72)
	{
		ghostSprite->setTextureRect(sf::IntRect(65, 112, 16, 16));
	}
	else if (orangeghosttimer >= 48)
	{
		ghostSprite->setTextureRect(sf::IntRect(81, 112, 16, 16));
	}
	else if (orangeghosttimer >= 24)
	{
		ghostSprite->setTextureRect(sf::IntRect(97, 112, 16, 16));
	}
	else if (orangeghosttimer >= 0)
	{
		ghostSprite->setTextureRect(sf::IntRect(113, 112, 16, 16));
	}
	else {
		//timer goes back up
		orangeghosttimer = 192;
	}
	//timer decreases
	orangeghosttimer--;

}
//		ghostSprite->setTextureRect(sf::IntRect(129, 64, 16, 16));

//Animation for ghosts when pek becomes energized(all 4 of them will use this function)
void Animation::scaredGhost(sf::Sprite* ghostSprite)
{
	if (scaredghosttimer >= 60)
	{
		ghostSprite->setTextureRect(sf::IntRect(129, 64, 16, 16));
	}
	else if (scaredghosttimer >= 40)
	{
		ghostSprite->setTextureRect(sf::IntRect(145, 64, 16, 16));
	}
	else if (scaredghosttimer >= 20)
	{
		ghostSprite->setTextureRect(sf::IntRect(161, 64, 16, 16));
	}
	else if (scaredghosttimer >= 0)
	{
		ghostSprite->setTextureRect(sf::IntRect(177, 64, 16, 16));
	}
	else
	{
		scaredghosttimer = 80;
	}
	scaredghosttimer--;
}
