#include "ChristmasTree.h"
#include <wx/aboutdlg.h>

ChristmasTree::ChristmasTree(wxWindow* parent)
	: AnimatedShapedFrame(parent, "res/Christmas.gif", wxColor(171, 171, 171))
{
	long x = 300, y = 300;
	if (global_params.count(CHRISTMAS_TREE_POS_X))
		global_params["CHRISTMAS_TREE_POS_X"].ToLong(&x);
	if (global_params.count(CHRISTMAS_TREE_POS_Y))
		global_params["CHRISTMAS_TREE_POS_Y"].ToLong(&y);
	SetPosition(wxPoint(x, y));

	menu = new wxMenu();
	menu->Append(new wxMenuItem(menu, wxID_ABOUT, "About"));
	menu->Append(new wxMenuItem(menu, wxID_EXIT, "Close"));

	Bind(wxEVT_MENU, &ChristmasTree::OnClose, this, wxID_EXIT);
	Bind(wxEVT_MENU, &ChristmasTree::OnAbout, this, wxID_ABOUT);
}

void ChristmasTree::DoubleClick()
{
	wxMessageDialog * dial = new wxMessageDialog(NULL, _T("ChristmasTree double click"), _T("ShapedFrame"), wxOK);

	dial->ShowModal();

	return;
	//auto flake = new Snowflake(this);
	//int x = wxSystemSettings::GetMetric(wxSYS_SCREEN_X);  // 1920
	//int y = wxSystemSettings::GetMetric(wxSYS_SCREEN_Y);  // 1080
	///*flake->Move(wxPoint(rand() % x, rand() % y), wxPoint(rand() % 100 - 50, rand() % 100 - 50), 10,
	//	[](MovingShapedFrame* f) { f->Close(); });*/
	//for (int i = 0; i != 5; i++) {
	//	auto flake = new Snowflake(this);
	//	flake->Move(wxPoint(rand() % x, 0), wxPoint(rand() % 100 - 50, y / 70), 70,
	//		[](MovingShapedFrame* f) { f->Close(); });
	//}
}

void ChristmasTree::LeftClick()
{
	int x = wxSystemSettings::GetMetric(wxSYS_SCREEN_X);  // 1920
	int y = wxSystemSettings::GetMetric(wxSYS_SCREEN_Y);  // 1080
	for (int i = 0; i != 5; i++) {
		auto flake = new MovingShapedFrame(this, "res/snowflake.png");
		flake->Move(wxPoint(rand() % x, 0), wxPoint(rand() % 50 - 25, y / 70), 70,
			[](MovingShapedFrame* f) { f->Close(); });
	}
}

void ChristmasTree::RightClick()
{
	PopupMenu(menu);
}

void ChristmasTree::save_to_cfg()
{
	wxPoint p = GetPosition();
	global_params["CHRISTMAS_TREE_POS_X"] = wxString::Format(wxT("%i"), p.x);
	global_params["CHRISTMAS_TREE_POS_Y"] = wxString::Format(wxT("%i"), p.y);
}

void ChristmasTree::OnClose(wxCommandEvent & event)
{
	Close();
}

void ChristmasTree::OnAbout(wxCommandEvent & event)
{
	wxIcon icon("res/about.png", wxBITMAP_TYPE_PNG);

	wxAboutDialogInfo info;
    info.SetName(_("ChristmasTree"));
    info.SetVersion(_("0.1"));
	info.SetDescription(_("This program is built for."));
	info.SetIcon(icon);
	wxAboutBox(info);

	//wxInfoMessageBox(this);

	/*wxMessageDialog * dial = new wxMessageDialog(NULL, _T("Test"), _T("Test"));

	
	if (icon.IsOk())
	{
		wxMessageDialog * d = new wxMessageDialog(NULL, _T("OK"), _T("OK"));
		d->ShowModal();
	}
	dial->SetIcon(icon);

	dial->ShowModal();*/
}
