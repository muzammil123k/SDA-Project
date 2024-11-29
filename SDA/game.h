#include <SFML/Graphics.hpp>

#include <time.h>

#include <vector>

#include "player.h"

#include"Alpha.h"

#include"Beta.h"

#include"Gamma.h"

#include<iostream>

#include <cstdlib>

#include <ctime>

#include<cmath>

//#include"Dragon.h"

//#include"Monster.h"

#include"PowerUp.h"

#include"Danger.h"

#include"Lives.h"

#include"menu.h"

using namespace std;
using namespace sf;
const char title[] = "OOP-Project, Spring-2023";
class Game {
public: Sprite background; //Game background sprite
      Texture bg_texture;
      Player* p; //player 
      // add other game attributes
      Invaders** ene;
     // Dragon* d;
      //Monster* m;
      Addons** a;
      Menu M;
      bool invaderMovement = 0;
      float invadertime = 0;
      int invaderKilled = 0;
      int changelevel = 0;
      bool playerOnScreen = 1;
      int score = 0;
      int Level = 1;
     // bool DragonShow = 0;
     // bool MonsterShow = 0;
      float dragonTime = 0;
      float monsterTime = 0;
      float playerRegion = 0;
      float addtime = 0.0;
      bool monstermovement = 0;
      bool powerup = 0;
      float powertime = 0;
      Game() {
         // d = new Dragon;
          // m = new Monster;
          ene = new Invaders * [20];
          p = new Player("img/player_ship.png");
          a = new Addons * [4];
          a[0] = new PowerUp;
          a[1] = new Danger;
          a[2] = new Lives;
          a[3] = nullptr;
          bg_texture.loadFromFile("img/background.jpg");
          background.setTexture(bg_texture);
          background.setScale(2, 1.5);
          invaderMovement = 0;
          monstermovement = 0;
          invadertime = 0;
          invaderKilled = 0;
          changelevel = 0;
          playerOnScreen = 1;
          score = 0;
          ////DragonShow = 0;
          powertime = 0;
          addtime = 0.0;
          dragonTime = 0;
          ////MonsterShow = 0;
          monsterTime = 0;
          Level = 1;
          playerRegion = 0;
          powerup = 0;
      }
      /*void dragonShow(float timer){

       if()
      }*/
      void setpower(float timer) {
          if (p->sprite.getGlobalBounds().intersects(a[0]->AddonsSprite.getGlobalBounds())) {
              powerup = 1;
              timer = powertime;
              a[0]->AddonsSprite.setPosition(0, 990);
              // cout<<"po"<<timer<<endl;
          }

          if ((timer - powertime) > 5) {
              powerup = 0;
              //cout<<"po"<<timer<<endl;
          }

      }
      void setdanger() {
          if (p->sprite.getGlobalBounds().intersects(a[1]->AddonsSprite.getGlobalBounds())) {
              a[1]->AddonsSprite.setPosition(0, 990);
              p->sprite.setPosition(-1000, -1000);
          }
      }
      void setLives() {
          if (p->sprite.getGlobalBounds().intersects(a[2]->AddonsSprite.getGlobalBounds())) {
              a[2]->AddonsSprite.setPosition(0, 990);
              p->Live++;
          }
      }
      void playersRegion() {
          if ((p->sprite.getPosition().x) < 260) {
              playerRegion = 2;
          }
          else if ((p->sprite.getPosition().x) < 520) {
              playerRegion = 0;
          }
          else if ((p->sprite.getPosition().x) < 780) {
              playerRegion = 1;
          }
      }

