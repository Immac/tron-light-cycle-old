#include "Bala.h"


Bala::Bala(void)
{
	tag="Bala";
	size = sf::Vector2f(5,5);
}


Bala::~Bala(void)
{
}


void Bala::render(sf::RenderWindow * win)
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

void Bala::update()
{
	SceneManager::getInstance()->findByName("Player");
	position.x+=7;
	if(position.x>800)
		SceneManager::getInstance()->removeGameObject(this);
}

