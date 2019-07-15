#pragma once
#include <SFML/Graphics.hpp>

class InputManager
{
private:
	InputManager(void);
	~InputManager(void);
	static InputManager * instance;
	bool keys[256];
public:


	void processEvent( sf::Event event);
    sf::Event * theEvent;
    void setCurrentEvent(sf::Event * event);
	static InputManager * getInstance();

	bool isKeyPressed(int keyCode);

};

