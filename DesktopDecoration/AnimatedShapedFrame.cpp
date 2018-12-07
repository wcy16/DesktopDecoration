#include "AnimatedShapedFrame.h"
#include "wx/dcgraph.h"
#include "textFrame.h"
#include <wx/animate.h>

#include <fstream>
#include <string>
#include <vector>
#include <random> // std::default_random_engine
#include <chrono> // std::chrono::system_clock

AnimatedShapedFrame::AnimatedShapedFrame(wxWindow* parent, wxString gif_path, wxColor background, wxString shape_path)
    : MovingShapedFrame(parent, shape_path)
{
    //m_bmp = wxBitmap(wxT("trans.gif"), wxBITMAP_TYPE_GIF);
    TransparentAnimationCtrl* m_animationCtrl = new TransparentAnimationCtrl(this, background);
    //m_animationCtrl->Bind(wxEVT_RIGHT_UP, &ShapedFrame::OnExit, this);
    MouseBind(m_animationCtrl);
    if (m_animationCtrl->LoadFile(gif_path)) {
        m_animationCtrl->Play();
    }
    
    wxSizer *sz = new wxBoxSizer(wxVERTICAL);
    sz->Add(m_animationCtrl);
    SetSizer(sz);
    Fit();
    //Center();
    SetPosition(wxPoint(300, 350));
}
