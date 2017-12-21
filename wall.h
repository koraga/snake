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
class wall
{
public:
	int x1, x2, y1, y2;
	float size;
	wall();
	wall(int _x1, int _x2, int _y1, int _y2);
	void draw();
	~wall();
};

