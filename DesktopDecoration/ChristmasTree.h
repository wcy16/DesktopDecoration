#pragma once
#include "AnimatedShapedFrame.h"

/*
  a christmas tree decoration
*/

class ChristmasTree : public AnimatedShapedFrame
{
public:
	ChristmasTree(wxWindow* parent);
	virtual void DoubleClick();
};
