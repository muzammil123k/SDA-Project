#ifndef Addons_h
#define Addons_h
#include <SFML/Graphics.hpp>

#include<iostream>

#include<string.h>

#include <ctime>

#include<cmath>

using namespace sf;
using namespace std;
class Addons {
public:
    Texture AddonsTex;
    Sprite AddonsSprite;
    float speed = 0.2;
    Addons() {
        //LoadingTexture();
    }
    void addOnGernator() {
        //LoadingTexture();
        int n = rand() % 750 + 10;
        AddonsSprite.setPosition(n, 0);

    }
    void move() {
        float delta_x = 0, delta_y = 0;
        delta_y = 1;



        delta_x *= speed;
        delta_y *= speed;

        AddonsSprite.move(delta_x, delta_y);

    }
    virtual void LoadingTexture() = 0;
};
#endif
#pragma once
