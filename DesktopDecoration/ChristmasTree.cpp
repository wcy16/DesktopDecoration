#include "ChristmasTree.h"

ChristmasTree::ChristmasTree(wxWindow* parent)
	: AnimatedShapedFrame(parent, "res/Christmas.gif", wxColor(171, 171, 171))
{
	long x = 300, y = 300;
	if (global_params.count(CHRISTMAS_TREE_POS_X))
		global_params["CHRISTMAS_TREE_POS_X"].ToLong(&x);
	if (global_params.count(CHRISTMAS_TREE_POS_Y))
		global_params["CHRISTMAS_TREE_POS_Y"].ToLong(&y);
	SetPosition(wxPoint(x, y));
}

void ChristmasTree::DoubleClick()
{
	return;
	//auto flake = new Snowflake(this);
	int x = wxSystemSettings::GetMetric(wxSYS_SCREEN_X);  // 1920
	int y = wxSystemSettings::GetMetric(wxSYS_SCREEN_Y);  // 1080
	/*flake->Move(wxPoint(rand() % x, rand() % y), wxPoint(rand() % 100 - 50, rand() % 100 - 50), 10,
		[](MovingShapedFrame* f) { f->Close(); });*/
	for (int i = 0; i != 5; i++) {
		auto flake = new Snowflake(this);
		flake->Move(wxPoint(rand() % x, 0), wxPoint(rand() % 100 - 50, y / 70), 70,
			[](MovingShapedFrame* f) { f->Close(); });
	}
}

void ChristmasTree::LeftClick()
{
	int x = wxSystemSettings::GetMetric(wxSYS_SCREEN_X);  // 1920
	int y = wxSystemSettings::GetMetric(wxSYS_SCREEN_Y);  // 1080
	for (int i = 0; i != 5; i++) {
		auto flake = new Snowflake(this);
		flake->Move(wxPoint(rand() % x, 0), wxPoint(rand() % 100 - 50, y / 70), 70,
			[](MovingShapedFrame* f) { f->Close(); });
	}
}

void ChristmasTree::save_to_cfg()
{
	wxPoint p = GetPosition();
	global_params["CHRISTMAS_TREE_POS_X"] = wxString::Format(wxT("%i"), p.x);
	global_params["CHRISTMAS_TREE_POS_Y"] = wxString::Format(wxT("%i"), p.y);
}

Snowflake::Snowflake(wxWindow * parent)
	: MovingShapedFrame(parent, "res/snowflake.png")
{
}
