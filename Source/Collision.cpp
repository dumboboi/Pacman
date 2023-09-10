#include "Collision.h"
#include "Global.h"
#include "vector"
#include <cmath>
bool cells_collision(float i_x, float i_y, std::vector<std::vector<char>>* Map)
{
	//this function works this way :
	//checks the cells pac is intersecting with (top left/top right/ bottom left/bottom right) using cmath libary.
	//i store these cells in a temporary vector then checking if one of them cells in the map represents a well(blue cell).
	//if so the functions returns 1 means pac collided with a wall
	std::vector<char> temp;
	temp.push_back((*Map)[floor(i_y / static_cast<float>(CELL_SIZE))][floor(i_x / static_cast<float>(CELL_SIZE))]); //top left
	temp.push_back((*Map)[floor(i_y / static_cast<float>(CELL_SIZE))][ceil(i_x / static_cast<float>(CELL_SIZE))]); //top right
	temp.push_back((*Map)[ceil(i_y / static_cast<float>(CELL_SIZE))][floor(i_x / static_cast<float>(CELL_SIZE))]); //bottom left
	temp.push_back((*Map)[ceil(i_y / static_cast<float>(CELL_SIZE))][ceil(i_x / static_cast<float>(CELL_SIZE))]); //bottom right

	for (auto& c : temp)
	{

			if (c == '#')
				return	1;
	}
	return 0;
}
bool coins_collision(float i_x, float i_y, std::vector<std::vector<char>>* Map,bool checkbigCoin)
{
	bool output = 0;

	//Getting the exact position.
	float cell_x = i_x / static_cast<float>(CELL_SIZE);
	float cell_y = i_y / static_cast<float>(CELL_SIZE);

	for (unsigned short a = 0; a < 4; a++)
	{
		float x = 0;
		float y = 0;

		switch (a)
		{
		case 0: //Top left cell
		{
			x = static_cast<short>(floor(cell_x));
			y = static_cast<short>(floor(cell_y));

			break;
		}
		case 1: //Top right cell
		{
			x = static_cast<short>(ceil(cell_x));
			y = static_cast<short>(floor(cell_y));

			break;
		}
		case 2: //Bottom left cell
		{
			x = static_cast<short>(floor(cell_x));
			y = static_cast<short>(ceil(cell_y));

			break;
		}
		case 3: //Bottom right cell
		{
			x = static_cast<short>(ceil(cell_x));
			y = static_cast<short>(ceil(cell_y));
		}
		}

		//Making sure that the position is inside the map.
		if (0 <= x && 0 <= y && y <= (Map->size() * CELL_SIZE) && x < (CELL_SIZE *22))
		{
			//checking if cells are collidable.
			if (checkbigCoin)
			{
				if ((*Map)[y][x] == '*')
				{
					(*Map)[y][x] = ' ';
					output = 1;
				}
			}
			else if ((*Map)[y][x] == '.')
			{
				(*Map)[y][x] = ' ';
				output = 1;
			}

		}
	}
	return output;

}

//checks if pac touched a ghost(pre-defined sfml function).
bool ghost_collision(sf::FloatRect pacBounds, sf::FloatRect ghostBounds)
{
	return(pacBounds.intersects(ghostBounds));
}

//calculating distance between 2 points
double distance(sf::Vector2f  a, sf::Vector2f b)
{
	double dx, dy;
	dx = a.x - b.x;
	dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}