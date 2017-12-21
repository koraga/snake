#pragma once
#include "glut.h"
#include "game.h"
#include "snake.h"
#include "eat.h"
#include "wall.h"

#include <vector>
#include <iostream>

void display();
void timer(int);
void sKeyboard(int key, int x, int y);
void initialize();
void start();
void wallFunc();
void tail();
void eatOmSnake();
void brkRegion();
void deathAWall();