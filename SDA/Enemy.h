#pragma once
#ifndef Enemy_h
#define Enemy_h
#include <SFML/Graphics.hpp>

#include<iostream>

#include<string.h>

#include"Bomb.h"

using namespace sf;
using namespace std;
class Enemy {
public: Texture EnemyTex;
	  Sprite EnemySprite;
	  Bomb* b = nullptr;
	  float speed = 0.05;
	  virtual void move(bool g) = 0;
	  virtual void LoadingTexture() = 0;
	  virtual void loadBombTex() = 0;
	  virtual void bombing(float g) = 0;
};
#endif
