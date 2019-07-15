#ifndef WINSCREEN_H
#define WINSCREEN_H
#include "GameObject.h"
#include "SceneManager.h"
#include "InputManager.h"
class WinScreen:public GameObject
{
    public:
        WinScreen();
        virtual ~WinScreen();
        bool isCollide(GameObject * obj);
        virtual sf::Rect<float> getHitBox();
        void render(sf::RenderWindow * win);
        void update();
        LinkedList<GameObject *> winner;
        int timer;
        sf::String winnerName;
    protected:

        sf::SoundBuffer bBeep;
        sf::Sound sBeep;
        sf::Texture youWin;
        sf::Texture draw;
        sf::Texture textureWinner[5];
        bool tie;

    private:
};

#endif // WINSCREEN_H
