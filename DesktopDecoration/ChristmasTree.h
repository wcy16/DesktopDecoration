#pragma once
#include "AnimatedShapedFrame.h"

/*
  a christmas tree decoration
*/

#define CHRISTMAS_TREE_POS_X "CHRISTMAS_TREE_POS_X"
#define CHRISTMAS_TREE_POS_Y "CHRISTMAS_TREE_POS_Y"

class ChristmasTree : public AnimatedShapedFrame
{
public:
	ChristmasTree(wxWindow* parent);
	virtual void DoubleClick();
	virtual void LeftClick();
	virtual void save_to_cfg();
};

class Snowflake : public MovingShapedFrame
{
public:
	Snowflake(wxWindow* parent);

};