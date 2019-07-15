#include "wall.h"

Wall::Wall()
{
    setTag("wall");
    wallColor = sf::Color::White;
    //ctor
}

Wall::Wall(sf::Vector2f position)
{

    this->setPosition(position);
    this->setName("PlayerWall");
    this->setTag("wall");
    this->setSize(sf::Vector2f(10,10));


}
Wall::~Wall()
{
    //dtor
}


void Wall::render(sf::RenderWindow * win){

    sf::VertexArray shape(sf::Quads,4);
    if(isHorizontal)
    {
        shape[0].position = sf::Vector2f(position.x,position.y-5);
        shape[1].position = sf::Vector2f(position.x ,position.y+5);
        shape[2].position = sf::Vector2f(size.x,size.y+5);
        shape[3].position = sf::Vector2f(size.x,size.y-5);
    }
    else
    {
        shape[0].position = sf::Vector2f(position.x +5,position.y);
        shape[1].position = sf::Vector2f(position.x -5,position.y);
        shape[2].position = sf::Vector2f(size.x-5,size.y);
        shape[3].position = sf::Vector2f(size.x+5,size.y);

    }

    for (int i = 0; i <4; i++)
    {
        shape[i].color = sf::Color(wallColor.r,wallColor.g,wallColor.b);
    }
    float realSizeX,realSizeY;

    if (isHorizontal)
        realSizeX = abs(position.x - size.x);
    else
        realSizeX = 10;

    if(!isHorizontal)
        realSizeY = abs(position.y - size.y);
    else
        realSizeY = 10;

    sf::Vector2f hitPos;

    if(position.x > size.x)
        hitPos.x = size.x;
    else
        hitPos.x = position.x;
    if(position.y > size.y)
        hitPos.y = size.y;
    else
        hitPos.y = position.y;

    if(isHorizontal)
        hitPos.y -= realSizeY/2;
    else
        hitPos.x -= realSizeX/2;


//    sf::RectangleShape hitbox;
//    hitbox.setPosition(hitPos);
//    hitbox.setSize(sf::Vector2f(realSizeX,realSizeY));







    /*
        shape.setOutlineThickness(2);
        shape.setOutlineColor(sf::Color::Blue);
        shape.setFillColor(sf::Color(100, 50, 50));
        shape.setPosition(position);
    */
    win->draw(shape);
  //  win->draw(hitbox);


}

void Wall::update()
{
    LinkedList<GameObject *> toCheck = SceneManager::getInstance()->findByTag("player");

    for (int i = 0; i < toCheck.getSize();i++)
    {
        if(isCollide(toCheck.get(i)))
            {
                //Explosiond
                SceneManager::getInstance()->removeGameObject(toCheck.get(i));
            }
    }


}

bool Wall::setHorizontal(bool value)
{
    this->isHorizontal = value;
    return value;
}

bool Wall::isCollide(GameObject * obj)
{
    this->getHitBox();
    return obj->getHitBox().intersects(this->getHitBox());
}

sf::Rect<float> Wall::getHitBox()
{
 float realSizeX,realSizeY;

    if (isHorizontal)
        realSizeX = abs(position.x - size.x);
    else
        realSizeX = 10;

    if(!isHorizontal)
        realSizeY = abs(position.y - size.y);
    else
        realSizeY = 10;

    sf::Vector2f hitPos;

    if(position.x > size.x)
        hitPos.x = size.x;
    else
        hitPos.x = position.x;
    if(position.y > size.y)
        hitPos.y = size.y;
    else
        hitPos.y = position.y;

    if(isHorizontal)
        hitPos.y -= realSizeY/2;
    else
        hitPos.x -= realSizeX/2;


    sf::Rect<float> hitbox;
    hitbox.left = hitPos.x;
    hitbox.top = hitPos.y;
    hitbox.width = realSizeX;
    hitbox.height = realSizeY;


return hitbox;

}
