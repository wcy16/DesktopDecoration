#pragma once
#include "ShapedFrame.h"
#include <wx/timer.h>

class MovingShapedFrame : public ShapedFrame
{
public:
    MovingShapedFrame(wxWindow* parent, wxString shape_path = global_params["MOVING_SHAPED_FRAME_DEFAULT_PIC"]);
    void Move(wxPoint from, wxPoint direction, int t, void (*callback)(MovingShapedFrame*));
    void OnMove(wxTimerEvent& event);
    void SetInterval(unsigned int nInterval);

    // event

private:
    wxTimer timer;
    unsigned int interval;
    
    wxPoint direction;
    int timer_cnt;

    void(*callback)(MovingShapedFrame*);
};


