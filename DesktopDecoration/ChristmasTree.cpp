#include "ChristmasTree.h"

ChristmasTree::ChristmasTree(wxWindow* parent)
	: AnimatedShapedFrame(parent, "res/Christmas.gif", wxColor(171, 171, 171))
{

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

Snowflake::Snowflake(wxWindow * parent)
	: MovingShapedFrame(parent, "res/snowflake.png")
{
}
