#include "moto.h"
enum {
        F_UP,F_DOWN,F_LEFT,F_RIGHT
        };

Moto::Moto(sf::Vector2<float> intialPosition){
    this->setPosition(intialPosition);
    this->skipAFrame = true;
    this->velocity = 4;
    this->size = sf::Vector2f(10,25);
    this-> name = "Moto";
    this->facing = F_UP;
    this->setPlayer(1);
    this->sensitivity = 25;
    this->setTag("player");
    this->playerColor = sf::Color::Blue;
    this->isInvulnerable = false;
    this->hasInvisWalls = false;
    this->isFaster = false;
    this->hasInvisibilityPower = false;
    this->hasInvisibilityPower = false;
    this->hasSpeedPower = false;
    center = sf::Vector2f(this->getSize().x/2,this->getSize().y/2);
    timer[SPEED] = 0;
    timer[INVIS] = 0;
    timer[INVUL] = 0;
    timer[FRAMES] = 0;
    srand(time(0));
    srand(rand());
  //  createWall();
    //ctor
}

Moto::~Moto()
{
    //dtor
}

void Moto::update()
{


    bool isHorizontal = (facing != F_DOWN && facing != F_UP);
    bool isVertical = (facing != F_LEFT && facing != F_RIGHT);
    float JoyX = sf::Joystick::getAxisPosition(playerNumber, sf::Joystick::X);
    float JoyY = sf::Joystick::getAxisPosition(playerNumber, sf::Joystick::Y);

    /*
    if (sf::Joystick::isButtonPressed(PlayerNumber, 1))
    facing = F_UP;
    if (sf::Joystick::isButtonPressed(PlayerNumber, 2))
    facing = F_RIGHT;*/
    if(!skipAFrame)
    {
        if ( abs(JoyX)>25 && abs(JoyY) > 25)
            isHorizontal = isVertical = false;
        if(JoyY < -25
           && isHorizontal)
            {
                facing = F_UP;createWall();
            }
        if(JoyY > 25
            && isHorizontal)
            {
                facing = F_DOWN;createWall();
            }
        if(JoyX > 25
            && isVertical)
            {
                facing = F_RIGHT;createWall();
            }
        if(JoyX < -25
            && isVertical)
            {
                facing = F_LEFT;createWall();
            }

        if (!sf::Joystick::isConnected(playerNumber))
        {
            keyboardInputs(isHorizontal,isVertical);
        }
    }
    skipAFrame = false;

        if(currentWall !=0)
        {
            if(facing != F_DOWN)
                currentWall->setSize(this->getPosition());
            else
                currentWall->setSize(sf::Vector2<float>(getPosition().x,getPosition().y));
        }

        float speed = velocity;

        if(isFaster)
            speed += 4;

        if (this->facing == F_UP){
            this->position.y -= speed;

        }
        if (this->facing == F_DOWN){
            this->position.y += speed;

        }
        if (this->facing == F_RIGHT){
            this->position.x += speed;

        }
        if (this->facing == F_LEFT){
            this->position.x -= speed;

        }

        timer[FRAMES]++;

        if(timer[FRAMES]%120 == 0)
        {
            if(rand()%2 == 0)
                SceneManager::getInstance()->createPowerup();
        }
        reset();

        if(position.x > 1280 || position.x < 0
           || position.y > 720 || position.y < 0)
            tag = "dead";


}

void Moto::createWall()
{
    currentWall = new Wall(this->getPosition());
    if(facing != F_DOWN)
        currentWall->wallEnd = this->getPosition();
    else
        currentWall->wallEnd = sf::Vector2<float>(this->getPosition().x,this->getPosition().y - this->getSize().y/2);

        if(hasInvisWalls)
            currentWall->wallColor = sf::Color::Transparent;
        else
            currentWall->wallColor = playerColor;

        currentWall->setHorizontal((facing == F_LEFT || facing == F_RIGHT));
    SceneManager::getInstance()->addGameObject(currentWall);
}

