#include "Game.h"

Game::Game(void)
{
}


Game::~Game(void)
{
}

void Game::setUp()
{
    SceneManager::getInstance()->clearGameObjects();

     int playerSpeed = SceneManager::getInstance()->speed;
    //set players
    //p1
	Moto * player = new Moto(sf::Vector2f(50,50));
	player->playerColor = sf::Color::Red;
	player->setName("Player1");
	player->setPlayer(0);
    player->setFacing(3);
    player->createWall();
    player->setVelocity(playerSpeed);
	SceneManager::getInstance()-> addGameObject(player);

    //p2
	player = new Moto(sf::Vector2f(1230,50));
	player->setName("Player2");
    player->playerColor = sf::Color::Blue;
	player->setPlayer(1);
	player->setFacing(2);
	player->createWall();
    player->setVelocity(playerSpeed);
    SceneManager::getInstance()-> addGameObject(player);
    //p3

          if (SceneManager::getInstance()->numberOfPlayers >= 2)
        {
        player = new Moto(sf::Vector2f(1230,680));
        player->setName("Player3");
        player->playerColor = sf::Color::Yellow;
        player->setPlayer(2);
        player->setFacing(2);
         player->createWall();
         player->setVelocity(playerSpeed);
        SceneManager::getInstance()-> addGameObject(player);
        }

    //p4
        if (SceneManager::getInstance()->numberOfPlayers == 3)
        {
        player = new Moto(sf::Vector2f(50,680));
        player->playerColor = sf::Color::Green;
        player->setName("Player4");
        player->setPlayer(3);
        player->setFacing(3);
        player->createWall();
        player->setVelocity(playerSpeed);
        SceneManager::getInstance()-> addGameObject(player);
        }

	/*
	Tanque * player = new Tanque();
	player->setPosition(sf::Vector2f(100,100));
	player->setName("Player1");


	SceneManager::getInstance()-> addGameObject(player);
    delete player;*/
    //set walls
    Wall * initialWall = new Wall(sf::Vector2f(0,0));
    initialWall->setHorizontal(true);
    initialWall->wallColor = sf::Color::White;
    initialWall->setSize(sf::Vector2f(1280,0));
    initialWall->setTag("boundary");
    SceneManager::getInstance()-> addGameObject(initialWall);

    initialWall = new Wall(sf::Vector2f(0,720));
    initialWall->setHorizontal(true);
    initialWall->setSize(sf::Vector2f(1280,720));
    initialWall->setTag("boundary");
    initialWall->wallColor = sf::Color::White;
    SceneManager::getInstance()-> addGameObject(initialWall);

    initialWall = new Wall(sf::Vector2f(0,0));
    initialWall->setHorizontal(false);
    initialWall->setSize(sf::Vector2f(0,720));
    initialWall->setTag("boundary");
    initialWall->wallColor = sf::Color::White;
    SceneManager::getInstance()-> addGameObject(initialWall);

    initialWall = new Wall(sf::Vector2f(1280,0));
    initialWall->setHorizontal(false);
    initialWall->setSize(sf::Vector2f(1280,720));
    initialWall->setTag("boundary");
    initialWall->wallColor = sf::Color::White;
    SceneManager::getInstance()-> addGameObject(initialWall);




//build main menu


}

void Game::processFrame()
{


	SceneManager::getInstance()->update();
	SceneManager::getInstance()->render();
    if(SceneManager::getInstance()->setup)
    {
        setUp();
        SceneManager::getInstance()->setup = false;
        SceneManager::getInstance()->frameAdvance();
    }


}

bool Game::isActive()
{
	return SceneManager::getInstance()->isActive();
}

