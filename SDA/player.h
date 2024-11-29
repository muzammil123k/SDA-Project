#pragma once
#include <SFML/Graphics.hpp>

#include<string.h>

#include "Bullet.h"

using namespace sf;
class Player {
public: Texture tex;
      Sprite sprite;
      float speed = 1.9;
      int Live = 3;
      int x,
          y;
      float time = 0;
      Bullet* f = new Bullet[100]; // Bullet *b;   b=

      Player(std::string png_path) {
          Live = 3;
          tex.loadFromFile(png_path);
          sprite.setTexture(tex);
          x = 340;
          y = 700;
          sprite.setPosition(sf::Vector2f(x, y));
          sprite.setScale(0.75, 0.75);
      }

      void fire(int g) {
          if (g == 0) {
              if (Bullet::arrCount == 100) {
                  Bullet::arrCount = 0;
                  Bullet::loopCount++;
              }
              f[Bullet::arrCount] = Bullet((sprite.getPosition().x) + 21, (sprite.getPosition().y) - 20);
              f[Bullet::arrCount].bulletTex.loadFromFile("img/bullets.png");
              f[Bullet::arrCount].bulletsprite.setTexture(f[Bullet::arrCount].bulletTex);
              f[Bullet::arrCount].rotatedFlag = 0;
              Bullet::arrCount++;
          }
          if (g == 1) {
              if (Bullet::arrCount == 100) {
                  Bullet::arrCount = 0;
                  Bullet::loopCount++;
              }
              f[Bullet::arrCount] = Bullet((sprite.getPosition().x) + 21, (sprite.getPosition().y) - 20);
              f[Bullet::arrCount].bulletTex.loadFromFile("img/bullets1.png");
              f[Bullet::arrCount].bulletsprite.setTexture(f[Bullet::arrCount].bulletTex);
              f[Bullet::arrCount].rotatedFlag = 1;
              Bullet::arrCount++;

          }
          if (g == 2) {
              if (Bullet::arrCount == 100) {
                  Bullet::arrCount = 0;
                  Bullet::loopCount++;
              }

              f[Bullet::arrCount] = Bullet((sprite.getPosition().x) + 21, (sprite.getPosition().y) - 20);
              f[Bullet::arrCount].bulletTex.loadFromFile("img/bullets2.png");
              f[Bullet::arrCount].bulletsprite.setTexture(f[Bullet::arrCount].bulletTex);
              f[Bullet::arrCount].rotatedFlag = 2;
              Bullet::arrCount++;
          }
          if (g == 3) {
              if (Bullet::arrCount == 100) {
                  Bullet::arrCount = 0;
                  Bullet::loopCount++;
              }
              f[Bullet::arrCount] = Bullet((sprite.getPosition().x) + 21, (sprite.getPosition().y) - 20);
              f[Bullet::arrCount].bulletTex.loadFromFile("img/bullets.png");
              f[Bullet::arrCount].bulletsprite.setTexture(f[Bullet::arrCount].bulletTex);
              f[Bullet::arrCount].rotatedFlag = 0;
              Bullet::arrCount++;
              if (Bullet::arrCount == 100) {
                  Bullet::arrCount = 0;
                  Bullet::loopCount++;
              }

              f[Bullet::arrCount] = Bullet((sprite.getPosition().x) + 21, (sprite.getPosition().y) - 20);
              f[Bullet::arrCount].bulletTex.loadFromFile("img/bullets2.png");
              f[Bullet::arrCount].bulletsprite.setTexture(f[Bullet::arrCount].bulletTex);
              f[Bullet::arrCount].rotatedFlag = 2;
              Bullet::arrCount++;
              if (Bullet::arrCount == 100) {
                  Bullet::arrCount = 0;
                  Bullet::loopCount++;
              }
              f[Bullet::arrCount] = Bullet((sprite.getPosition().x) + 21, (sprite.getPosition().y) - 20);
              f[Bullet::arrCount].bulletTex.loadFromFile("img/bullets1.png");
              f[Bullet::arrCount].bulletsprite.setTexture(f[Bullet::arrCount].bulletTex);
              f[Bullet::arrCount].rotatedFlag = 1;
              Bullet::arrCount++;
          }
      }
      void move(std::string s) {
          float delta_x = 0, delta_y = 0;
          if (s == "l")
              delta_x = -2; //move the player left
          else if (s == "r")
              delta_x = 2; //move the player right
          if (s == "u")
              delta_y = -2;
          else if (s == "d")
              delta_y = 2;

          delta_x *= speed;
          delta_y *= speed;

          sprite.move(sf::Vector2f(delta_x, delta_y));

      }
      void RotateR() {
          tex.loadFromFile("img/player_ship1.png");
          sprite.setTexture(tex);
          sprite.setScale(1, 1);
      }
      void RotateL() {
          tex.loadFromFile("img/player_ship2.png");
          sprite.setTexture(tex);
          sprite.setScale(1, 1);
      }
      void anomly(bool l) {
          if (l) {
              if (sprite.getPosition().x < 0 || sprite.getPosition().y > 780 || sprite.getPosition().y < 0 || sprite.getPosition().x > 780) {
                  if (sprite.getPosition().x < -10) {
                      sprite.setPosition(790, sprite.getPosition().y);
                  }
                  if (sprite.getPosition().x > 790) {
                      sprite.setPosition(-10, sprite.getPosition().y);
                  }
                  if (sprite.getPosition().y < -10) {
                      sprite.setPosition(sprite.getPosition().x, 790);
                  }
                  if (sprite.getPosition().y > 790) {
                      sprite.setPosition(sprite.getPosition().x, -10);
                  }
              }
          }
      }

};
