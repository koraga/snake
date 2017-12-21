#pragma once
class game
{
public:
	float delay;
	int _size_eat, _size_snake;
	int winWidth, winHeight;
	int posWinWidth, posWinHeight;
	int posStartX, posStartY;
	int sizeBlock;
	bool onWalls;
	game();
	~game();
};

