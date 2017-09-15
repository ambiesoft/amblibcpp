
#include "stdafx.h"
#include "Form1.h"

using namespace amblibcppTest;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	{
		array<unsigned char>^ zaa;
		if (Ambiesoft::CppUtils::ReadAlternate(L"C:\\T\\magic", L"alt", zaa))
		{
			String^ ttt = System::Text::Encoding::UTF8->GetString(zaa);
		}

	}
	String^ aaa = "aaa";
	array<unsigned char>^ baaa = System::Text::Encoding::UTF8->GetBytes(aaa);

	System::Diagnostics::Debug::Assert(
		Ambiesoft::CppUtils::WriteAlternate(L"C:\\T\\magic", L"alt", baaa)
	);

	array<unsigned char>^ zaa;
	System::Diagnostics::Debug::Assert(
		Ambiesoft::CppUtils::ReadAlternate(L"C:\\T\\magic", L"alt", zaa)
		);

	String^ zzz = System::Text::Encoding::UTF8->GetString(zaa);
	System::Diagnostics::Debug::Assert(baaa->Length == zaa->Length);
	System::Diagnostics::Debug::Assert(aaa == zzz);

	array<String^>^ as = gcnew array<String^>(2);
	as[0] = L"C:\\T\\x\\a";
	as[1] = L"C:\\T\\x\\b";
	Ambiesoft::CppUtils::DeleteFiles(as);
	Ambiesoft::CppUtils::DeleteFile(L"C:\\T\\x\\*.csproj");

	Ambiesoft::CppUtils::CopyFile(L"Y:\\T\\*.zip",L"Y:\\T\\aaa\\");
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	Application::Run(gcnew Form1());
	return 0;
}
