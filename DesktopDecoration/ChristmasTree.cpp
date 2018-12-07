#include "ChristmasTree.h"
#include <wx/aboutdlg.h>

ChristmasTree::ChristmasTree(wxWindow* parent)
    : AnimatedShapedFrame(parent, "res/Christmas.gif", wxColor(171, 171, 171))
{
    if (wxFile::Exists("res/play.mp3"))
    {
        music = new wxMediaCtrl();
        bool bOK = music->Create(this, ID_CHRISTMAS_MUSIC, wxEmptyString,
            wxDefaultPosition, wxDefaultSize, 0
            , wxMEDIABACKEND_WMP10);
        wxASSERT_MSG(bOK, wxT("Could not create media control!"));
        wxUnusedVar(bOK);
        music->Show(false);
        if (!music->Load("res/play.mp3"))
        {
            wxMessageBox(_T("0"), _T("load failed!"));
        }
        wxBeginBusyCursor();
    }

    long x = 300, y = 300;
    if (global_params.count(CHRISTMAS_TREE_POS_X))
        global_params["CHRISTMAS_TREE_POS_X"].ToLong(&x);
    if (global_params.count(CHRISTMAS_TREE_POS_Y))
        global_params["CHRISTMAS_TREE_POS_Y"].ToLong(&y);
    SetPosition(wxPoint(x, y));

    wxFont f = wxFont(_T("0;-60;0;0;0;700;0;0;0;0;3;2;1;66;Edwardian Script ITC"));
    std::string txt = "placeholder";
    letter = new CTtextFrame(txt, this, &f);
    letter->SetPosition(wxPoint(400, 120));

    menu = new wxMenu();
    menu->Append(new wxMenuItem(menu, ID_CHRISTMAS_PLAY, "Play", wxEmptyString,wxITEM_CHECK));
    menu->Append(new wxMenuItem(menu, wxID_ABOUT, "About"));
    menu->Append(new wxMenuItem(menu, wxID_EXIT, "Close"));

    Bind(wxEVT_MENU, &ChristmasTree::OnClose, this, wxID_EXIT);
    Bind(wxEVT_MENU, &ChristmasTree::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &ChristmasTree::OnPlay, this, ID_CHRISTMAS_PLAY);
    Bind(wxEVT_MEDIA_LOADED, &ChristmasTree::OnLoaded, this, ID_CHRISTMAS_MUSIC);
    Bind(wxEVT_MEDIA_FINISHED, &ChristmasTree::OnFinishedMusic, this, ID_CHRISTMAS_MUSIC);

}

void ChristmasTree::DoubleClick()
{
    letter->Show();
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
    if (music != NULL)
        music->Destroy();
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
}

void ChristmasTree::OnPlay(wxCommandEvent & event)
{
    if (music != NULL) {
        if (event.IsChecked())
            music->Play();
        else
            music->Stop();
    }
}

void ChristmasTree::OnLoaded(wxMediaEvent & event)
{
    wxEndBusyCursor();
}

void ChristmasTree::OnFinishedMusic(wxMediaEvent & event)
{
    music->Play();
}
