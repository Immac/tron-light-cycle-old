#pragma once
#include "GameObject.h"
#include "InputManager.h"
#include "Bala.h"

class Tanque: public GameObject
{
public:
	Tanque(void);
	~Tanque(void);
	virtual void render(sf::RenderWindow * win);
	
	virtual void update();
};

