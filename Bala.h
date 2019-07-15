#pragma once

#include "GameObject.h"
#include "InputManager.h"
#include "SceneManager.h"
class Bala: public GameObject
{
public:
	Bala(void);
	~Bala(void);
	virtual void render(sf::RenderWindow * win);
	
	virtual void update();
};