void Moto::render(sf::RenderWindow * win){

sf::RectangleShape shape;
    shape.setOrigin(this->getSize().x/2,this->getSize().y/2);
    shape.setSize(size);
    shape.setOutlineThickness(2);
	shape.setOutlineColor(sf::Color::White);
    shape.setFillColor(playerColor);
	shape.setPosition(position);




    sf::RectangleShape hitBox;

	if (this->facing == F_UP)
    {
        shape.setRotation(180);
        hitBox.setPosition(sf::Vector2f(position.x - getSize().x/2 ,position.y - getSize().y/2));
        hitBox.setSize(sf::Vector2f(10,2));
    }
    if (this->facing == F_DOWN)
    {
        shape.setRotation(0);
        hitBox.setPosition(sf::Vector2f(position.x - getSize().x/2 ,position.y + getSize().y/2));
        hitBox.setSize(sf::Vector2f(10,2));
    }
    if (this->facing == F_RIGHT){
        shape.setRotation(90);
        hitBox.setPosition(sf::Vector2f(position.x + getSize().x ,position.y - getSize().x/2));
        hitBox.setSize(sf::Vector2f(2,10));
    }
    if (this->facing == F_LEFT){
        shape.setRotation(270);
        hitBox.setPosition(sf::Vector2f(position.x - getSize().x ,position.y - getSize().x/2));
        hitBox.setSize(sf::Vector2f(2,10));
    }


    win->draw(shape);
  //  win->draw(hitBox);


}

void Moto::setPlayer(int index)
{
    if (index >= 0 && index < 8)
        this->playerNumber = index;
}

sf::Rect<float> Moto::getHitBox()
{

   sf::Rect<float> hitBox;

	if (this->facing == F_UP)
    {
        hitBox.left = position.x - getSize().x/2;
        hitBox.top = position.y - getSize().y/2;
        hitBox.width = 10;
        hitBox.height = 2;
    }
    if (this->facing == F_DOWN)
    {
        hitBox.left = position.x - getSize().x/2;
        hitBox.top = position.y + getSize().y/2;
        hitBox.width = 10;
        hitBox.height = 2;
    }
    if (this->facing == F_RIGHT)
    {
        hitBox.left = position.x + getSize().x ;
        hitBox.top = position.y - getSize().x/2;
        hitBox.width = 2;
        hitBox.height = 10;
    }
    if (this->facing == F_LEFT){
        hitBox.left = position.x - getSize().x ;
        hitBox.top = position.y - getSize().x/2;
        hitBox.width = 2;
        hitBox.height = 10;
    }
    if (this->isInvulnerable)
    {
        hitBox.left = playerNumber*280 ;
        hitBox.top = 800;
        hitBox.width = 1;
        hitBox.height = 1;
    }

    return hitBox;
}

