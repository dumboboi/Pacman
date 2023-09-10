#include "TextManager.h"
#include "Global.h"

//this class is just to make things more clean so the game class wont be messy.
TextsManager::TextsManager()
{
    //loading fonts, seting size/style/position/string for all texts that will be show on the window.
    //Loading fonts
    font.loadFromFile("Joystix.ttf");
    //Setting this font to Score text
    Score.setFont(font);
    //Setting Score size
    Score.setCharacterSize(36);
    //Setting space between letters in score
    Score.setLetterSpacing(2.5);
    //Setting the string for the score
    Score.setString("Score");
    //Highscore takes Score so we dont have to re-write some things
    HighScore = Score;
    //Setting The position of highscore in the screen
    HighScore.setPosition(SCREEN_WIDTH/2 - 130, 600);
    //Setting Size of highscore
    HighScore.setCharacterSize(26);
    //all the rest is the same but for other texts..
    Credit = HighScore;
    Credit.setCharacterSize(16);
    Credit.setPosition(SCREEN_WIDTH/2 -50, 750);
    Credit.setString("Dumboo");
    Score.setPosition(SCREEN_WIDTH-200, 20);
    titleTexture.loadFromFile("pacmanTitle.png");
    titleSprite.setTexture(titleTexture);
    titleSprite.setPosition(SCREEN_WIDTH / 2 - 190,100);
    ScoreNUM = Score;
    ScoreNUM.setCharacterSize(26);
    ScoreNUM.setPosition(SCREEN_WIDTH - 180, 75);
    Starting = ScoreNUM;
    Starting.setCharacterSize(16);
    Starting.setPosition(SCREEN_WIDTH - 240, 360);
    Scoretxts.push_back(Score);
    Scoretxts.push_back(ScoreNUM);
    YouWonYouCanSkipText = Score;
    YouWonYouCanSkipText.setPosition(SCREEN_WIDTH - 250, 500);
    YouWonYouCanSkipText.setCharacterSize(16);
    tip = YouWonYouCanSkipText;
    tip.setPosition(SCREEN_WIDTH - 250, SCREEN_HEIGHT - 200);
    tip.setString("Highscore only\nsaves when \nyou pass\nthe Level.");
}


//We using arrows in the next functions because we passed pointers and not references.
//drawing window title which is a sprite
void TextsManager::drawTitle(sf::RenderWindow* window)
{
    window->draw(titleSprite);
}
//This functions draws Score to the screen - RECURSIVE
void TextsManager::drawScore(sf::RenderWindow* window,unsigned short Score,int t)
{
    Scoretxts[1].setString(std::to_string(Score));
    if(t<Scoretxts.size())
    {
        window->draw(Scoretxts[t]);
        drawScore(window, Score, t + 1);
    }
}
//drawing highscore - POINTER
void TextsManager::drawHighScore(sf::RenderWindow* window)
{
    window->draw(HighScore);
}
//drawing Credits. - POINTER
void TextsManager::drawCredit(sf::RenderWindow* window)
{
    window->draw(Credit);
}

//This fuction show a starting countdown - POINTER
void TextsManager::drawStartingTime(sf::RenderWindow* window,const float startingTimer)
{
    //settings string for Starting Text this way : "Start in " and we devide the starting timer on 120ms so it looks like seconds on screen.
    Starting.setString("Starting in "+std::to_string(startingTimer/120));
    window->draw(Starting);
    window->draw(tip);
}

//Update HighScore
void TextsManager::updateHighScoretxt(std::string str)
{
    //setting string for highScore
    HighScore.setString(str);
}

//Drawing " You won you can Skip if you want" - POINTER
void TextsManager::drawYouWonYouCanSkip(sf::RenderWindow* window, const short Score)
{
    YouWonYouCanSkipText.setString("YOU WON WITH " + std::to_string(Score) + "\nYOU CAN SKIP \nBY HITTING SPACE\nOR KEEP PLAYING \nFOR BEST SCORE");
    window->draw(YouWonYouCanSkipText);
}

//Animate a text(fade in/out) - POINTER
void TextsManager::TextAnimation(sf::Text* text)
{
    if (Loop > 0)
    {
        if (i < 255)
        {
            i++;
        }
        else if (i == 255)
            Loop *= -1;
    }
    else
    {
        if (i > 0)
        {
            i--;
        }
        else if (i == 0)
            Loop *= -1;
    }
    text->setFillColor(sf::Color(i, i, i));
}
