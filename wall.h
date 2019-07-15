#ifndef WALL_H
#define WALL_H
#include "GameObject.h"
#include "InputManager.h"
#include "linkedlist.h"
#include "SceneManager.h"
#include <iostream>
class Wall : public GameObject
{
    public:
        Wall();
        Wall(sf::Vector2f position);
        sf::Vector2f wallEnd;
        virtual ~Wall();
        bool setHorizontal(bool value);
        bool isCollide(GameObject * obj);
        virtual sf::Rect<float> getHitBox();
        sf::Color wallColor;
    protected:
        bool isHorizontal;
        void render(sf::RenderWindow * win);
        void update();


    private:
};

#endif // WALL_H
