#include "stdafx.h"
#include "Line.h"

void Line::setLineRect()
{
	rect.SetRect(start_pt.x - 5, start_pt.y - 5, desti_pt.x + 10, desti_pt.y + 10);
}
Line::Line()
{
	
}
Line::~Line()
{
}

