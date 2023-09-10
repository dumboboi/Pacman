#include "MapManager.h"
#include "Global.h"
#include "Animation.h"

Animation mapAnimator;

MapManager::MapManager():
MAP_RESIZE(64),
MAP_UPDATED(0)
{
	//loading textures in sprites
	cellTexture.loadFromFile("bluecell.png");
	cellSprite.setTexture(cellTexture);
	coinTexture.loadFromFile("coin.png");
	coinSprite.setTexture(coinTexture);
	coinSprite.setTextureRect(sf::IntRect(0,0,32,32));
	BIGcoinTexture.loadFromFile("BigCoin.png");
	BIGcoinSprite.setTexture(BIGcoinTexture);
	BIGcoinSprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
	BIGcoinSprite.setScale(2.f, 2.f);
	reset();
}


void MapManager::draw(sf::RenderWindow* window)
{
	window->draw(bgSprite);
	for (unsigned short row = 0; row < 21; row++)
	{
		for (unsigned short coll = 0; coll < 21; coll++)
		{
			char cell = tempMap[row][coll];
			cellSprite.setPosition((coll * CELL_SIZE), (row * CELL_SIZE));
			coinSprite.setPosition((coll * CELL_SIZE), (row * CELL_SIZE));
			BIGcoinSprite.setPosition((coll * CELL_SIZE), (row * CELL_SIZE));
			switch (cell)
			{
				case ' ': // space
					break;
				case '#': // wall
				{
					window->draw(cellSprite);
					break;
				}
				case '.': // coin
				{
					mapAnimator.coinAnim(&coinSprite);
					window->draw(coinSprite);
					break;
				}
				case '*': // big coin
				{
					window->draw(BIGcoinSprite);
					break;
				}
				default:
					break;
			}


		}
	}
}


//remove two walls for the ghosts to get out after the game starts.
void MapManager::update()
{
	if (!MAP_UPDATED)
	{
		tempMap[9][8] = ' ';
		tempMap[9][12] = ' ';
		MAP_UPDATED = 0;
	}

}

//Reseting map
void MapManager::reset()
{
	tempMap.clear();
	tempMap = Level;
}