#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

bool cells_collision(float i_x, float i_y, std::vector<std::vector<char>>* Map);
bool coins_collision(float i_x, float i_y, std::vector<std::vector<char>>* Map, bool checkbigCoin);
bool ghost_collision(sf::FloatRect pacBounds, sf::FloatRect ghostBounds);
double distance(sf::Vector2f  a, sf::Vector2f b);



