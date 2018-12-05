#include "ShapedFrame.h"
#include <wx/dcclient.h>
#include <wx/rawbmp.h>
#include <wx/msgdlg.h>
//#include "shapem.xpm"

CtrlFrame::CtrlFrame()
	: wxFrame(NULL, wxID_ANY, "surprise",
		wxDefaultPosition, wxSize(200, 100))
{
	
}

ShapedFrame::ShapedFrame(wxString shape_path, wxWindow *parent, wxPoint pos)
	: wxFrame(parent, wxID_ANY, wxEmptyString,
		pos, wxSize(100, 100),
		0
		| wxFRAME_SHAPED
		| wxSIMPLE_BORDER
		| wxFRAME_NO_TASKBAR
		| wxSTAY_ON_TOP
	)
{
	Connect(wxEVT_PAINT, wxPaintEventHandler(ShapedFrame::OnPaint));
	/*
	Connect(wxEVT_LEFT_DCLICK, wxMouseEventHandler(ShapedFrame::OnDoubleClick));
	Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(ShapedFrame::OnLeftDown));
	Connect(wxEVT_LEFT_UP, wxMouseEventHandler(ShapedFrame::OnLeftUp));
	Connect(wxEVT_MOTION, wxMouseEventHandler(ShapedFrame::OnMouseMove));
	Connect(wxEVT_RIGHT_UP, wxMouseEventHandler(ShapedFrame::OnExit));
	*/
	MouseBind(this);
	m_bmp = wxBitmap(shape_path, wxBITMAP_TYPE_PNG);
	//m_bmp = wxBitmap(shape_path, wxBITMAP_TYPE_PNG);
	//m_bmp = wxBitmap(shape_path, wxBITMAP_TYPE_GIF);
	AdjustBmp();
	//m_bmp = wxBitmap(shapem);
	SetSize(wxSize(m_bmp.GetWidth(), m_bmp.GetHeight()));
	SetToolTip(wxT("ÓÒ¼ü¹Ø±Õ"));
	SetWindowShape();
	//Show();
	//Center();

	is_leftclick = false;
}

void ShapedFrame::SetWindowShape()
{
	SetShape(wxRegion(m_bmp, *wxWHITE));
}

void ShapedFrame::OnDoubleClick(wxMouseEvent & evt)
{
	DoubleClick();
}

void ShapedFrame::OnLeftDown(wxMouseEvent& evt)
{
	CaptureMouse();
	wxPoint pos = ClientToScreen(evt.GetPosition());
	wxPoint origin = GetPosition();    // get the window's position
	int dx = pos.x - origin.x;
	int dy = pos.y - origin.y;
	m_delta = wxPoint(dx, dy);
	is_leftclick = true;

	m_pos = evt.GetPosition();
}

void ShapedFrame::OnMouseMove(wxMouseEvent& evt)
{
	if (HasCapture() && evt.LeftIsDown())
	{
		wxPoint pt = evt.GetPosition();
		if (pt != m_pos)   // dragged
		{
			wxPoint pos = ClientToScreen(pt);
			Move(wxPoint(pos.x - m_delta.x, pos.y - m_delta.y));

			is_leftclick = false;  // left not click, left drag
		}
	}

	// using evt.Dragging() may cause misjudge for animated shape frame
	//wxPoint pt = evt.GetPosition();
	//if (evt.Dragging() && evt.LeftIsDown())
	//{
	//	wxPoint pos = ClientToScreen(pt);

	//	Move(wxPoint(pos.x - m_delta.x, pos.y - m_delta.y));

	//	is_leftclick = false;  // left not click, left drag
	//}
}

void ShapedFrame::OnExit(wxMouseEvent& WXUNUSED(evt))
{
	save_to_cfg();

	Close();
}

void ShapedFrame::OnLeftUp(wxMouseEvent& WXUNUSED(evt))
{
	if (HasCapture())
	{
		ReleaseMouse();
		
		if (is_leftclick)
			LeftClick();
	}
	is_leftclick = false;
}

void ShapedFrame::OnPaint(wxPaintEvent& WXUNUSED(evt))
{
	wxPaintDC dc(this);
	dc.DrawBitmap(m_bmp, 0, 0, true);
}

void ShapedFrame::DoubleClick()
{
	wxMessageDialog * dial = new wxMessageDialog(NULL, _T("ShapedFrame double click"), _T("ShapedFrame"), wxOK);

	dial->ShowModal();
}

void ShapedFrame::LeftClick()
{
	wxMessageDialog * dial = new wxMessageDialog(NULL, _T("ShapedFrame left click"), _T("ShapedFrame"), wxOK);

	dial->ShowModal();
}

void ShapedFrame::save_to_cfg()
{
}

void ShapedFrame::AdjustBmp()
{
	if (modification == false)
		return;
	wxNativePixelData data(m_bmp);
	wxNativePixelData::Iterator p(data);
	/*
	int pixels = data.GetWidth() * data.GetHeight();
	volatile int i;
	for (i = 0; i != pixels && p.IsOk(); i++, p++) {
		if (p.Red() > r_threshold && p.Green() > g_threshold && p.Blue() > b_threshold) {
			p.Red() = 255;
			p.Green() = 255;
			p.Blue() = 255;
		}
	}*/
	for (int y = 0; y < data.GetHeight(); ++y)
	{
		wxNativePixelData::Iterator rowStart = p;
		for (int x = 0; x < data.GetWidth(); ++x, ++p)
		{
			if (p.Red() > r_threshold && p.Green() > g_threshold && p.Blue() > b_threshold) {
				p.Red() = 255;
				p.Green() = 255;
				p.Blue() = 255;
			}
		}
		p = rowStart;
		p.OffsetY(data, 1);
	}
}

void ShapedFrame::MouseBind(wxEvtHandler * p)
{
	p->Bind(wxEVT_LEFT_DCLICK, &ShapedFrame::OnDoubleClick, this);
	p->Bind(wxEVT_LEFT_DOWN, &ShapedFrame::OnLeftDown, this);
	p->Bind(wxEVT_LEFT_UP, &ShapedFrame::OnLeftUp, this);
	p->Bind(wxEVT_MOTION, &ShapedFrame::OnMouseMove, this);
	p->Bind(wxEVT_RIGHT_UP, &ShapedFrame::OnExit, this);
}



