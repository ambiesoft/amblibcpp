
#include "stdafx.h"
#include "Form1.h"

using namespace amblibcppTest;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	Ambiesoft::CppUtils::CopyFile(L"Y:\\T\\*.zip",L"Y:\\T\\aaa\\");
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	Application::Run(gcnew Form1());
	return 0;
}
