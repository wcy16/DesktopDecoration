#pragma once
#include <wx/string.h>
#include <wx/fileconf.h>
#include <wx/wfstream.h>
#include <map>

enum {
	EVENT_ID_START = 100,
	MOVING_SHAPED_FRAME_TIMER,
	ANIMATED_SHAPED_FRAME_TIMER,
};

extern std::map<wxString, wxString> global_params;

const wxString CONFIG_FILE = "config.ini";
const wxString GLOBAL_PARAMS = "Global Params";

const int MOVING_SHAPED_FRAME_TIMER_VAR = 500;
const wxString SHAPED_FRAME_DEFAULT_PIC = wxT("shape.png");
const wxString MOVING_SHAPED_FRAME_DEFAULT_PIC = wxT("shape.png");

void default_cfg();

void save_cfg();

void load_cfg();
