/*
	https://github.com/koraga/snake

	Game "snake"
	OpenGL(GLUT)/C++

	Copyright (c) 2017 Alexey Koryazhkin 
	
	alexey@koraga3.ru
	koraga3.ru
	t.me/koraga

*/
#include "main.h"

using namespace std;
/*default settings*/
game settings;
eat eatSnake(10.0, settings.winWidth, settings.winHeight, settings.sizeBlock);
vector<wall> walls;
vector<snake> snakeT;

bool ifRoute, ifSpeed = false;
int kSpeed = 0;
int delayPlayer;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	eatSnake.draw();
	for (vector<wall>::iterator i = walls.begin(); i != walls.end(); i++)
		i->draw();
	for (vector<snake>::iterator i = snakeT.begin(); i != snakeT.end(); i++)
	{
		if (i == snakeT.begin())
			i->draw(settings._size_snake + 3, 1);
		else
			i->draw(settings._size_snake, 1);
	}
	glutSwapBuffers();
}

void tail()
{
	if (snakeT.size() > 1)
	{
		for (vector<snake>::iterator ip = snakeT.end(); (ip - 1) != snakeT.begin();)
		{
			ip--;
			ip->x = (ip - 1)->x;
			ip->y = (ip - 1)->y;
		}
	}
}

void brkRegion()
{
	if (snakeT.front().x == settings.winWidth / 2)
	{
		snakeT.front().x = -settings.winWidth / 2 + settings.sizeBlock;
		return;
	}
	if (snakeT.front().x == -settings.winWidth / 2)
	{
		snakeT.front().x = settings.winWidth / 2 - settings.sizeBlock;
		return;
	}
	if (snakeT.front().y == settings.winHeight / 2)
	{
		snakeT.front().y = -settings.winHeight / 2 + settings.sizeBlock;
		return;
	}
	if (snakeT.front().y == -settings.winHeight / 2)
	{
		snakeT.front().y = settings.winHeight / 2 - settings.sizeBlock;
		return;
	}
}

void deathAWall()
{
	if (snakeT.front().x == settings.winWidth / 2 || snakeT.front().x == -settings.winWidth / 2 || snakeT.front().y == settings.winHeight / 2 || snakeT.front().y == -settings.winHeight / 2)
	{
		snakeT.clear();
		snake head(settings.posStartX, settings.posStartY);
		snakeT.push_back(head);
		eatSnake.reset();
	}
}

void eatOmSnake()
{
	if (eatSnake.om(snakeT.front().x, snakeT.front().y))
	{
		snake addTail(snakeT.back().x, snakeT.back().y);
		snakeT.push_back(addTail);
	}
}

void tailOmSnake()
{
	if (snakeT.size() > 3)
	{
		for (int i = 2; i < snakeT.size(); i++)
			if (snakeT[0].x == snakeT[i].x && snakeT[0].y == snakeT[i].y)
			{
				for (int j = snakeT.size() - i; j < snakeT.size(); j++)
					snakeT.pop_back();
				return;
			}
	}
}

void timer(int)
{
	ifRoute = true;
	tail();
	eatOmSnake(); 
	tailOmSnake();
	if (!settings.onWalls)
		brkRegion();
	else
		deathAWall();
	if (ifSpeed && kSpeed < 5)
		kSpeed++;
	else
	{
		settings.delay = delayPlayer;
		kSpeed = 0;
		ifSpeed = false;
	}
	if (snakeT.front().getN() == "-x")
		snakeT.front().x -= 10;
	if (snakeT.front().getN() == "+x")
		snakeT.front().x += 10;
	if (snakeT.front().getN() == "-y")
		snakeT.front().y -= 10;
	if (snakeT.front().getN() == "+y")
		snakeT.front().y += 10;
	glutPostRedisplay();
	glutTimerFunc(settings.delay, timer, 0);
}

void sKeyboard(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		if (snakeT.front().getN() == "-x" && !ifSpeed)
		{
			settings.delay = delayPlayer / 4;
			ifSpeed = true;
			break;
		}
		if (!(snakeT.front().getN() == "+x") && ifRoute)
			snakeT.front().setN("-x");
		break;
	case GLUT_KEY_RIGHT:
		if (snakeT.front().getN() == "+x" && !ifSpeed)
		{
			settings.delay = delayPlayer / 4;
			ifSpeed = true;
			break;
		}
		if (!(snakeT.front().getN() == "-x") && ifRoute)
			snakeT.front().setN("+x");
		break;
	case GLUT_KEY_UP:
		if (snakeT.front().getN() == "+y" && !ifSpeed)
		{
			settings.delay = delayPlayer / 4;
			ifSpeed = true;
			break;
		}
		if (!(snakeT.front().getN() == "-y") && ifRoute)
			snakeT.front().setN("+y");
		break;
	case GLUT_KEY_DOWN:
		if (snakeT.front().getN() == "-y" && !ifSpeed)
		{
			settings.delay = delayPlayer / 4;
			ifSpeed = true;
			break;
		}
		if (!(snakeT.front().getN() == "+y") && ifRoute)
			snakeT.front().setN("-y");
		break;
	}
	ifRoute = false;
}
void initialize()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-settings.winWidth / 2, settings.winWidth / 2, 
		-settings.winHeight / 2, settings.winHeight / 2, 
		-5.0, 5.0);
	glMatrixMode(GL_MODELVIEW);
}

void start()
{
	cout << "Enter speed(max - infinity, min - 10, default - 100) : ";
	cin >> delayPlayer;
	if(delayPlayer < 10)
		delayPlayer = 100;
	settings.delay = delayPlayer;
	while (1)
	{
		cout << "Enter game mode (walls - 1 or without walls - 0) :";
		int ch;
		cin >> ch;
		if (ch == 1 || ch == 0)
		{
			if (ch == 1)
				settings.onWalls = true;
			else
				settings.onWalls = false;
			break;
		}
		system("cls");
	}
	snake head(settings.posStartX, settings.posStartY);
	snakeT.push_back(head);
	if(settings.onWalls)
		wallFunc();
}

void wallFunc()
{
	wall w0(-250, -250, -250, 250);
	wall w1(-250, 250, -250, -250);
	wall w2(250, -250, 250, 250);
	wall w3(250, 250, -250, 250);
	w0.size = w1.size = w2.size = w3.size = settings.sizeBlock;
	walls.push_back(w0);
	walls.push_back(w1);
	walls.push_back(w2);
	walls.push_back(w3);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(settings.winWidth, settings.winHeight);
	glutInitWindowPosition(settings.posWinWidth, settings.posWinHeight);
	glutCreateWindow("Snake 1.1");
	glutTimerFunc(settings.delay, timer, 0);
	glutDisplayFunc(display);
	glutSpecialFunc(sKeyboard);
	start();
	initialize();
	glutMainLoop();
	return 0;
}