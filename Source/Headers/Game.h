#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "fstream"
class Game
{
public:
    Game(sf::RenderWindow& win);

    //Functions
public:
    //Initialize things
    void Init();
    //Game loop
    void Run();
private:
    //Game logic
    void Logic();
    //Clear window
    void Clear();
    //Update objects(Map/Pac/Ghosts)
    void Updates();
    //Draw objects
    void Draw();
    //Reset the game
    void Reset();
    //Close the game
    void Close();
    bool Running() { return isRunning; }
    sf::Vector2f CursCoords();


    //variables
private:
    bool isRunning;
    bool isPlaying;
    sf::RenderWindow& window;
    sf::Event event;
    sf::Clock clock;
    sf::Image icon;
    unsigned short  Score;
    float startingTimer;
    bool gameStarted;
    bool played;
    std::fstream HSfile;
    std::string HighScore;



};

