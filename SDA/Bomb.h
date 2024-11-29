#pragma once
#ifndef bomb_h
#define bomb_h
#include <SFML/Graphics.hpp>

#include<iostream>

#include<string.h>

using namespace sf;
using namespace std;
class Bomb {
public:
    Texture bombTex;
    Sprite bombsprite;
    // float speed = 0.35;
     //static int bomCount;
     //static int loopCount;
    int rotatedFlag = 0;
    int x,
        y;
    bool dragonBool;

    Bomb(int xx = 800, int yy = 800) {
        x = xx;
        y = yy;
        bombTex.loadFromFile("img/Bomb.png");
        bombsprite.setTexture(bombTex);
        bombsprite.setPosition(sf::Vector2f(x, y));
        bombsprite.setScale(1, 1);
        rotatedFlag = 0;
        dragonBool = 0;
    }
    void move(int f) {
        float delta_x = 0, delta_y = 0;
        if (f == 1) {

            delta_y = 1;
            if (dragonBool) {
                delta_x *= 10;
                delta_y *= 10;
            }
            else {
                delta_x *= 0.2;
                delta_y *= 0.2;
            }
        }
        else if (f == 2) {
            delta_y = 1;
            delta_x *= 0.35;
            delta_y *= 0.35;
        }
        else if (f == 3) {
            if (rotatedFlag == 0) {
                delta_y = 1;
                if (dragonBool) {
                    delta_x *= 7.0;
                    delta_y *= 7.0;
                }
                else {
                    delta_x *= 0.45;
                    delta_y *= 0.45;
                }

            }
            else if (rotatedFlag == 1) {
                delta_y = 1;
                delta_x = 0.75;
                delta_x *= 7.0;
                delta_y *= 7.0;
            }
            else if (rotatedFlag == 2) {
                delta_y = 1;
                delta_x = -0.75;
                delta_x *= 7.0;
                delta_y *= 7.0;
            }
        }
        bombsprite.move(delta_x, delta_y);
    }

};

//int bomb::bomCount = 0;
//int bomb::loopCount = 0;
#endif
