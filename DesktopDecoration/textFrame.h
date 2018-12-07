#pragma once
#include "ShapedFrame.h"
#include <wx/dcmemory.h>

class textFrame : public ShapedFrame
{
public:
    textFrame(std::string text, wxWindow* parent, wxFont *font=NULL) 
        : ShapedFrame(global_params["DECORATE_DEFAULT_PIC"], parent)
    {
        wxBitmap mybm(1000, 500);
        if (mybm.IsOk())
        {
            // Create a memory DC
            wxMemoryDC memdc;
            // select bitmap we just loaded
            memdc.SelectObject(mybm);

            // Draw into the memory DC...
            // e.g.
            memdc.SetPen(wxColor(255, 255, 255));
            memdc.SetBrush(wxColor(255, 255, 255));
            memdc.DrawRectangle(0, 0, 1000, 500);
            memdc.SetPen(wxColor(255, 0, 0));
            memdc.SetBrush(wxColor(255, 0, 0));
            if (font == NULL)
                memdc.SetFont(wxFont(_T("0;-80;0;0;0;400;0;0;0;134;3;2;1;34;Î¢ÈíÑÅºÚ")));
            else
                memdc.SetFont(*font);
            memdc.DrawText(text, wxPoint(0, 0));

            // write changes to disk...
            memdc.SelectObject(wxNullBitmap);
            //mybm.SaveFile(wxT("NewFile.bmp"), wxBITMAP_TYPE_BMP);

            m_bmp = mybm;
            //m_bmp.SaveFile(wxT("NewFile.bmp"), wxBITMAP_TYPE_BMP);
            SetSize(wxSize(m_bmp.GetWidth(), m_bmp.GetHeight()));
            SetWindowShape();
        }

    }

    virtual void DoubleClick()
    {
        //MovingShapedFrame* mframe = new MovingShapedFrame(this);
        AnimatedShapedFrame* mframe = new AnimatedShapedFrame(this);
        int x = wxSystemSettings::GetMetric(wxSYS_SCREEN_X);
        int y = wxSystemSettings::GetMetric(wxSYS_SCREEN_Y);
        mframe->Move(wxPoint(rand() % x, rand() % y), wxPoint(rand() % 100 - 50, rand() % 100 - 50), 10,
            [](MovingShapedFrame* f) { f->Close(); });
    }
};
