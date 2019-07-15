#include "Tanque.h"


Tanque::Tanque(void)
{
	 name="Player";
	 size = sf::Vector2f(20,20);
}


Tanque::~Tanque(void)
{
}
void Tanque::render(sf::RenderWindow * win)
{
	sf::RectangleShape leftPaddle;
    leftPaddle.setSize(size);
    leftPaddle.setOutlineThickness(3);
	leftPaddle.setOutlineColor(sf::Color::Blue);
    leftPaddle.setFillColor(sf::Color(100, 100, 200));
	leftPaddle.setPosition(position);
	win->draw(leftPaddle);

	//leftPaddle.setOrigin(paddleSize / 2.f);
}

void Tanque::update()
{   if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    position.x -=4;
	if(InputManager::getInstance()->isKeyPressed(sf::Keyboard::Right))
		position.x+=4;
	if(InputManager::getInstance()->isKeyPressed(sf::Keyboard::Up))
		position.y-=4;
	if(InputManager::getInstance()->isKeyPressed(sf::Keyboard::Down))
		position.y+=4;

	if(InputManager::getInstance()->isKeyPressed(sf::Keyboard::Space))
	{
		//Bala * b = new Bala();
		//b->setPosition(this->position);
		//SceneManager::getInstance()->addGameObject(b);

	}

}
