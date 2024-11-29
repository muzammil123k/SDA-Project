#ifndef Alpha_h
#define Alpha_h
#include"Invaders.h"

#include <SFML/Graphics.hpp>

#include<iostream>

#include<string.h>

using namespace sf;
using namespace std;
class Alpha : public Invaders {

public: Alpha() {
    bombTime = 0.0;
    type = 1;
}

      double bombTime;
      void LoadingTexture() {
          EnemyTex.loadFromFile("img/Invader1.png");
          EnemySprite.setTexture(EnemyTex);
      }

      void bombing(float g) {
          if ((g - bombTime) > 5.0) {
              bombTime = g;
              b->bombsprite.setPosition(EnemySprite.getPosition().x, EnemySprite.getPosition().y);
          }
          //b->move();
      }
};
#endif
#pragma once
