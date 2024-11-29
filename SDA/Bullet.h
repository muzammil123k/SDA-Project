#ifndef Bullet_h
#define Bullet_h
#include <SFML/Graphics.hpp>

#include<iostream>

#include<string.h>

using namespace sf;
using namespace std;
class Bullet {
public: Texture bulletTex;
      Sprite bulletsprite;
      float speed = 2;
      static int arrCount;
      static int loopCount;
      int rotatedFlag = 0;
      int x;
      int y;
      Bullet(std::string png_path = "img/bullets.png", int xx = -75, int yy = -75) {

          bulletTex.loadFromFile(png_path);
          bulletsprite.setTexture(bulletTex);
          x = xx;
          y = yy;
          bulletsprite.setPosition(sf::Vector2f(x, y));
          bulletsprite.setScale(0.04, 0.04);
      }
      Bullet(int xx, int yy) {
          x = xx;
          y = yy;
          bulletsprite.setPosition(sf::Vector2f(x, y));
          bulletsprite.setScale(0.04, 0.04);
      }

      void move() {

          float delta_x = 0, delta_y = 0;
          //cout<<rotatedFlag<<endl;
          if (rotatedFlag == 0) {
              delta_y = -3;
          }
          else if (rotatedFlag == 1) {
              delta_y = -3;
              delta_x = 3;
          }
          else if (rotatedFlag == 2) {
              delta_y = -3;
              delta_x = -3;
          }

          delta_x *= speed;
          delta_y *= speed;

          bulletsprite.move(delta_x, delta_y);

      }

};
int Bullet::arrCount = 0;
int Bullet::loopCount = 0;
#endif
#pragma once
