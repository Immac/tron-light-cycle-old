#include "InputManager.h"


InputManager::InputManager(void)
{
	for(int i=0;i<256;i++)
		keys[i]=false;
}


InputManager::~InputManager(void)
{
}

void InputManager::processEvent( sf::Event event)
{


	if(event.type == sf::Event::KeyPressed)
		keys[event.key.code] = true;

	if(event.type == sf::Event::KeyReleased)
		keys[event.key.code] = false;


}

void InputManager::setCurrentEvent(sf::Event * event){
this->theEvent = event;
}

bool InputManager::isKeyPressed(int keyCode)
{
	return keys[keyCode];
}


InputManager * InputManager::getInstance()
{
	if(instance==0)
		instance = new InputManager();
	return instance;
}

InputManager * InputManager::instance=0;
