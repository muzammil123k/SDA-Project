#ifndef Dragon_h
#define Dragon_h
#include <SFML/Graphics.hpp>

#include<iostream>

#include<string.h>

#include"Enemy.h"

using namespace sf;
using namespace std;
class Dragon : public Enemy {
public:
    static int arrCount;
    int x, y;
    float t = 0;
    Dragon(int xx = 10340, int yy = 10340) {
        t = 0;
        x = xx;
        y = yy;
        LoadingTexture();
        b = new Bomb[100];
        for (int i = 0; i < 100; i++) {
            b[i].dragonBool = 1;
        }
        EnemySprite.setPosition(x, y);
        EnemySprite.setScale(1, 1);
        loadBombTex();
    }
    void LoadingTexture() {
        EnemyTex.loadFromFile("img/dragon.png");
        EnemySprite.setTexture(EnemyTex);
    }
    void move(bool g) {
    }
    void loadBombTex() {
        for (int i = 0; i < 100; i++) {
            b[i].bombTex.loadFromFile("img/PNG/Lasers/laserBlue12.png");
            b[i].bombsprite.setTexture(b[i].bombTex);
        }

    }
    virtual void bombing(float g) {
        if (g == 0) {
            if (Dragon::arrCount == 100) {
                Dragon::arrCount = 0;
                //Bullet::loopCount++;
            }
            //b[Dragon::arrCount] = Bullet((sprite.getPosition().x) + 21, (sprite.getPosition().y) - 20);
            b[Dragon::arrCount].bombTex.loadFromFile("img/PNG/Lasers/laserBlue12.png");
            b[Dragon::arrCount].bombsprite.setTexture(b[Dragon::arrCount].bombTex);
            b[Dragon::arrCount].rotatedFlag = 0;
            b[Dragon::arrCount].bombsprite.setPosition(EnemySprite.getPosition().x + 120, EnemySprite.getPosition().y + 220);
            Dragon::arrCount++;
        }
        if (g == 1) {
            if (Dragon::arrCount == 100) {
                Dragon::arrCount = 0;
                //Dragon::loopCount++;
            }
            //b[Dragon::arrCount] = Bullet((sprite.getPosition().x) + 21, (sprite.getPosition().y) - 20);
            b[Dragon::arrCount].bombTex.loadFromFile("img/PNG/Lasers/laserBlue12.png");
            b[Dragon::arrCount].bombsprite.setTexture(b[Dragon::arrCount].bombTex);
            b[Dragon::arrCount].rotatedFlag = 1;
            b[Dragon::arrCount].bombsprite.setPosition(EnemySprite.getPosition().x + 120, EnemySprite.getPosition().y + 220);
            Dragon::arrCount++;

        }
        if (g == 2) {
            if (Dragon::arrCount == 100) {
                Dragon::arrCount = 0;
                //Dragon::loopCount++;
            }

            //b[Dragon::arrCount] = Bullet((sprite.getPosition().x) + 21, (sprite.getPosition().y) - 20);
            b[Dragon::arrCount].bombTex.loadFromFile("img/PNG/Lasers/laserBlue12.png");
            b[Dragon::arrCount].bombsprite.setTexture(b[Dragon::arrCount].bombTex);
            b[Dragon::arrCount].rotatedFlag = 2;
            b[Dragon::arrCount].bombsprite.setPosition(EnemySprite.getPosition().x + 120, EnemySprite.getPosition().y + 220);
            Dragon::arrCount++;
        }
    }
};
int Dragon::arrCount = 0;
#endif
#pragma once