void Moto::keyboardInputs(bool isHorizontal,bool isVertical)
{
   switch (playerNumber)
        {
            case 0:
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
                   && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
                   && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
                   && isHorizontal)
                    {
                        facing = F_UP;createWall();
                    }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
                    && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
                    && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
                    && isHorizontal)
                    {
                        facing = F_DOWN;createWall();
                    }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
                   && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
                   && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
                    && isVertical)
                    {
                        facing = F_RIGHT;createWall();
                    }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
                   && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
                   && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
                    && isVertical)
                    {
                        facing = F_LEFT;createWall();
                    }
                    break;
            case 1:
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)
                   && !sf::Keyboard::isKeyPressed(sf::Keyboard::D)
                   && !sf::Keyboard::isKeyPressed(sf::Keyboard::A)
                   && isHorizontal)
                    {
                        facing = F_UP;createWall();
                    }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)
                    && !sf::Keyboard::isKeyPressed(sf::Keyboard::D)
                    && !sf::Keyboard::isKeyPressed(sf::Keyboard::A)
                    && isHorizontal)
                    {
                        facing = F_DOWN;createWall();
                    }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)
                   && !sf::Keyboard::isKeyPressed(sf::Keyboard::W)
                   && !sf::Keyboard::isKeyPressed(sf::Keyboard::S)
                    && isVertical)
                    {
                        facing = F_RIGHT;createWall();
                    }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)
                   && !sf::Keyboard::isKeyPressed(sf::Keyboard::W)
                   && !sf::Keyboard::isKeyPressed(sf::Keyboard::S)
                    && isVertical)
                    {
                        facing = F_LEFT;createWall();
                    }
                break;
            case 2:
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::I)
                   && !sf::Keyboard::isKeyPressed(sf::Keyboard::L)
                   && !sf::Keyboard::isKeyPressed(sf::Keyboard::J)
                   && isHorizontal)
                    {
                        facing = F_UP;createWall();
                    }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::K)
                    && !sf::Keyboard::isKeyPressed(sf::Keyboard::L)
                    && !sf::Keyboard::isKeyPressed(sf::Keyboard::J)
                    && isHorizontal)
                    {
                        facing = F_DOWN;createWall();
                    }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::L)
                   && !sf::Keyboard::isKeyPressed(sf::Keyboard::I)
                   && !sf::Keyboard::isKeyPressed(sf::Keyboard::K)
                    && isVertical)
                    {
                        facing = F_RIGHT;createWall();
                    }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::J)
                   && !sf::Keyboard::isKeyPressed(sf::Keyboard::I)
                   && !sf::Keyboard::isKeyPressed(sf::Keyboard::K)
                    && isVertical)
                    {
                        facing = F_LEFT;createWall();
                    }
                break;
            case 3:
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::T)
                   && !sf::Keyboard::isKeyPressed(sf::Keyboard::H)
                   && !sf::Keyboard::isKeyPressed(sf::Keyboard::F)
                   && isHorizontal)
                    {
                        facing = F_UP;createWall();
                    }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::G)
                    && !sf::Keyboard::isKeyPressed(sf::Keyboard::H)
                    && !sf::Keyboard::isKeyPressed(sf::Keyboard::F)
                    && isHorizontal)
                    {
                        facing = F_DOWN;createWall();
                    }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::H)
                   && !sf::Keyboard::isKeyPressed(sf::Keyboard::T)
                   && !sf::Keyboard::isKeyPressed(sf::Keyboard::G)
                    && isVertical)
                    {
                        facing = F_RIGHT;createWall();
                    }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::F)
                   && !sf::Keyboard::isKeyPressed(sf::Keyboard::T)
                   && !sf::Keyboard::isKeyPressed(sf::Keyboard::G)
                    && isVertical)
                    {
                        facing = F_LEFT;createWall();
                    }
                break;
        }


}


void Moto::setFacing(int faceIndex)
{
    this->facing = faceIndex;
}

float Moto::getVelocity()
{
    return velocity;
}

void Moto::setVelocity(float value)
{
    velocity = value;
}

void Moto::speedUp()
{
    if (timer[SPEED] == 0)
    {
        isFaster = true;
        hasSpeedPower = false;
        timer[SPEED] = 60;
    }
}

void Moto::invulnerability()
{
    if (timer[INVUL] == 0)
    {
        isInvulnerable = true;
        hasInvulnerabilityPower = false;
        timer[INVUL] = 60;
    }

}

void Moto::invisWalls()
{
    if(timer[INVIS] == 0)
    {
        hasInvisWalls = true;
        hasInvisibilityPower = false;
        timer[INVIS] = 60;
    }

}

void Moto::reset()
{
    if(timer[SPEED] > 0)
    {
       timer[SPEED]--;
    }

    if(timer[INVUL] > 0)
       timer[INVUL]--;
    if(timer[INVIS] > 0)
        timer[INVIS]--;

    if(timer[SPEED] == 0)
    {
        isFaster = false;
    }
    if(timer[INVUL] == 0)
    {
        isInvulnerable = false;
    }
    if(timer[INVIS] == 0)
    {
        hasInvisWalls = false;
    }

}

void Moto::activatePower(int index)
{
    if(index == INVIS)
        invisWalls();
    if(index == INVUL)
        invulnerability();
    if(index == SPEED)
        speedUp();
}
