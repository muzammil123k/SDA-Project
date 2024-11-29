#ifndef Invaders_h
#define Invaders_h
#include <SFML/Graphics.hpp>

#include<iostream>

#include<string.h>

#include"Enemy.h"

using namespace sf;
using namespace std;
class Invaders : public Enemy {
public:
    float speed = 0.05;
    int type;
    int x, y;
    float t = 0;
    Invaders(int xx = -70, int yy = -70) {
        t = 0;
        x = xx;
        y = yy;
        EnemySprite.setPosition(x, y);
        EnemySprite.setScale(0.25, 0.25);
        loadBombTex();
        b = new Bomb;

    }
    void move(bool g) {
        float delta_x = 0, delta_y = 0;
        if (g == 0) {
            delta_x = -1;
        }
        else if (g == 1) {
            delta_x = 1;
        }
        delta_x *= speed;
        delta_y *= speed;
        EnemySprite.move(delta_x, delta_y);
    }
    virtual void LoadingTexture() = 0;
    virtual void loadBombTex() {
        /*b -> bombTex.loadFromFile("img/Bomb.png");
        b -> bombsprite.setTexture(b -> bombTex);*/
    }
    virtual void bombing(float g) = 0;
};
//int Bullet::arrCount = 0;
//int Bullet::loopCount = 0;
#endif
