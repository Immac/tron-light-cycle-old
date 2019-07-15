


#ifndef _SCENEMANAGER_
#define _SCENEMANAGER_

#include "GameObject.h"
#include "linkedlist.h"
#include "winscreen.h"
#include "moto.h"
#include <SFML/Graphics.hpp>
#include "optionsmenu.h"
#include "powerup.h"
class WinScreen;
class optionsMenu;
class PowerUp;

class SceneManager
{


private:
    int loopIndex;
	LinkedList<GameObject *> gameObjects;
	LinkedList<GameObject *> menuObjects;
	LinkedList<GameObject *> optionsObjects;
	WinScreen * winScreen;
	sf::RenderWindow * window;
	SceneManager(void);
	static SceneManager * instance;



public:
    void frameAdvance();
    bool setup;
    void setSpeed(int index);
     int numberOfPlayers;
     int speed;
    sf::Music music[10];
    int winner;
	~SceneManager(void);
    LinkedList<GameObject *> alive;

	LinkedList<GameObject *> findByTag(sf::String tag);
	GameObject *  findByName(sf::String name);
    void clearGameObjects();
	void addGameObject(GameObject * obj);
	void addMenuObject(GameObject * obj);
	void addOptionObject(GameObject * obj);
	void removeGameObject(GameObject * obj);
	void removeMenuObject(GameObject * obj);
	void removeOptionObject(GameObject * obj);
    void createPowerup();
    void playSong(int index);
    bool setLoop(int index);
	void init(int width,int height,const char * title);
	void render();
	void update();
	bool isActive();
    int getLoopIndex();
	static SceneManager * getInstance();


};

#endif

