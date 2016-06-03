#pragma once
#include "stdafx.h"
#include <vector>

class Line
{
public:
	CPoint line[2];
	bool statu = false;
	std::vector<Line *> connect_lines;
	void draw_main(Gdiplus::Graphics* gp);
	Line(int x, int y);
	Line(CPoint point);
	Line();
	~Line();
};


