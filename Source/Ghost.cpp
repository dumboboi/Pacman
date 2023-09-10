#include "Ghost.h"
#include "Global.h"
#include "Animation.h"
#include "Collision.h"
#include "iostream"
//Creating an animator for ghosts
Animation ghostAnim;


Ghost::Ghost(std::string  texture, sf::IntRect ghostType)
{
	//loading textures in sprites
	ghostTexture.loadFromFile(texture);
	ghostSprite.setTexture(ghostTexture);
	ghostSprite.setTextureRect(ghostType);
	ghostSprite.setScale(2.f, 2.f);
	reset();
}

//getting in position - POINTER
void Ghost::gettingInPosition(std::vector<std::vector<char>>* lvl, sf::Vector2f headingPosition)
{
	//the distance between the headingposition and ghostposition must be <=1
	if (distance(ghostPosition, headingPosition) > 1)
	{
		//ping/orange ghosts movements
		if (ghostColor == "Pink" || ghostColor == "Orange")
		{
			if (!cells_collision(ghostPosition.x, ghostPosition.y + ghostSpeed, lvl) && headingPosition.y > ghostPosition.y)
				ghostPosition.y += ghostSpeed;
			else  if (!cells_collision(ghostPosition.x + ghostSpeed, ghostPosition.y, lvl) && headingPosition.x > ghostPosition.x)
				ghostPosition.x += ghostSpeed;
			else  if (!cells_collision(ghostPosition.x - ghostSpeed, ghostPosition.y, lvl) && headingPosition.x < ghostPosition.x)
				ghostPosition.x -= ghostSpeed;
			else if (!cells_collision(ghostPosition.x, ghostPosition.y - ghostSpeed, lvl) && headingPosition.y < ghostPosition.y)
				ghostPosition.y -= ghostSpeed;

		}
		else  //blue/red ghosts movements
		{
			if (!cells_collision(ghostPosition.x, ghostPosition.y - 1.f, lvl) && headingPosition.y < ghostPosition.y)
				ghostPosition.y -= ghostSpeed;
			else  if (!cells_collision(ghostPosition.x + 1.f, ghostPosition.y, lvl) && headingPosition.x > ghostPosition.x)
				ghostPosition.x += ghostSpeed;
			else  if (!cells_collision(ghostPosition.x - 1.f, ghostPosition.y, lvl) && headingPosition.x < ghostPosition.x)
				ghostPosition.x -= ghostSpeed;
			else if (!cells_collision(ghostPosition.x, ghostPosition.y + 1.f, lvl) && headingPosition.y > ghostPosition.y)
				ghostPosition.y += ghostSpeed;
		}
	}
	else
	{
		inPosition = 1;
		newDestination = 1;
	}
}

