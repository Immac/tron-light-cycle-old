#include "powerup.h"

PowerUp::PowerUp()
{
    texture[0].loadFromFile("fast.png");
    texture[1].loadFromFile("invi.png");
    texture[2].loadFromFile("invu.png");
    setPosition(sf::Vector2<float>(rand()%1200+20,rand()%660 + 20));
    srand(time(0));
    srand(rand());
    powerType = rand()%3;
}

PowerUp::~PowerUp()
{
    //dtor
}
sf::Rect<float> PowerUp::getHitBox()
{
     sf::Sprite power;
    power.setTexture(texture[powerType]);
    power.setOrigin(power.getLocalBounds().width/2,power.getLocalBounds().height/2);
    power.setPosition(position);
    return power.getGlobalBounds();

}

void PowerUp::render(sf::RenderWindow* win)
{
    sf::Sprite power;
    power.setTexture(texture[powerType]);
    power.setOrigin(power.getLocalBounds().width/2,power.getLocalBounds().height/2);
    power.setPosition(position);

    win->draw(power);

}

void PowerUp::update()
{
    LinkedList<GameObject *> toCheck = SceneManager::getInstance()->findByTag("player");

    for (int i = 0; i < toCheck.getSize();i++)
    {
        if(isCollide(toCheck.get(i)))
            {
             GameObject * hola = toCheck.get(i);
              Moto * dios = dynamic_cast<Moto*>(hola);
              dios->activatePower(powerType);
              this->tag = "dead";
            }
    }

}

bool PowerUp::isCollide(GameObject* obj)
{
            this->getHitBox();
    return obj->getHitBox().intersects(this->getHitBox());

}
