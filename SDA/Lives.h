#ifndef Lives_h
#define Lives_h

#include <SFML/Graphics.hpp>

#include<iostream>

#include<string.h>

#include <ctime>

#include<cmath>
#include"Addons.h"

using namespace sf;
using namespace std;
class Lives : public Addons {
public:
    void LoadingTexture() {
        AddonsTex.loadFromFile("img/New1.png");
        AddonsSprite.setTexture(AddonsTex);
        AddonsSprite.setScale(0.25, 0.25);
        AddonsSprite.setPosition(790, 790);
    }
    Lives() {
        LoadingTexture();
    }
};
#endif
#pragma once
