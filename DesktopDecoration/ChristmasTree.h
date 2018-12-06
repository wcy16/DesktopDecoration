#pragma once
#include "AnimatedShapedFrame.h"

/*
  a christmas tree decoration
*/

#define CHRISTMAS_TREE_POS_X "CHRISTMAS_TREE_POS_X"
#define CHRISTMAS_TREE_POS_Y "CHRISTMAS_TREE_POS_Y"

class ChristmasTree : public AnimatedShapedFrame
{
	wxMenu* menu;
public:
	ChristmasTree(wxWindow* parent);
	virtual void DoubleClick();
	virtual void LeftClick();
	virtual void RightClick();

	virtual void save_to_cfg();

	void OnClose(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
};