#pragma once
#include <wx/mediactrl.h>
#include "AnimatedShapedFrame.h"
#include "textFrame.h"

/*
  a christmas tree decoration
*/

#define CHRISTMAS_TREE_POS_X "CHRISTMAS_TREE_POS_X"
#define CHRISTMAS_TREE_POS_Y "CHRISTMAS_TREE_POS_Y"

class CTtextFrame;

class ChristmasTree : public AnimatedShapedFrame
{
    wxMenu* menu;
    CTtextFrame* letter;
    wxMediaCtrl* music;
    bool music_ready;
public:
    ChristmasTree(wxWindow* parent);
    virtual void DoubleClick();
    virtual void LeftClick();
    virtual void RightClick();

    virtual void save_to_cfg();

    void OnClose(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnPlay(wxCommandEvent& event);

    void OnLoaded(wxMediaEvent& event);
    void OnFinishedMusic(wxMediaEvent& event);
};

/*
  text frame for christmas tree
*/
class CTtextFrame : public textFrame
{
public:
    CTtextFrame(std::string text, wxWindow* parent, wxFont *font) 
        : textFrame(text, parent, font) {}

    virtual void RightClick() { Show(false); }
};
