// Shadow Datafile Manager.cpp : main project file.

#include "stdafx.h"
#include "FormMain.h"

using namespace ShadowDatafileManager;

[STAThreadAttribute]
int __clrcall main(array<System::String ^> ^args)
{
	SCF_UNREFERENCED_PARAMETER(args);

	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew FormMain());
	return 0;
}