//gurding some position - POINTER
void Ghost::guardingBigCoin(std::vector<std::vector<char>>* lvl, sf::Vector2f pacPosition)
{
	if (ghostColor == "Red")
	{
		Destination = pacPosition;
	}
	else
	{
		//ghosts will have 12 different position and each one will get a random position when he gets too close to pac(still can kill pekmen if touched)
		if (newDestination == 1)
		{
			int r = rand() % 12;
			switch (r)
			{
			case 0:
			{
				Destination = sf::Vector2f(18 * CELL_SIZE, CELL_SIZE);
				newDestination = 0;
				break;
			}
			case 1:
			{
				Destination = sf::Vector2f(11 * CELL_SIZE, CELL_SIZE);
				newDestination = 0;
				break;
			}

			case 2:
			{
				Destination = sf::Vector2f(15 * CELL_SIZE, 3 * CELL_SIZE);
				newDestination = 0;
				break;
			}
			case 3:
			{
				Destination = sf::Vector2f(18 * CELL_SIZE, 5 * CELL_SIZE);
				newDestination = 0;
				break;
			}
			case 4:
			{
				Destination = sf::Vector2f(CELL_SIZE * 2, CELL_SIZE);
				newDestination = 0;
				break;
			}
			case 5:
			{
				Destination = sf::Vector2f(9 * CELL_SIZE, CELL_SIZE);
				newDestination = 0;
				break;
			}
			case 6:
			{
				Destination = sf::Vector2f(5 * CELL_SIZE, 4 * CELL_SIZE);
				newDestination = 0;
				break;
			}
			case 7:
			{
				Destination = sf::Vector2f(3 * CELL_SIZE, 5 * CELL_SIZE);
				newDestination = 0;
				break;
			}
			case 8:
			{
				Destination = sf::Vector2f(CELL_SIZE * 2, CELL_SIZE * 19);
				newDestination = 0;
				break;
			}
			case 9:
			{
				Destination = sf::Vector2f(10 * CELL_SIZE, 19 * CELL_SIZE);
				newDestination = 0;
				break;
			}
			case 10:
			{
				Destination = sf::Vector2f(CELL_SIZE * 18, CELL_SIZE * 19);
				newDestination = 0;
				break;
			}
			case 11:
			{
				Destination = sf::Vector2f(10 * CELL_SIZE, 19 * CELL_SIZE);
				newDestination = 0;
				break;
			}
			default:
				break;

			}
		}
	}
	//Use that function we used at first for the headingposition with the random destination
	gettingInPosition(lvl, Destination);

}

//All updates of a ghost - POINTER
void Ghost::update(std::vector<std::vector<char>>* lvl, sf::Vector2f pacPosition)
{
	//sprite position takes ghostposition
	ghostSprite.setPosition(ghostPosition);
	if (!inPosition)
	{
		gettingInPosition(lvl, headingPosition);
	}//Added follow pacmen code
	//if a ghost if far more than 2 cells from pac and can follow him =  he heads towards him.
	else if (distance(ghostPosition, pacPosition) > CELL_SIZE * 2 && canFollow)
	{
		//Movements and checking collision
		if (ghostColor == "Red")
		{
			if (!cells_collision(ghostPosition.x, ghostPosition.y + 1, lvl) && pacPosition.y > ghostPosition.x)
			{
				ghostPosition.y += ghostSpeed;
			}
			else if (!cells_collision(ghostPosition.x, ghostPosition.y - 1, lvl) && pacPosition.y < ghostPosition.x)
			{
				ghostPosition.y -= ghostSpeed;
			}
			else if (!cells_collision(ghostPosition.x + 1, ghostPosition.y, lvl) && pacPosition.x > ghostPosition.x)
			{
				ghostPosition.x += ghostSpeed;
			}
			else if (!cells_collision(ghostPosition.x - 1, ghostPosition.y, lvl) && pacPosition.x < ghostPosition.x)
			{
				ghostPosition.x -= ghostSpeed;
			}

		}
		else if (ghostColor == "Blue")
		{
			if (!cells_collision(ghostPosition.x, ghostPosition.y - 1, lvl) && pacPosition.y < ghostPosition.x)
			{
				ghostPosition.y -= ghostSpeed;
			}
			else if (!cells_collision(ghostPosition.x - 1, ghostPosition.y, lvl) && pacPosition.x < ghostPosition.x)
			{
				ghostPosition.x -= ghostSpeed;
			}
			else if (!cells_collision(ghostPosition.x, ghostPosition.y + 1, lvl) && pacPosition.y > ghostPosition.x)
			{
				ghostPosition.y += ghostSpeed;
			}

			else if (!cells_collision(ghostPosition.x + 1, ghostPosition.y, lvl) && pacPosition.x > ghostPosition.x)
			{
				ghostPosition.x += ghostSpeed;
			}

		}
		else if (ghostColor == "Pink")
		{
			if (!cells_collision(ghostPosition.x + 1, ghostPosition.y, lvl) && pacPosition.x > ghostPosition.x)
			{
				ghostPosition.x += ghostSpeed;
			}
			else if (!cells_collision(ghostPosition.x - 1, ghostPosition.y, lvl) && pacPosition.x < ghostPosition.x)
			{
				ghostPosition.x -= ghostSpeed;
			}
			else if (!cells_collision(ghostPosition.x, ghostPosition.y + 1, lvl) && pacPosition.y > ghostPosition.x)
			{
				ghostPosition.y += ghostSpeed;
			}
			else if (!cells_collision(ghostPosition.x, ghostPosition.y - 1, lvl) && pacPosition.y < ghostPosition.x)
			{
				ghostPosition.y -= ghostSpeed;
			}

		}
		else
		{
			if (!cells_collision(ghostPosition.x - 1, ghostPosition.y, lvl) && pacPosition.x < ghostPosition.x)
			{
				ghostPosition.x -= ghostSpeed;
			}
			else if (!cells_collision(ghostPosition.x + 1, ghostPosition.y, lvl) && pacPosition.x > ghostPosition.x)
			{
				ghostPosition.x += ghostSpeed;
			}
			else if (!cells_collision(ghostPosition.x, ghostPosition.y - 1, lvl) && pacPosition.y < ghostPosition.x)
			{
				ghostPosition.y -= ghostSpeed;
			}
			else if (!cells_collision(ghostPosition.x, ghostPosition.y + 1, lvl) && pacPosition.y > ghostPosition.x)
			{
				ghostPosition.y += ghostSpeed;
			}
		}
	}//if distance is not far the ghost stops following
	else if (distance(ghostPosition, pacPosition) <= CELL_SIZE * 2 && canFollow)
	{
		canFollow = 0;
	}
	// else the ghost picks a random position to head 2
	else
	{
		guardingBigCoin(lvl, pacPosition);
		canFollow = 0;
	}
	if (!canFollow)
	{
		if (followCoolDown > 0)
			followCoolDown--;
		else
		{
			followCoolDown = 800;
			canFollow = 1;
		}
	}
	//if a ghost takes too long to get to pac(means got stuck in walls = a countdown start running down for him either to find a way to pek or get a new position to head 2
	if (canFollow && distance(pacPosition, ghostPosition) >= CELL_SIZE * 2 && maxTimeToGetToPac > 0)
	{
		maxTimeToGetToPac--;
		if (maxTimeToGetToPac <= 0)
		{
			canFollow = 0;
			maxTimeToGetToPac = 600;
		}
	}


}

