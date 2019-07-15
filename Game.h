
#ifndef _GAME_
#define _GAME_

#include <SFML/Graphics.hpp>
#include "SceneManager.h"
#include "Tanque.h"
#include "moto.h"
#include "wall.h"
#include "mainmenu.h"
#include "winscreen.h"
class Game
{

private:


public:
	Game(void);
	~Game(void);

	void setUp();
	void processFrame();
	bool isActive();


};

#endif

