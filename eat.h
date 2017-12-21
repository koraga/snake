#pragma once
#include "glut.h"
#include <random>

class eat
{
public:
	int x, y;
	int ranX, ranY;
	int sizeBlock;
	float size;
	eat(float _size,int sizWW,int sizWH,int sizBL);
	bool om(int _x, int _y);
	void reset();
	void draw();
	~eat();
};

