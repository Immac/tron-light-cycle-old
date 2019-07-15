#include "optionsmenu.h"

optionsMenu::optionsMenu()
{
    selectionIndex = 0;
    currentCooldown = 60;
    buttonCooldown = 0;
    currentFrame = 0;
    players = 1;
    music = 0;
    speed = 0;
    if (!this->menuMain.loadFromFile("options.png"))
        system("pause");
    if (!bBeep.loadFromFile("beep.wav"))
       system("pause");
       sBeep.setBuffer(bBeep);
    loadNumbers();
}

optionsMenu::~optionsMenu()
{
    //dtor
}
void optionsMenu::render(sf::RenderWindow* win)
{
     float Y = 217 + selectionIndex * 125;
     float X = 285 + selectionIndex *15;
    sf::Vector2<float> selection1(X,Y);
    sf::Sprite sprite;
    sprite.setTexture(menuMain,true);

    sf::CircleShape cursorA(60, 3); // Coso giratorio
    cursorA.setPosition(X,Y);
    sf::Rect<float> LocalBoundingBox = cursorA.getLocalBounds();
    cursorA.setOrigin(LocalBoundingBox.height/2,LocalBoundingBox.width/2 );
    cursorA.setRotation((currentFrame)%90*4);
    cursorA.setFillColor(sf::Color(0xFF,0x00,0x00));

    sf::CircleShape cursorB(60, 3);// Coso giratorio
    cursorB.setPosition(X,Y);
    LocalBoundingBox = cursorB.getLocalBounds();
    cursorB.setOrigin(LocalBoundingBox.height/2,LocalBoundingBox.width/2 );
    cursorB.setRotation(((-(currentFrame))%90*4%360+360)%360);
    cursorB.setFillColor(sf::Color(0x11,0x11,0xFF));

    sf::CircleShape cursorC(60, 3);// Coso giratorio
    cursorC.setPosition(X,Y);
    LocalBoundingBox = cursorC.getLocalBounds();
    cursorC.setOrigin(LocalBoundingBox.height/2,LocalBoundingBox.width/2 );
    cursorC.setRotation((((currentFrame))%45*8%360+360)%360);
    cursorC.setFillColor(sf::Color(0x00,0xFF,0x00));

    sf::Sprite optionPlayer;    //numero de jugadores
    optionPlayer.setPosition(285+450,217-45);
    optionPlayer.setTexture(numbers[players],true);

    sf::Sprite optionSpeed; // velocidad (indice)
    optionSpeed.setPosition(285+450,217-45+125);
    optionSpeed.setTexture(numbers[speed],true);

     sf::Sprite optionMusic; // musica (indice)
    optionMusic.setPosition(285+450,217-45+250);
    optionMusic.setTexture(numbers[music],true);



    win->draw(sprite);
    win->draw(cursorA);
    win->draw(cursorB);
    win->draw((cursorC));
    win->draw(optionPlayer);
    win->draw(optionSpeed);
    win->draw(optionMusic);
}

void optionsMenu::update()
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

    if(JoyY < -25 || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            changeSelection(true);
        }
    if(JoyY > 25 || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            changeSelection(false);
        }

    if ((sf::Joystick::isButtonPressed(lowestJoystick,0) || sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
        && buttonCooldown >= buttonCD)
    {
        if(selectionIndex == 3)
            {
                //EXIT
                SceneManager::getInstance()->setup = true;
                selectionIndex = 0;
                SceneManager::getInstance()->setLoop(1);
            }
    }

     if(JoyX < -25)
        {
            changeOption(selectionIndex,true);
        }
    if(JoyX > 25)
        {
            changeOption(selectionIndex,false);
        }


if(currentCooldown < cooldown)
    currentCooldown++;

if(buttonCooldown < buttonCD)
    buttonCooldown++;

currentFrame++;
if(currentFrame > 360)
    currentFrame = 0;
}

bool optionsMenu::isCollide(GameObject* obj)
{
    return false;
}

sf::Rect<float> optionsMenu::getHitBox()
{
    sf::Rect<float> temp;
    return temp;
}

void optionsMenu::changeSelection(bool up)
{
    if(cooldown <= currentCooldown)
    {
        if(!up)
        {
            selectionIndex++;
            if(selectionIndex > 3)
                selectionIndex = 0;
        }
        else
        {
            selectionIndex--;
            if(selectionIndex < 0)
                selectionIndex = 3;
        }
        sBeep.play();
        currentCooldown = 0;
    }
}

void optionsMenu::changeOption(int index, bool left)
{
    if(cooldown <= currentCooldown)
    {
        if(left)
        {
            switch (index)
            {
            case 0:
                players--;
                if (players < 1)
                {
                    players = 3;
                }
                break;
            case 2:
                music--;
                if (music < 0)
                {
                    music = 3;
                }
                SceneManager::getInstance()->playSong(music);
                break;
            case 1:
                speed--;
                if (speed < 0)
                {
                    speed = 3;
                }
                break;
            }
        }
        else
        {
             switch (index)
            {
            case 0:
                players++;
                if (players > 3)
                {
                    players = 1;
                }
                break;
            case 2:
                music++;
                if (music > 3)
                {
                    music = 0;
                }
                SceneManager::getInstance()->playSong(music);
                break;
            case 1:
                speed++;
                if (speed > 3)
                {
                    speed = 0;
                }
                break;
        }

        }
        SceneManager::getInstance()->numberOfPlayers = players;
        SceneManager::getInstance()->setSpeed(speed);
        sBeep.play();
        currentCooldown = 0;
    }
}

void optionsMenu::loadNumbers()
{
    if (!this->numbers[0].loadFromFile("1.png"))
        system("pause");
    if (!this->numbers[1].loadFromFile("2.png"))
        system("pause");
    if (!this->numbers[2].loadFromFile("3.png"))
        system("pause");
    if (!this->numbers[3].loadFromFile("4.png"))
        system("pause");
}
