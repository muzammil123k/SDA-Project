#ifndef Beta_h
#define Beta_h
#include"Invaders.h"

#include <SFML/Graphics.hpp>

#include<iostream>

#include<string.h>

using namespace sf;
using namespace std;
class Beta : public Invaders {
public: Beta() {
    bombTime = 0.0;
    type = 2;
}
      double bombTime;
      void LoadingTexture() {
          EnemyTex.loadFromFile("img/Invader2.png");
          EnemySprite.setTexture(EnemyTex);

      }
      void bombing(float g) {
          if ((g - bombTime) > 3.0) {
              bombTime = g;
              b->bombsprite.setPosition(EnemySprite.getPosition().x, EnemySprite.getPosition().y);
          }
          //b->move();
      }
};
#endif
#pragma once
