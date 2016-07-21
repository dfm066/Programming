#ifndef FRAME_H
#define FRAME_H

//(*Headers(Frame)
#include <wx/animate.h>
#include <wx/frame.h>
#include <wx/gauge.h>
//*)

class Frame: public wxFrame
{
	public:

		Frame(wxWindow* parent);
		virtual ~Frame();

		//(*Declarations(Frame)
		wxGauge* Gauge1;
		wxAnimationCtrl* AnimationCtrl2;
		//*)

	protected:

		//(*Identifiers(Frame)
		//*)

	private:

		//(*Handlers(Frame)
		void OnLinearRegulator1Changed(wxCommandEvent& event);
		void OnToggleButton1Toggle(wxCommandEvent& event);
		void OnClose(wxCloseEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
