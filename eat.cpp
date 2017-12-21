/*
	https://github.com/koraga/snake

	Game "snake"
	OpenGL(GLUT)/C++

	Copyright (c) 2017 Alexey Koryazhkin 
	
	alexey@koraga3.ru
	koraga3.ru
	t.me/koraga

*/
#include "eat.h"

std::default_random_engine pos;

eat::eat(float _size, int sizWW, int sizWH, int sizBL)
{
	pos.seed(std::random_device()());
	ranX = sizWW / 2 / sizBL - 1;
	ranY = sizWH / 2 / sizBL - 1;
	std::uniform_int_distribution<int> regX(-ranX, ranX);
	std::uniform_int_distribution<int> regY(-ranY,ranY);
	x = regX(pos) * sizBL;
	y = regY(pos) * sizBL;
	size = _size;
	sizeBlock = sizBL;
}

bool eat::om(int _x, int _y)
{
	if (x == _x && y == _y)
	{
		reset();
		return true;
	}
	return false;
}

void eat::reset()
{
	pos.seed(std::random_device()());
	std::uniform_int_distribution<int> regX(-ranX, ranX);
	std::uniform_int_distribution<int> regY(-ranY, ranY);
	x = regX(pos) * sizeBlock;
	y = regY(pos) * sizeBlock;
}

void eat::draw()
{
	glPointSize(size);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_POINTS);
	glColor3f(0.90, 0.40, 0);
	glVertex2f(x, y);
	glEnd();
	glDisable(GL_BLEND);
	glDisable(GL_POINT_SMOOTH);
}

eat::~eat()
{
}
