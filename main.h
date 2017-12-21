/*
	https://github.com/koraga/snake

	Game "snake"
	OpenGL(GLUT)/C++

	Copyright (c) 2017 Alexey Koryazhkin 
	
	alexey@koraga3.ru
	koraga3.ru
	t.me/koraga

*/
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