#include "stdafx.h"
#include "Line.h"

Line::Line(int x, int y)
{
	this->line[0] = CPoint(x, y);
	this->line[1] = CPoint(x, y);
}

Line::Line(CPoint point)
{
	this->line[0] = point;
	this->line[1] = point;
	
}


Line::~Line()
{
}


void draw_main(Gdiplus::Graphics* gp)
{
	Gdiplus::Pen *p;
	p = new Gdiplus::Pen(Gdiplus::Color(0, 0, 0), 3);
	Gdiplus::Point drw_line[2];
	gp->DrawLines(p, drw_line, 2);
}