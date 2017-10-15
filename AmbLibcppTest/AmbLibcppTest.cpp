//Copyright (C) 2017 Ambiesoft All rights reserved.
//
//Redistribution and use in source and binary forms, with or without
//modification, are permitted provided that the following conditions
//are met:
//1. Redistributions of source code must retain the above copyright
//notice, this list of conditions and the following disclaimer.
//2. Redistributions in binary form must reproduce the above copyright
//notice, this list of conditions and the following disclaimer in the
//documentation and/or other materials provided with the distribution.
//
//THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
//ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
//IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
//ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
//FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
//DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
//OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
//HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
//LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
//OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
//SUCH DAMAGE.

#include "stdafx.h"
#include "Form1.h"

using namespace AmbLibcppTest;
using namespace Ambiesoft;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	CenteringDialog center(nullptr);

	CppUtils::CenteredMessageBox("AAA");

	String^ mime = Ambiesoft::CppUtils::getMimeTypeFromExtention(".txt");
	mime = Ambiesoft::CppUtils::getMimeTypeFromExtention(".ini");
	mime = Ambiesoft::CppUtils::getMimeTypeFromExtention(".cpp");
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
