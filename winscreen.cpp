#include "winscreen.h"

WinScreen::WinScreen()
{
    timer = 120;
    tie = false;
    if (!this->youWin.loadFromFile("win.png"))
        system("pause");
    if (!this->draw.loadFromFile("tie.png"))
        system("pause");
    if (!bBeep.loadFromFile("beep.wav"))
        system("pause");
       sBeep.setBuffer(bBeep);
    if(!textureWinner[0].loadFromFile("red.png"))
        system("pause");
    if(!textureWinner[1].loadFromFile("blue.png"))
        system("pause");
    if(!textureWinner[2].loadFromFile("yellow.png"))
        system("pause");
    if(!textureWinner[3].loadFromFile("green.png"))
        system("pause");
    if(!textureWinner[4].loadFromFile("draw.png"))
        system("pause");


}

WinScreen::~WinScreen()
{
    //dtor
}

bool WinScreen::isCollide(GameObject* obj)
{
    return false;

}

sf::Rect<float> WinScreen::getHitBox()
{
    sf::Rect<float> A;
    return A;
}

void WinScreen::render(sf::RenderWindow* win)
{
    int won = SceneManager::getInstance()->winner;
    sf::Sprite sprite;
    if(!tie)
        sprite.setTexture(youWin,true);
    else
        sprite.setTexture(draw,true);

    sf::Sprite winner;

    if(!tie)
    {
        winner.setTexture(textureWinner[won]);

    }
    else
    {
            winner.setTexture(textureWinner[4]);
    }
    winner.setOrigin(winner.getLocalBounds().width/2,winner.getLocalBounds().height/2);
    winner.setPosition(1280/2,720 - 720/3);
    win->draw(sprite);
    win->draw(winner);
}

void WinScreen::update()
{
    float JoyY;
    float JoyX = sf::Joystick::getAxisPosition(1, sf::Joystick::X);
    int lowestJoystick;
    for(int i = 3; i >= 0; i--)
    {
        if(sf::Joystick::isConnected(i))
        {
         JoyY = sf::Joystick::getAxisPosition(i, sf::Joystick::Y);
         lowestJoystick = i;
        }

    }

    if (winner.getSize() != 1)
        tie = true;
    else{
        tie = false;
    }
  //  sf::String hola = winner.get(0)->getName();

    if(timer < 0)
    {
        if (sf::Joystick::isButtonPressed(lowestJoystick,0) || sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
        {
            timer =40;
            SceneManager::getInstance()->setLoop(1);

        }

    }

    if(SceneManager::getInstance()->getLoopIndex() == 2)
        timer--;


}
