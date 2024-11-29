#ifndef Danger_h
#define Danger_h

#include <SFML/Graphics.hpp>

#include<iostream>

#include<string.h>

#include <ctime>

#include<cmath>
#include"Addons.h"

using namespace sf;
using namespace std;
class Danger : public Addons {
public:
    void LoadingTexture() {
        AddonsTex.loadFromFile("img/download.png");
        AddonsSprite.setTexture(AddonsTex);
        AddonsSprite.setScale(0.25, 0.25);
        AddonsSprite.setPosition(790, 790);
    }
    Danger() {
        LoadingTexture();
    }
};
#endif
#pragma once
