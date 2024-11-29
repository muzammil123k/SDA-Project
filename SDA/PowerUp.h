#ifndef PowerUp_h
#define PowerUp_h

#include <SFML/Graphics.hpp>

#include<iostream>

#include<string.h>

#include <ctime>

#include<cmath>
#include"Addons.h"

using namespace sf;
using namespace std;
class PowerUp : public Addons {
public:
    void LoadingTexture() {
        AddonsTex.loadFromFile("img/New.png");
        AddonsSprite.setTexture(AddonsTex);
        AddonsSprite.setScale(0.5, 0.5);
        AddonsSprite.setPosition(790, 790);
    }
    PowerUp() {
        LoadingTexture();
    }
};
#endif
#pragma once
