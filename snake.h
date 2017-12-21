#pragma once
#include "glut.h"
class snake
{
public:
	int x, y;
	int sX, sY;
	char* snakeRoute;
	snake(int _x, int _y);
	void draw(float _size,bool color);
	void setN(char* c);
	char* getN();
	void death();
	~snake();
};

