#ifndef MOTO_H
#define MOTO_H

#include "GameObject.h"
#include "InputManager.h"
#include "wall.h"
#include "SceneManager.h"

class Wall;

class Moto: public GameObject
{
    public:
        void activatePower(int index);
        Moto(sf::Vector2<float> initialPosition);
        virtual ~Moto();
        void setPlayer(int i);
        sf::Vector2f center;
        //pertenecen an GameObject
        sf::Rect<float> getHitBox();
            //Dibuja el objeto
        virtual void render(sf::RenderWindow * win);
        //Procesa Logica
        virtual void update();



        void createWall();
        void setFacing(int faceIndex);
        sf::Color playerColor;
        int playerNumber;
        float getVelocity();
        void setVelocity(float value);
        void speedUp();
        void invulnerability();
        void invisWalls();
        bool hasSpeedPower,hasInvulnerabilityPower,hasInvisibilityPower;
        bool isInvulnerable,hasInvisWalls,isFaster;
        void reset();

    protected:

        enum timers
        {
            SPEED,
            INVUL,
            INVIS,
            FRAMES
        };
        int timer[4];
        int maxTimer[4];
        Wall * currentWall;
        bool skipAFrame;

        int sensitivity;



        float velocity;
    private:
        int facing;
        void keyboardInputs(bool isHorizontal,bool isVertical);

};

#endif // MOTO_H