      /*void setDragonBool(float timer) {
          if (DragonShow == 0 && MonsterShow == 0) {

              if ((timer - dragonTime) > 10.0) {
                  cout << timer << endl;
                  int n = 2; //rand() % 2 + 1;

                  if (n == 1) {
                      d->EnemySprite.setPosition(260, 0);
                      DragonShow = 1;
                  }
                  if (n == 2) {
                      m->EnemySprite.setPosition(230, 0);
                      MonsterShow = 1;
                  }

                  dragonTime = timer;
              }
          }
          if (DragonShow == 1) {
              if ((timer - dragonTime) > 5.0) {
                  cout << timer << endl;
                  d->EnemySprite.setPosition(10340, 10340);
                  DragonShow = 0;
                  dragonTime = timer;
              }
          }
          if (MonsterShow == 1) {
              if ((timer - dragonTime) > 2.5) {
                  cout << timer << endl;
                  m->EnemySprite.setPosition(10340, 10340);
                  MonsterShow = 0;
                  dragonTime = timer;
              }
          }

      }*/
      void bombDistruction() {
          for (int j = 0; j < 20; j++) {
              if (p->sprite.getGlobalBounds().intersects(ene[j]->b->bombsprite.getGlobalBounds())) {
                  playerOnScreen = 0;
                  p->sprite.setPosition(-1000, -1000);
                  ene[j]->b->bombsprite.setPosition(-75, -75);
              }
          }


      }
      /*void DragonbombDistruction() {
          for (int j = 0; j < 100; j++) {
              if (p->sprite.getGlobalBounds().intersects(d->b[j].bombsprite.getGlobalBounds())) {
                  playerOnScreen = 0;
                  p->sprite.setPosition(-1000, -1000);
                  //ene[j] -> b -> bombsprite.setPosition(-75, -75);
              }
          }
          for (int j = 0; j < 100; j++) {
              if (p->sprite.getGlobalBounds().intersects(m->b[j].bombsprite.getGlobalBounds())) {
                  playerOnScreen = 0;
                  p->sprite.setPosition(-1000, -1000);
                  //ene[j] -> b -> bombsprite.setPosition(-75, -75);
              }
          }
      }*/
      void reApearecne() {
          if ((p->sprite.getPosition().x) < -20)
              if ((p->Live) > 0) {
                  playerOnScreen = 1;
                  (p->Live) = (p->Live) - 1;
                  p->sprite.setPosition(340, 700);
              }
      }
      /*void dragonDistruction() {
          if (DragonShow == 1) {

              if (p->sprite.getGlobalBounds().intersects(d->EnemySprite.getGlobalBounds())) {
                  playerOnScreen = 0;
                  p->sprite.setPosition(-1000, -1000);

              }
          }
      }*/
      void addonTime(float timer) {
          if (timer - addtime > 8.0) {
              addtime = timer;
              int n = rand() % 3;
              a[n]->addOnGernator();
          }
      }
      /*void monsterDistruction() {
          if (MonsterShow == 1) {

              if (p->sprite.getGlobalBounds().intersects(m->EnemySprite.getGlobalBounds())) {
                  playerOnScreen = 0;
                  p->sprite.setPosition(-1000, -1000);

              }
          }
      }*/
      void invaderDistruction() {
          for (int j = 0; j < 20; j++) {
              if (p->sprite.getGlobalBounds().intersects(ene[j]->EnemySprite.getGlobalBounds())) {
                  playerOnScreen = 0;
                  p->sprite.setPosition(-1000, -1000);
                  ene[j]->EnemySprite.setPosition(-75, -75);
              }
          }
      }
      void bulletDistruction() {
          for (int i = 0; i < 100; i++) {
              if ((p->f[i].bulletsprite.getPosition().x) > -10 && (p->f[i].bulletsprite.getPosition().x) < 790 && (p->f[i].bulletsprite.getPosition().y) > -10 && (p->f[i].bulletsprite.getPosition().y) < 790) {
                  for (int j = 0; j < 20; j++) {
                      if ((p->f[i].bulletsprite.getPosition().x) > (ene[j]->EnemySprite.getPosition().x)) {
                          if ((p->f[i].bulletsprite.getPosition().x) < ((ene[j]->EnemySprite.getPosition().x) + 42)) {
                              if ((p->f[i].bulletsprite.getPosition().y) > (ene[j]->EnemySprite.getPosition().y)) {
                                  if ((p->f[i].bulletsprite.getPosition().y) < ((ene[j]->EnemySprite.getPosition().y) + 42)) {
                                      p->f[i].bulletsprite.setPosition(-75, -75);
                                      ene[j]->EnemySprite.setPosition(-75, -75);
                                      score = score + (10 * Level);
                                      invaderKilled++;
                                      break;
                                  }
                              }
                          }
                      }
                  }
              }
          }
      }
      void assingInvader() {
          for (int i = 0; i < 20; i++) {
              int random = rand() % 6 + 1;
              if (random == 1 || random == 6) {
                  ene[i] = new Alpha;
              }
              if (random == 2 || random == 5) {
                  ene[i] = new Beta;
              }
              if (random == 3 || random == 4) {
                  ene[i] = new Gamma;
              }
              ene[i]->LoadingTexture();
          }
      }
      void DisplayEnemy() {
          if (invaderKilled < 19) {
              for (int i = 0; i < 8; i++)
                  ene[i]->EnemySprite.setPosition(150 + (i * 60), 100);
              ene[8]->EnemySprite.setPosition(150, 160);
              ene[9]->EnemySprite.setPosition(570, 160);
              ene[10]->EnemySprite.setPosition(150, 220);
              ene[11]->EnemySprite.setPosition(570, 220);
              for (int i = 12; i < 20; i++)
                  ene[i]->EnemySprite.setPosition(150 + ((i - 12) * 60), 280);
          }
          else if (invaderKilled < 38) {
              float increment = 2.f * 3.14 / 20;
              for (int i = 0; i < 20; i++)
                  ene[i]->EnemySprite.setPosition(325 + 210 * cos(i * increment), 250 + 210 * sin(i * increment));
          }
          else if (invaderKilled < 55) {
              for (int i = 0; i < 7; i++) {
                  ene[i]->EnemySprite.setPosition(200 + (i * 60), 100);
              }
              ene[11]->EnemySprite.setPosition(230, 160);
              ene[8]->EnemySprite.setPosition(540, 160);
              ene[9]->EnemySprite.setPosition(260, 220);
              ene[10]->EnemySprite.setPosition(510, 220);
              ene[7]->EnemySprite.setPosition(490, 280);
              ene[12]->EnemySprite.setPosition(290, 280);
              ene[13]->EnemySprite.setPosition(320, 340);
              ene[14]->EnemySprite.setPosition(460, 340);
              ene[15]->EnemySprite.setPosition(350, 400);
              ene[16]->EnemySprite.setPosition(430, 400);
              ene[17]->EnemySprite.setPosition(390, 460);
          }
      }
      void start_game() {
          //cout<<'m';
          srand(time(0));
          M.display_menu();
          RenderWindow window(VideoMode(780, 780), title);
          Clock clock;
          float timer = 0;
          float b_t = 0.0;
          bool rotate = 0;
          int rotateFlag = 0;
          float dragonMonsterTimer = 0;
          assingInvader();
          DisplayEnemy();

          while (window.isOpen()) {

              rotate = 0;
              rotateFlag = 0;
              float time = clock.getElapsedTime().asSeconds();
              clock.restart();
              timer += time;
              Event e;
              while (window.pollEvent(e)) {
                  if (e.type == Event::Closed) // If cross/close is clicked/pressed
                      window.close(); //close the game                        	    
              }
              if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Right)) {
                  p->speed = 0.1414;
                  p->RotateR();
                  rotate = 1;
                  rotateFlag = 1;
              }
              if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Left)) {
                  p->speed = 0.1414;
                  p->RotateL();
                  rotate = 1;
                  rotateFlag = 2;
              }
              if (Keyboard::isKeyPressed(Keyboard::Left)) //If left key is pressed
                  p->move("l"); // Player will move to left
              if (Keyboard::isKeyPressed(Keyboard::Right)) // If right key is pressed
                  p->move("r"); //player will move to right
              if (Keyboard::isKeyPressed(Keyboard::Up)) //If up key is pressed
                  p->move("u"); //playet will move upwards
              if (Keyboard::isKeyPressed(Keyboard::Down)) // If down key is pressed
                  p->move("d"); //player will move downwards
              if (Keyboard::isKeyPressed(Keyboard::X) && timer - b_t > 0.15) {
                  p->fire(rotateFlag);
                  b_t = timer;
              }
              if (Keyboard::isKeyPressed(Keyboard::P)) {
                  M.displayPausemenu(score, p->Live);
              }
              // cout<<timer<<endl;
              //if (DragonShow == 0 && MonsterShow == 0) {
                  if (invadertime < 2.0) {
                      if (timer - invadertime > 2.0) {
                          invadertime = timer;
                          if (invaderMovement == 1)
                              invaderMovement = 0;
                          else if (invaderMovement == 0)
                              invaderMovement = 1;
                      }
                  }
                  else if (timer - invadertime > 4.0) {
                      invadertime = timer;
                      if (invaderMovement == 1)
                          invaderMovement = 0;
                      else if (invaderMovement == 0)
                          invaderMovement = 1;
                  }
             // }
              /*if (MonsterShow == 1) {
                  if (monsterTime < 0.5) {
                      if (timer - monsterTime > 0.5) {
                          monsterTime = timer;
                          if (monstermovement == 1)
                              monstermovement = 0;
                          else if (monstermovement == 0)
                              monstermovement = 1;
                      }
                  }
                  else if (timer - monsterTime > 1.0) {
                      monsterTime = timer;
                      if (monstermovement == 1)
                          monstermovement = 0;
                      else if (monstermovement == 0)
                          monstermovement = 1;
                  }
                  m->move(monstermovement);
              }*/
              ////////////////////////////////////////////////
              ///Call your functions here ////
              for (int i = 0; i < 100; i++) {
                  //cout<<"h"<<endl;
                  p->f[i].move();
              }
              /*if (DragonShow == 1) {
                  d->bombing(playerRegion);
                  for (int i = 0; i < 100; i++) {
                      d->b[i].move(3);
                  }
              }*/
              addonTime(timer);
              a[0]->move();
              a[1]->move();
              a[2]->move();
              setdanger();
              setLives();
              setpower(timer);
              if (powerup == 1 && timer - b_t > 0.15) {
                  p->fire(3);
                  b_t = timer;
              }
              /*monsterDistruction();
              dragonDistruction();
              DragonbombDistruction();
              if (MonsterShow == 1) {
                  m->bombing(0);
                  for (int i = 0; i < 100; i++) {
                      m->b[i].move(1);
                  }
              }
              setDragonBool(timer);
              //setMonsterBool(timer);
              */
              reApearecne();
              playersRegion();
              //if (DragonShow == 0 && MonsterShow == 0) {
                  bombDistruction();
                  bulletDistruction();
              //}

              //if (DragonShow == 0 && MonsterShow == 0) {
                  invaderDistruction();
              //}
              p->anomly(playerOnScreen);
              //if (DragonShow == 0 && MonsterShow == 0) {
                  for (int i = 0; i < 20; i++) {
                      ene[i]->move(invaderMovement);
                  }
             // }
              changelevel = 0;
              for (int i = 0; i < 20; i++) {
                  if (ene[i]->EnemySprite.getPosition().y < -10)
                      changelevel++;
              }
              if (changelevel == 20) {
                  DisplayEnemy();
              }
              //if (DragonShow == 0 && MonsterShow == 0) {
                  for (int i = 0; i < 20; i++) {
                      ene[i]->b->move(ene[i]->type);
                      if (ene[i]->EnemySprite.getPosition().y > -5)
                          ene[i]->bombing(timer);
                  }
              //}
              if (!rotate) {
                  p->speed = 0.2;
                  p->tex.loadFromFile("img/player_ship.png");
                  p->sprite.setTexture(p->tex);
                  p->sprite.setScale(0.75, 0.75);
              }

              window.clear(Color::Black); //clears the screen
              window.draw(background); // setting background
              window.draw(p->sprite);
              for (int i = 0; i < 100; i++) {
                  window.draw(p->f[i].bulletsprite);
              }
              //if (DragonShow == 0 && MonsterShow == 0) {

                  // setting player on screen
                  for (int i = 0; i < 20; i++) {
                      window.draw(ene[i]->EnemySprite);
                      window.draw(ene[i]->b->bombsprite);
                  }
             // }
              /*if (DragonShow == 1) {
                  for (int i = 0; i < 100; i++) {
                      window.draw(d->b[i].bombsprite);
                  }
              }*/
              /*if (MonsterShow == 1) {
                  for (int i = 0; i < 100; i++) {
                      window.draw(m->b[i].bombsprite);
                  }
              }*/
              //window.draw(d->EnemySprite);
              //window.draw(m->EnemySprite);
              window.draw(a[0]->AddonsSprite);
              window.draw(a[1]->AddonsSprite);
              window.draw(a[2]->AddonsSprite);
              window.display(); //Displying all the sprites
          }

      }
};
#pragma once
