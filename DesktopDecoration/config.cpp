#include "config.h"

std::map<wxString, wxString> global_params = std::map<wxString, wxString>();

void default_cfg() {
	global_params["MOVING_SHAPED_FRAME_TIMER_VAR"] = "100";
	global_params["DECORATE_DEFAULT_PIC"] = wxT("res/shape.png");
	global_params["MOVING_SHAPED_FRAME_DEFAULT_PIC"] = wxT("res/shape.png");
	global_params["ANIMATED_SHAPED_FRAME_DEFAULT_PIC"] = wxT("res/minshape.png");
	global_params["FRAME_POSITION_X"] = "100";
	global_params["FRAME_POSITION_Y"] = "100";
}

void save_cfg() {
	// save ini file
	wxFileConfig* cfg = new wxFileConfig(wxEmptyString, wxEmptyString,
		wxEmptyString, wxEmptyString, wxCONFIG_USE_RELATIVE_PATH);
	//cfg->Write("count", prizes.size());
	for (auto i = global_params.begin(); i != global_params.end(); i++) {
		cfg->Write("/" + i->first, i->second);
		//cfg->Write(GLOBAL_PARAMS + "/" + i->first, i->second);
	}
	wxFileOutputStream ostream(CONFIG_FILE);
	cfg->Save(ostream);
	delete cfg;
}

void load_cfg() {
	wxFileConfig* cfg = new wxFileConfig(wxEmptyString, wxEmptyString,
		CONFIG_FILE, wxEmptyString, wxCONFIG_USE_RELATIVE_PATH);

	long cfg_index;
	wxString k, v;

	if (cfg->GetFirstEntry(k, cfg_index)) {
		cfg->Read(k, &v);
		global_params[k] = v;
		while (cfg->GetNextEntry(k, cfg_index)) {
			cfg->Read(k, &v);
			global_params[k] = v;
		}
	}

	delete cfg;
}

