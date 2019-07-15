#include "SceneManager.h"


#include "InputManager.h"
SceneManager::SceneManager(void)
{
    loopIndex = 1 ;
    alive = findByTag("player");
    winScreen = new WinScreen();
    numberOfPlayers = 1;
    speed = 8;
    setup = false;
    if (!music[0].openFromFile("MSTPT.ogg"))
        exit(100); // error
    if (!music[1].openFromFile("BOD.ogg"))
        exit(100); // error
    if (!music[2].openFromFile("CMKA.ogg"))
        exit(100); // error
    if (!music[3].openFromFile("LOADH.ogg"))
        exit(100); // errors
    srand(time(0));
    srand(rand());
    int i = (rand()%4);
    music[i].play();
    for(int i = 0; i < 4;i++)
    {
        music[i].setLoop(1);
    }

    optionsMenu * options = new optionsMenu();
    options->music = i;

    addOptionObject(options);


}


SceneManager::~SceneManager(void)
{
}

void SceneManager::addGameObject(GameObject * obj)
{
	gameObjects.add(obj);
}
void SceneManager::addMenuObject(GameObject * obj)
{
	menuObjects.add(obj);
}

void SceneManager::addOptionObject(GameObject * obj)
{
	optionsObjects.add(obj);
}
void SceneManager::removeGameObject(GameObject * obj)
{
	for(int i=0;i<gameObjects.getSize();i++)
	{
		if(gameObjects.get(i)==obj)
		{
			gameObjects.remove(i);
			break;
		}
	}
}
void SceneManager::removeMenuObject(GameObject * obj)
{
	for(int i=0;i<menuObjects.getSize();i++)
	{
		if(menuObjects.get(i)==obj)
		{
			menuObjects.remove(i);
			break;
		}
	}
}
void SceneManager::removeOptionObject(GameObject * obj)
{
	for(int i=0;i<optionsObjects.getSize();i++)
	{
		if(optionsObjects.get(i)==obj)
		{
			optionsObjects.remove(i);
			break;
		}
	}
}

void SceneManager::render()
{
	window->isOpen();
	window->clear();

	switch(loopIndex)
	{
    case 0:
        for(int i=0;i<gameObjects.getSize();i++)
		gameObjects.get(i)->render(window);
		break;
    case 1:
         for(int i=0;i<menuObjects.getSize();i++)
            menuObjects.get(i)->render(window);
            break;
    case 2:
         winScreen->render(window);
            break;
    case 4:
         for(int i=0;i<optionsObjects.getSize();i++)
            optionsObjects.get(i)->render(window);

	}


	window->display();
}

void SceneManager::update()
{
	 sf::Event event;

    switch (loopIndex)
    {
    case 0:
        while (window->pollEvent(event))
     {
		  if ((event.type == sf::Event::Closed) )
          {
                window->close();
                break;
          }
		  InputManager::getInstance()->processEvent(event);



     }
            alive = findByTag("player");


          if(alive.getSize()<=1)
          {
              winScreen->winner = alive;
              if (!(alive.getSize() == 0)){
              Node<GameObject *> * hola = alive.first;
              Moto * dios = dynamic_cast<Moto*>(hola->getValue());
              winner = dios->playerNumber;
              }
              else
              {
                  winner = 5;
              }

            setup = true;
              loopIndex = 2;
              break;
          }

        if(loopIndex == 0)
        {
            for(int i=0;i<gameObjects.getSize();i++)
            gameObjects.get(i)->update();

            while(findByTag("dead").getSize() != 0)
                removeGameObject(findByTag("dead").first->getValue());


        }

    break;

    case 1:
        while (window->pollEvent(event))
     {
		  if ((event.type == sf::Event::Closed) )
          {
                window->close();
                break;
          }
		  InputManager::getInstance()->processEvent(event);

     }

	 for(int i=0;i<menuObjects.getSize();i++)
		menuObjects.get(i)->update();
    break;

    case 2:

        while (window->pollEvent(event))
     {
		  if ((event.type == sf::Event::Closed) )
          {
                window->close();
                break;
          }
		  InputManager::getInstance()->processEvent(event);

     }
        //winScreen->winner = alive;

        winScreen->update();

    break;

    case 3:
                window->close();
    break;


    case 4:
                 while (window->pollEvent(event))
     {
		  if ((event.type == sf::Event::Closed) )
          {
                window->close();
                break;
          }
		  InputManager::getInstance()->processEvent(event);

     }
            if(loopIndex == 4)
        {
            for(int i=0;i<optionsObjects.getSize();i++)
            optionsObjects.get(i)->update();
        }


    break;

    }

}

LinkedList<GameObject *> SceneManager::findByTag(sf::String tag)
{
	LinkedList<GameObject *> result;
	for(int i=0;i<gameObjects.getSize();i++)
	{
		if(gameObjects.get(i)->getTag()==tag)
			result.add(gameObjects.get(i));
	}
	return result;
}



GameObject *  SceneManager::findByName(sf::String name)
{
	for(int i=0;i<gameObjects.getSize();i++)
	{
		if(gameObjects.get(i)->getName()==name)
			return gameObjects.get(i);
	}
	return 0;
}

void SceneManager::init(int width,int height,const char *title)
{
	window = new sf::RenderWindow(sf::VideoMode(width,height,32),title);
	 window->setVerticalSyncEnabled(true);
}

bool SceneManager::isActive()
{
	return window->isOpen();
}

SceneManager * SceneManager::getInstance()
{
	if(instance==0)
		instance = new SceneManager();
	return instance;
}

bool SceneManager::setLoop(int index)
{
    this->loopIndex = index;
}
SceneManager * SceneManager::instance = 0;

void SceneManager::clearGameObjects()
{
    gameObjects.clear();
}

int SceneManager::getLoopIndex()
{
    return loopIndex;
}


void SceneManager::playSong(int index)
{
    for (int i = 0 ; i < 4; i++)
    {
        music[i].stop();
    }
    music[index].play();
}

void SceneManager::setSpeed(int index)
{
    switch(index)
    {
        case 0:
            speed = 6;
            break;
        case 1:
            speed = 8;
        case 2:
            speed = 10;
        case 3:
            speed = 12;
    }

}

void SceneManager::frameAdvance()
{
    for(int i=0;i<gameObjects.getSize();i++)
    gameObjects.get(i)->update();
}

void SceneManager::createPowerup()
{
    PowerUp * power = new PowerUp;
    addGameObject(power);
}



