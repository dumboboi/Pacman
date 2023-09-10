#include "Game.h"
#include "Global.h"
#include <math.h>
#include <MapManager.h>
#include <TextManager.h>
#include <Button.h>
#include <Pacman.h>
#include "Collision.h"
#include "Ghost.h"
#include "time.h"
//Creating ghosts

Ghost RedGhost("EntitiesNoBG.png", sf::IntRect(0, 64, 16, 16));
Ghost BlueGhost("EntitiesNoBG.png", sf::IntRect(0, 96, 16, 16));
Ghost PinkGhost("EntitiesNoBG.png", sf::IntRect(0, 80, 16, 16));
Ghost OrangeGhost("EntitiesNoBG.png", sf::IntRect(0, 112, 16, 16));

//Creating objects(Map,Texts,a play button,pacman)
MapManager Map;
TextsManager Text;
Button playButton("Play",   sf::Vector2f(SCREEN_WIDTH/2 - 60, 300) ,    sf::Vector2f(100,40));
Pacman Pac;


Game::Game(sf::RenderWindow& win) :
    //getting the window from the main.cpp
    window(win),
    //setting isRunning to 1
    isRunning(1),
    //setting isPlaying to 0
    isPlaying(0)
{
    //Capping the fps to 120
    window.setFramerateLimit(120);
    //Setting PacMan as an icon of the window
    icon.loadFromFile("icon.jfif");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    Score = 0;
    //get highscore stored in "highScore" text file
    HSfile.open("highScore.txt", std::ios::in);
    if (HSfile.is_open()) {
        getline(HSfile, HighScore);
        HSfile.close();
    }
    if (HighScore == "")
        HighScore = "0.0";
}

//Initialiser
void Game::Init()
{
    //Initializing Ghosts(Their colors / Starting position / The Position they must guard).
    RedGhost.init("Red", sf::Vector2f(10 * CELL_SIZE, 9 * CELL_SIZE),sf::Vector2f(15*CELL_SIZE,2*CELL_SIZE));
    BlueGhost.init("Blue", sf::Vector2f(9 * CELL_SIZE, 9 * CELL_SIZE),sf::Vector2f(5*CELL_SIZE,2*CELL_SIZE));
    PinkGhost.init("Pink", sf::Vector2f(11 * CELL_SIZE, 9 * CELL_SIZE), sf::Vector2f(2 * CELL_SIZE, 19 * CELL_SIZE));
    OrangeGhost.init("Orange", sf::Vector2f(11 * CELL_SIZE, 9 * CELL_SIZE), sf::Vector2f(18 * CELL_SIZE, 19 * CELL_SIZE));
    //Countdown timer.
    startingTimer = 600;
    //Game Status
    gameStarted = 0;
    //Updating Highscore.
    Text.updateHighScoretxt("HighScore "+HighScore);
}


//game loop
void Game::Run()
{
    //while isRunning is 1 the game loop keeps going
    while (Running())
    {

        float currentTime = clock.restart().asSeconds();
        float fps = 1.0f / (currentTime);

        while (1 == window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                Close();
                break;
            }
        }
        //game logic
        Logic();
    }
}



void Game::Logic()
{
    //clear the screen in the game loop
    Clear();
    if(isPlaying)
    {
        Updates();
        Draw();
    }
    else
    {
        Text.drawTitle(&window);
        playButton.update(CursCoords());
        if (!playButton.checkCursInButton(CursCoords()))
        {
            Text.TextAnimation(&playButton.text);
        }
        playButton.draw(window);
        Text.drawHighScore(&window);
        Text.drawCredit(&window);
        if (played)
        {
            Text.drawScore(&window,Score,0);

        }
        if (playButton.checkClickedButton(CursCoords()))
        {
            Reset();
            isPlaying = 1;
        }

    }
    window.display();
}

//clearing the window
void Game::Clear()
{
    window.clear(sf::Color::Black);
}


