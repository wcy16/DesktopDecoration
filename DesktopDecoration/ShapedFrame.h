#pragma once
#include <wx/frame.h>
#include <wx/bitmap.h>
#include "config.h"

class CtrlFrame : public wxFrame
{
public:
	CtrlFrame();
};

class ShapedFrame : public wxFrame
{
public:
	ShapedFrame(wxString shape_path, wxWindow *parent = NULL, wxPoint pos = wxDefaultPosition);
	void SetWindowShape();

	// event handlers (these functions should _not_ be virtual)
	void OnDoubleClick(wxMouseEvent& evt);
	void OnLeftDown(wxMouseEvent& evt);
	void OnLeftUp(wxMouseEvent& evt);
	void OnMouseMove(wxMouseEvent& evt);
	void OnExit(wxMouseEvent& evt);
	void OnPaint(wxPaintEvent& evt);

	virtual void DoubleClick();
	virtual void LeftClick();

	void AdjustBmp();

protected:
	wxBitmap m_bmp;
	void MouseBind(wxEvtHandler* p);

private:
	wxPoint  m_delta;
	wxPoint m_pos;   // tmp pos for mouse event
	bool is_leftclick;   // judge if left is clicked

	// do modification to the bitmap
	bool modification=false;
	int r_threshold=245;
	int g_threshold=245;
	int b_threshold=245;

};
