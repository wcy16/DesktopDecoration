#include "MovingShapedFrame.h"
#include "config.h"

MovingShapedFrame::MovingShapedFrame(wxWindow * parent, wxString shape_path)
    : ShapedFrame(shape_path, parent), timer(this, MOVING_SHAPED_FRAME_TIMER)
{
    Connect(MOVING_SHAPED_FRAME_TIMER, wxEVT_TIMER, wxTimerEventHandler(MovingShapedFrame::OnMove));
    //long tmp;
    //global_params["MOVING_SHAPED_FRAME_TIMER_VAR"].ToLong(&tmp);
    //interval = tmp;
    interval = wxAtoi(global_params["MOVING_SHAPED_FRAME_TIMER_VAR"]);  // load default interval
}

void MovingShapedFrame::Move(wxPoint from, wxPoint direction, int t, void(*callback)(MovingShapedFrame*))
{
    Show();
    SetPosition(from);
    this->callback = callback;

    this->direction = direction;
    timer_cnt = t;
    timer.Start(interval, true);
}

void MovingShapedFrame::OnMove(wxTimerEvent & event)
{
    wxPoint pos = GetPosition();
    pos += direction;
    SetPosition(pos);
    timer_cnt--;
    if (timer_cnt > 0)
        timer.Start(interval, true);
    else
        callback(this);
}

void MovingShapedFrame::SetInterval(unsigned int nInterval)
{
    interval = nInterval;
}
