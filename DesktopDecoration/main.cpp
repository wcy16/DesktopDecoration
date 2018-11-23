#include <wx/wx.h>
#include "MovingShapedFrame.h"
#include "AnimatedShapedFrame.h"
#include "textFrame.h"

class Decorate : public wxApp
{
public:
	virtual bool OnInit();
	~Decorate();
};

IMPLEMENT_APP(Decorate)

bool Decorate::OnInit()
{
	if (!wxApp::OnInit())
		return false;
	default_cfg();
	load_cfg();
	//save_cfg();

	wxInitAllImageHandlers();

	//CustomShapedFrame* d = new CustomShapedFrame(NULL);
	//d->Show();
	
	auto t = new AnimatedShapedFrame(NULL);
	t->Show();

	wxFont f = wxFont(_T("0;-80;0;0;0;700;0;0;0;134;3;2;1;34;Î¢ÈíÑÅºÚ"));
	auto t2 = new textFrame("version 1", NULL, &f);
	t2->SetPosition(wxPoint(400, 620));
	t2->Show();
	
	//MovingShapedFrame* f = new MovingShapedFrame(NULL);
	//f->Move(wxPoint(100, 100), wxPoint(10, 10), 10, true);

	return true;
}

Decorate::~Decorate()
{
	save_cfg();
}