//Updating ingame objects(Pacmen/Ghosts/Map)
void Game::Updates()
{
    //checking if pac touched one of the 4 ghosts. If so we check if we hit a new score then we set the game status to notplaying(isPlaying = false).
    if ((ghost_collision(Pac.getGlobalBounds(), RedGhost.getGlobalBounds()) || ghost_collision(Pac.getGlobalBounds(), PinkGhost.getGlobalBounds())
       || ghost_collision(Pac.getGlobalBounds(), BlueGhost.getGlobalBounds()) || ghost_collision(Pac.getGlobalBounds(), OrangeGhost.getGlobalBounds()))&&!Pac.Energized)
    {
        isPlaying = 0;
        played = 1;
    }
    if (startingTimer > 0)
        startingTimer--;
    else if (!gameStarted)
    {
        gameStarted = 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        isPlaying = 0;
    }
    //if game has started(means the starting timer hit 0) we start updating the map/pac/ghosts.
    if (gameStarted)
    {
        Map.update();
        RedGhost.update(Map.getMap(), Pac.getPosition());
        BlueGhost.update(Map.getMap(), Pac.getPosition());
        PinkGhost.update(Map.getMap(), Pac.getPosition());
        OrangeGhost.update(Map.getMap(), Pac.getPosition());
        Pac.update(Map.getMap());
    }
    //if pac touched a coin score increases by 50.
    if (coins_collision(Pac.getPosition().x, Pac.getPosition().y, Map.getMap(),0))
        Score += 50;
    //if pac touched a big coin his big coin count inceases by 1.
    if (coins_collision(Pac.getPosition().x, Pac.getPosition().y, Map.getMap(), 1))
        Pac.bigcoinCount++;
    //if pac eat 4 big coins he  becomes Energized (means he's invincible for 2000ms)
    if (Pac.bigcoinCount == 4)
    {
        Pac.Energized = 1;
        Pac.bigcoinCount = 0;
        Score += 100;
        Pac.VALID = 1;
    }
    //if pac hit 3500 Score and ate 4 big coin he can finish with space
    if (Score >= 3499 && Pac.VALID)
    {
        Text.drawYouWonYouCanSkip(&window, Score);
    }
    if (Score >= 3500 && sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && Pac.VALID )
    {
        //checking for new highScore
        if (Score >= std::stoi(HighScore))
        {
            HSfile.open("highScore.txt", std::ios::out);
            HSfile << std::to_string(Score);
            HSfile.close();
            HighScore = std::to_string(Score);
            Text.updateHighScoretxt("HighScore : " + HighScore);
        }
        played = 1;
        isPlaying = 0;
    }
    //if pac hits maxiumum score he wins
    if (Score >= 4900)
    {
        //checking for new highScore
        if (Score >= std::stoi(HighScore))
        {
            HSfile.open("highScore.txt", std::ios::out);
            HSfile << std::to_string(Score);
            HSfile.close();
            HighScore = std::to_string(Score);
            Text.updateHighScoretxt("HighScore : " + HighScore);
        }
        played = 1;
        isPlaying = 0;
    }
}

// is least score to win 3850

//drawing objects(map/pac/score)
void Game::Draw()
{
    Map.draw(&window);
    RedGhost.draw(&window, Pac.Energized);
    BlueGhost.draw(&window, Pac.Energized);
    PinkGhost.draw(&window, Pac.Energized);
    OrangeGhost.draw(&window, Pac.Energized);
    Pac.draw(&window);
    Text.drawScore(&window,Score,0);
    if (!gameStarted)
    {
        Text.TextAnimation(&Text.tip);
        Text.drawStartingTime(&window, startingTimer);
    }
}



//getting cursor coords on the window;
sf::Vector2f Game::CursCoords()
{
    // get the current mouse position in the window
    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
    // convert it to world coordinates
    sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
    return worldPos;
}

void Game::Reset()
{
    //Reseting Map like we just run the game
    Map.reset();
    //Reseting pac to his spawning place , and just like the game started
    Pac.reset();
    //reseting ghosts also like the others
    RedGhost.reset();
    BlueGhost.reset();
    PinkGhost.reset();
    OrangeGhost.reset();
    //Score goes to 0
    Score = 0;
    //Game status go to off.
    gameStarted = 0;
    startingTimer = 600;

}

//closing game
void Game::Close()
{
    isRunning = 0;
    window.close();
}



