#ifndef MAINMENU_H
#define MAINMENU_H
#include "GameObject.h"
#include "InputManager.h"
#include "SceneManager.h"
#include <SFML/Audio.hpp>
class MainMenu: public GameObject
{
    public:
        MainMenu();
        virtual ~MainMenu();
        virtual void render(sf::RenderWindow * win);
        virtual void update();
        virtual bool isCollide(GameObject * obj);
        virtual sf::Rect<float> getHitBox();
        void changeSelection(bool up);
    protected:
        sf::SoundBuffer bBeep;
        sf::Sound sBeep;
        sf::Texture menuMain;
        int selectionIndex;
        const int cooldown = 10;
        const int buttonCooldown = 20;
        int currentCooldown;
        int buttonPressCoolDown;
        unsigned int currentFrame;
    private:
};

#endif // MAINMENU_H
