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

