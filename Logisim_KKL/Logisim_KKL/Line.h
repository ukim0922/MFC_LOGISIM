#pragma once
#include "stdafx.h"
#include <vector>

class Line
{
public:
	CPoint start_pt, desti_pt;
	CRect rect;
	bool statu = false;
	void setLineRect();
	Line();
	~Line();
};


