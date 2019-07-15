#ifndef POWERUP_H
#define POWERUP_H
#include "GameObject.h"
#include "linkedlist.h"
#include "InputManager.h"
#include "wall.h"
#include "SceneManager.h"

class PowerUp:public GameObject
{
    public:
        PowerUp();
        virtual ~PowerUp();

        sf::Rect<float> getHitBox();
        virtual void render(sf::RenderWindow * win);
        virtual void update();
        bool isCollide(GameObject * obj);




    protected:
    private:
        sf::Texture texture[3];
        int powerType;
};

#endif // POWERUP_H
