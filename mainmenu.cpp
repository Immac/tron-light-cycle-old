#include "mainmenu.h"

MainMenu::MainMenu()
{
    selectionIndex = 0;
    currentCooldown = 60;
    currentFrame = 0;
    buttonPressCoolDown = 0;
    if (!this->menuMain.loadFromFile("main.png"))
        system("pause");
    if (!bBeep.loadFromFile("beep.wav"))
       system("pause");
       sBeep.setBuffer(bBeep);
}

MainMenu::~MainMenu()
{
    //dtor
}

void MainMenu::update()
{   float JoyY;
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

    if(JoyY < -25)
        {
            changeSelection(true);
        }
    if(JoyY > 25)
        {
            changeSelection(false);
        }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            changeSelection(true);
        }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            changeSelection(false);
        }

    if ((sf::Joystick::isButtonPressed(lowestJoystick,0) || sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
         && buttonPressCoolDown >= buttonCooldown )
    {
        if(selectionIndex == 0)
            SceneManager::getInstance()->setLoop(0);
        if(selectionIndex == 1)
            SceneManager::getInstance()->setLoop(4);
        if(selectionIndex == 2)
            SceneManager::getInstance()->setLoop(3);

            buttonPressCoolDown = 0;
    }


if(currentCooldown < cooldown)
    currentCooldown++;
if(buttonPressCoolDown < buttonCooldown)
    buttonPressCoolDown++;

currentFrame++;
if(currentFrame > 360)
    currentFrame = 0;
}

void MainMenu::render(sf::RenderWindow* win)
{
    float Y = 200 + selectionIndex * 140;
    sf::Vector2<float> selection1(780,Y);
    sf::Sprite sprite;
    sprite.setTexture(menuMain,true);

    sf::CircleShape cursorA(60, 3);
    cursorA.setPosition(780,Y);
    sf::Rect<float> LocalBoundingBox = cursorA.getLocalBounds();
    cursorA.setOrigin(LocalBoundingBox.height/2,LocalBoundingBox.width/2 );
    cursorA.setRotation((currentFrame)%90*4);
    cursorA.setFillColor(sf::Color(0xFF,0x00,0x00));

    sf::CircleShape cursorB(60, 3);
    cursorB.setPosition(780,Y);
    LocalBoundingBox = cursorB.getLocalBounds();
    cursorB.setOrigin(LocalBoundingBox.height/2,LocalBoundingBox.width/2 );
    cursorB.setRotation(((-(currentFrame))%90*4%360+360)%360);
    cursorB.setFillColor(sf::Color(0x00,0x00,0xFF));

    sf::CircleShape cursorC(60, 3);
    cursorC.setPosition(780,Y);
    LocalBoundingBox = cursorC.getLocalBounds();
    cursorC.setOrigin(LocalBoundingBox.height/2,LocalBoundingBox.width/2 );
    cursorC.setRotation((((currentFrame))%45*8%360+360)%360);
    cursorC.setFillColor(sf::Color(0xFF,0xFF,0x00));




    win->draw(sprite);
    win->draw(cursorA);
    win->draw(cursorB);
    win->draw((cursorC));


}

bool MainMenu::isCollide(GameObject* obj)
{
    return false;
}

sf::Rect<float> MainMenu::getHitBox()
{
    sf::Rect<float> hello;
    return hello;
}

void MainMenu::changeSelection(bool up)
{
    if(cooldown <= currentCooldown)
    {
        if(!up)
        {
            selectionIndex++;
            if(selectionIndex > 2)
                selectionIndex = 0;
        }
        else
        {
            selectionIndex--;
            if(selectionIndex < 0)
                selectionIndex = 2;
        }
        sBeep.play();
        currentCooldown = 0;
    }
}
