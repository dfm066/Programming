#include "Frame.h"

//(*InternalHeaders(Frame)
#include <wx/xrc/xmlres.h>
//*)

//(*IdInit(Frame)
//*)

BEGIN_EVENT_TABLE(Frame,wxFrame)
	//(*EventTable(Frame)
	//*)
END_EVENT_TABLE()

Frame::Frame(wxWindow* parent)
{
	//(*Initialize(Frame)
	wxXmlResource::Get()->LoadObject(this,parent,_T("Frame"),_T("wxFrame"));
	Gauge1 = (wxGauge*)FindWindow(XRCID("ID_GAUGE1"));
	AnimationCtrl2 = (wxAnimationCtrl*)FindWindow(XRCID("ID_ANIMATIONCTRL2"));

	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&Frame::OnClose);
	//*)
}

Frame::~Frame()
{
	//(*Destroy(Frame)
	//*)
}


void Frame::OnLinearRegulator1Changed(wxCommandEvent& event)
{
}

void Frame::OnToggleButton1Toggle(wxCommandEvent& event)
{
}

void Frame::OnClose(wxCloseEvent& event)
{
}
