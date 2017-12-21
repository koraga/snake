/*
	https://github.com/koraga/snake

	Game "snake"
	OpenGL(GLUT)/C++

	Copyright (c) 2017 Alexey Koryazhkin 
	
	alexey@koraga3.ru
	koraga3.ru
	t.me/koraga

*/
#include "game.h"



game::game()
{
	delay = 100.0;
	_size_eat = 8;
	_size_snake = 10;
	winWidth = winHeight = 500;
	posWinWidth = posWinHeight = 50;
	posStartX = posStartY = 0;
	sizeBlock = 10;
	onWalls = true;
}


game::~game()
{
}
