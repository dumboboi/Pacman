#include "Pacman.h"
#include "Global.h"
#include "Collision.h"
#include "Animation.h"
Animation anim;


//constructor
Pacman::Pacman()
{
	//laoding texture.
	PacTexture.loadFromFile("EntitiesNoBG.png");
	PacSprite.setTexture(PacTexture);
	PacSprite.setTextureRect(sf::IntRect(32, 16, 32, 32));

	//whenever pac dies we reset him
	reset();
}

//all pac's update
void Pacman::update(std::vector<std::vector<char>>* lvl)
{
	//movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		Direction = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		Direction = 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		Direction = 3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		Direction = 4;
	}
	switch (Direction)
	{
	case 1:
	{
		flipped = 1;
		//checking collision with left wall
		if (!cells_collision(PacPos.x - 1, PacPos.y, lvl))
			PacPos.x -= PacSpeed;
		else
		{
			Direction = 0;
		}
			break;
	}
	case 2:
	{
		flipped = 0;
		//checking collision with right wall
		if (!cells_collision(PacPos.x + 1, PacPos.y, lvl))
			PacPos.x += PacSpeed;
		else
		{
			Direction = 0;
		}

		break;

	}
	case 3:
	{
		//checking collision with top wall
		if (!cells_collision(PacPos.x, PacPos.y - 1, lvl))
			PacPos.y -= PacSpeed;
		else
		{
			Direction = 0;
		}
			break;
	}
	case 4:
	{
		//checking collision with bottom wall
		if (!cells_collision(PacPos.x, PacPos.y + 1,lvl ))
			PacPos.y += PacSpeed;
		else
		{
			Direction = 0;
		}
			break;

	}
	default:
		break;
	}

	//pac's sprite position will take this variable(this is better than just working with a sprite only)
	PacSprite.setPosition(PacPos);


	//teleportation
	if (PacPos.x <= 2 && PacPos.y >= CELL_SIZE * 8)
	{
		PacPos.x = CELL_SIZE * 19 + 16 ;
	}
	if (PacPos.x >= CELL_SIZE *20 -2 && PacPos.y >= CELL_SIZE * 8)
	{
		PacPos.x = CELL_SIZE-16;
	}
	if (Energized)
	{
		if (EnergyTimer > 0)
		{
			EnergyTimer--;
		}
		else
		{
			EnergyTimer = 2000;
			Energized = 0;
		}

	}







}






//drawing pac
void Pacman::draw(sf::RenderWindow* window)
{
	//animation
		anim.pac(&PacSprite,Direction);
	window->draw(PacSprite);
}
//reseting pac's status/position...
void Pacman::reset()
{

	Direction = 0;
	PacSpeed = 1;
	//Spawning coords
	PacPos = sf::Vector2f(10 * CELL_SIZE, 15*CELL_SIZE );
	PacSprite.setPosition(PacPos);
	bigcoinCount = 0;
	flipped = 0;
	Energized = 0;
	EnergyTimer = 2000;
}
//return globa bounds of pacmen
sf::FloatRect Pacman::getGlobalBounds()
{
	return PacSprite.getGlobalBounds();
}