#include "GameObject.h"


GameObject::GameObject(void)
{
	name = "Name"+objectCode;
	tag = "Default";
	objectCode++;
}


GameObject::~GameObject(void)
{

}

void GameObject::setPosition(sf::Vector2f position)
{
	this->position=position;
}
sf::Vector2f GameObject::getPosition()
{
	return this->position;
}
void GameObject::setSize(sf::Vector2f size)
{
	this->size = size;
}
sf::Vector2f GameObject::getSize()
{
	return this->size;
}

sf::String GameObject::getName()
{
	return this->name;
}
void GameObject::setName(sf::String name)
{
	this->name = name;
}

sf::String GameObject::getTag()
{
	return this->tag;
}
void GameObject::setTag(sf::String tag)
{
	this->tag = tag;
}

bool GameObject::isCollide(GameObject * obj)
{
	sf::Rect<float> A,B;
	A.left = this->position.x;
	A.top = this->position.y;
	A.width = this->size.x;
	A.height = this->size.y;

	B.left = obj->getPosition().x;
	B.top = obj->getPosition().y;
	B.width = obj->getSize().x;
	B.height = obj->getSize().y;

	return A.intersects(B);
}


int GameObject::objectCode =1;