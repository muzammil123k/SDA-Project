#ifndef Monster_h
#define Monster_h

#include <SFML/Graphics.hpp>

#include<iostream>

#include<string.h>

#include"Enemy.h"

using namespace sf;
using namespace std;
class Monster : public Enemy {
public:
    static int arrCount;
    int x, y;
    float t = 0;
    Monster(int xx = 10340, int yy = 10340) {
        t = 0;
        x = xx;
        y = yy;
        LoadingTexture();
        b = new Bomb[100];
        for (int i = 0; i < 100; i++) {
            b[i].dragonBool = 1;
        }
        EnemySprite.setPosition(x, y);
        EnemySprite.setScale(0.5, 0.5);
        loadBombTex();
    }
    void LoadingTexture() {
        EnemyTex.loadFromFile("img/monster1.png");
        EnemySprite.setTexture(EnemyTex);
    }
    void move(bool g) {
        float delta_x = 0, delta_y = 0;
        if (g == 0) {
            delta_x = -1;
        }
        else if (g == 1) {
            delta_x = 1;
        }
        delta_x *= 0.125;
        delta_y *= 0.125;
        EnemySprite.move(delta_x, delta_y);
    }
    void loadBombTex() {
        for (int i = 0; i < 100; i++) {
            b[i].bombTex.loadFromFile("img/PNG/Lasers/laserBlue12.png");
            b[i].bombsprite.setTexture(b[i].bombTex);
        }
    }
    virtual void bombing(float g) {
        if (g == 0) {
            if (Monster::arrCount == 100) {
                Monster::arrCount = 0;
                //Monster::loopCount++;
            }
            //f[Monster::arrCount] = Bullet((sprite.getPosition().x) + 21, (sprite.getPosition().y) - 20);
            b[Monster::arrCount].bombTex.loadFromFile("img/PNG/Lasers/laserBlue12.png");
            b[Monster::arrCount].bombsprite.setTexture(b[Monster::arrCount].bombTex);
            b[Monster::arrCount].bombsprite.setPosition(EnemySprite.getPosition().x + 150, EnemySprite.getPosition().y + 220);
            b[Monster::arrCount].rotatedFlag = 0;

            Monster::arrCount++;
        }
    }

};
int Monster::arrCount = 0;
#endif


#pragma once
