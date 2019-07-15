#ifndef OPTIONSMENU_H
#define OPTIONSMENU_H
#include "GameObject.h"
#include "SceneManager.h"



class optionsMenu:public GameObject
{
    public:
        optionsMenu();
        virtual ~optionsMenu();
        virtual void render(sf::RenderWindow * win);
        virtual void update();
        virtual bool isCollide(GameObject * obj);
        virtual sf::Rect<float> getHitBox();
        void changeSelection(bool up);
        int players,music,speed;
    protected:
        void loadNumbers();
        void changeOption(int index,bool left);
        sf::SoundBuffer bBeep;
        sf::Sound sBeep;
        sf::Texture menuMain;
        sf::Texture numbers[4];
        int selectionIndex;
       // int players,speed,music;
        const int cooldown = 10;
        const int buttonCD = 25;
        int buttonCooldown;
        int currentCooldown;

        unsigned int currentFrame;
    private:
};

#endif // OPTIONSMENU_H
