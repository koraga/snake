/*
	https://github.com/koraga/snake

	Game "snake"
	OpenGL(GLUT)/C++

	Copyright (c) 2017 Alexey Koryazhkin 
	
	alexey@koraga3.ru
	koraga3.ru
	t.me/koraga

*/
#include "snake.h"



snake::snake(int _x, int _y)
{
	x = sX = _x;
	y = sY =_y;
	snakeRoute = "NULL";
}

void snake::draw(float _size,bool color)
{
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPointSize(_size);
	glBegin(GL_POINTS);
	if (color)
		glColor3f(0.2, 1.0, 0.2);
	else
		glColor3f(0.0, 0.0, 0.0);
	glVertex2f(x, y);
	glEnd();
	glDisable(GL_BLEND);
	glDisable(GL_POINT_SMOOTH);
}

void snake::setN(char* c)
{
	if (c == "+x" || c == "-x" || c == "+y" || c == "-y")
		snakeRoute = c;
	else
		snakeRoute = "NULL";
}

char* snake::getN()
{
	return snakeRoute;
}

void snake::death()
{
	x = sX;
	y = sY;
	snakeRoute = "NULL";
}

snake::~snake()
{
}
