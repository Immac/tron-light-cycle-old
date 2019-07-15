
#ifndef _GAMEOBJECT_
#define _GAMEOBJECT_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

class GameObject
{

private:
	static int objectCode;


protected:
	sf::Vector2f position;
	sf::Vector2f size;
	sf::String name;
	sf::String tag;

public:

	GameObject(void);
	~GameObject(void);

	sf::String getName();
	void setName(sf::String name);

	sf::String getTag();
	void setTag(sf::String name);

	//Dibuja el objeto
	virtual void render(sf::RenderWindow * win)=0;
	//Procesa Logica
	virtual void update()=0;

	void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition();
	void setSize(sf::Vector2f size);
	sf::Vector2f getSize();
    virtual sf::Rect<float> getHitBox() = 0;
	virtual bool isCollide(GameObject * obj);


};

#endif