void Ghost::init(std::string ghostColor, sf::Vector2f startingPosition, sf::Vector2f headingPosition)
{
	this->ghostColor = ghostColor;
	this->startingPosition = startingPosition;
	this->headingPosition = headingPosition;

}


//Drawing ghost
void Ghost::draw(sf::RenderWindow* window, bool energizedPek)
{
	//if pac is energized we draw the ghost scared
	if (energizedPek)
	{
		ghostAnim.scaredGhost(&ghostSprite);
	}
	else
	{
		//else we animate each ghost with his own animation function
		if (ghostColor == "Red")
		{
			ghostAnim.redGhost(&ghostSprite);
		}
		else if (ghostColor == "Blue")
		{
			ghostAnim.blueGhost(&ghostSprite);
		}
		else if (ghostColor == "Pink")
		{
			ghostAnim.pinkGhost(&ghostSprite);
		}
		else
		{
			ghostAnim.orangeGhost(&ghostSprite);
		}
	}
	window->draw(ghostSprite);
}

//Reseting ghost status/posiotion/detination to 0.
void Ghost::reset()
{
	ghostPosition = startingPosition;
	ghostSprite.setPosition(ghostPosition);
	inPosition = 0;
	newDestination = 0;
	canFollow = 1;
	followCoolDown = 800;
	maxTimeToGetToPac = 600;
}


sf::FloatRect Ghost::getGlobalBounds()
{
	return ghostSprite.getGlobalBounds();
}
