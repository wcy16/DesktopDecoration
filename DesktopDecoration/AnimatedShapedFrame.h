#pragma once
#include <wx/wx.h>
#include <wx/animate.h>
#include <wx/bitmap.h>
#include "MovingShapedFrame.h"

class AnimatedShapedFrame : public MovingShapedFrame
{
public:
    AnimatedShapedFrame(wxWindow* parent, 
        wxString gif_path= global_params["ANIMATED_SHAPED_FRAME_DEFAULT_GIF"],
        wxColor background = wxColor(252, 254, 252),
        wxString shape_path = global_params["ANIMATED_SHAPED_FRAME_DEFAULT_PIC"]);

    //virtual void DoubleClick();

private:
};

class TransparentAnimationCtrl : public wxAnimationCtrl
{
public:
    TransparentAnimationCtrl(AnimatedShapedFrame* parent, wxColor background) : wxAnimationCtrl(parent, -1)
    {
        Connect(wxEVT_PAINT, wxPaintEventHandler(TransparentAnimationCtrl::OnPaint));
        Connect(wxEVT_TIMER, wxTimerEventHandler(TransparentAnimationCtrl::OnTimer));
        //Connect(wxEVT_RIGHT_UP, wxMouseEventHandler(AnimatedShapedFrame::OnExit));
        
        this->parent = parent;
        //m_timer.SetOwner(this);
        bg = background;
    }

    void OnPaint(wxPaintEvent& event)
    {
        //parent->SetShape(wxRegion(GetAnimation().GetFrame(m_currentFrame), wxColor(171, 171, 171)));
        //parent->SetShape(wxRegion(m_backingStore, wxColor(171, 171, 171)));
        parent->SetShape(wxRegion(m_backingStore, bg));
        wxAnimationCtrl::OnPaint(event);
    }
    void OnTimer(wxTimerEvent& event) {
        wxAnimationCtrl::OnTimer(event);
        //parent->SetShape(wxRegion(m_backingStore, wxColor(171, 171, 171)));
        parent->SetShape(wxRegion(m_backingStore, bg));
        //wxMessageDialog * dial = new wxMessageDialog(NULL, _T("ShapedFrame double click"), _T("ShapedFrame"), wxOK);
        //dial->ShowModal();
        //parent->Refresh();
    }
private:
    wxFrame * parent;
    wxColor bg;   // background
};



