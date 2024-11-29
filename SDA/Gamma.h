#ifndef Gamma_h
#define Gamma_h
#include"Invaders.h"

#include <SFML/Graphics.hpp>

#include<iostream>

#include<string.h>

using namespace sf;
using namespace std;
class Gamma : public Invaders {
public: Gamma() {
    bombTime = 0.0;
    type = 3;
}
      double bombTime;
      void LoadingTexture() {
          EnemyTex.loadFromFile("img/Invader3.png");
          EnemySprite.setTexture(EnemyTex);

      }
      void bombing(float g) {
          if ((g - bombTime) > 2.0) {
              bombTime = g;
              b->bombsprite.setPosition(EnemySprite.getPosition().x, EnemySprite.getPosition().y);
          }
          // b->move();
      }
};
#endif
#pragma once
