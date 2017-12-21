#include "wall.h"



wall::wall()
{
	x1 = -30;
	y1 = -30;
	x2 = 100;
	y2 = 20;
	size = 1;
}

wall::wall(int _x1, int _x2, int _y1, int _y2)
{
	x1 = _x1;
	x2 = _x2;
	y1 = _y1;
	y2 = _y2;
}

void wall::draw()
{
	glLineWidth(size);
	glBegin(GL_LINES);
	glColor3f(1, 0.0, 1);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
}

wall::~wall()
{
}
