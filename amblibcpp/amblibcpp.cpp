

#include "stdafx.h"
#include <windows.h>
#include <Shlwapi.h>
#pragma comment(lib, "shlwapi.lib")

#include <tchar.h>
#include <vcclr.h>

#include <stlsoft/smartptr/scoped_handle.hpp>

#include "amblibcpp.h"

#include "../../lsMisc/SHMoveFile.h"
#include "../../lsMisc/cppclr/clrString.h"

using std::vector;
using std::wstring;
using namespace System::IO;

namespace Ambiesoft {

	std::string CppUtils::getStdStringLoc(String^ s, LPCSTR pLoc)
	{
		char szLang[4];
		if(!pLoc)
		{
			::GetLocaleInfoA(LOCALE_USER_DEFAULT ,
					LOCALE_SABBREVLANGNAME,
					szLang, 
					4);
			pLoc = szLang;
		}
		setlocale( LC_CTYPE, pLoc );

		std::string ret;
		if ( s == nullptr )
			return ret;

		pin_ptr<const wchar_t> p = PtrToStringChars(s);
		size_t len = (s->Length+1) * sizeof(wchar_t);
		char* pT = (char*)malloc(len);
		size_t retutrnvalue;

		if ( 0 != wcstombs_s( &retutrnvalue, 
			pT,
			len,
			p,
			len ) )
		{
			
			free(pT);
			return ret;
		}
		ret = pT;
		free(pT);
		return ret;
	}
	std::string CppUtils::getStdStringLoc(String^ s)
	{
		return getStdStringLoc(s, NULL);
	}
	std::string CppUtils::getStdString(String^ s)
	{
		std::string ret;
		if ( s == nullptr )
			return ret;

		pin_ptr<const wchar_t> p = PtrToStringChars(s);
		size_t len = (s->Length+1) * sizeof(wchar_t);
		char* pT = (char*)malloc(len);
		size_t retutrnvalue;

		if ( 0 != wcstombs_s( &retutrnvalue, 
			pT,
			len,
			p,
			len ) )
		{
			free(pT);
			return getStdStringLoc(s);
		}
		ret = pT;
		free(pT);
		return ret;
	}


	std::wstring CppUtils::getStdWstring(String^ s)
	{
		std::wstring ret;
		if ( s == nullptr )
			return ret;

		pin_ptr<const wchar_t> p = PtrToStringChars(s);
		ret = p;
		return ret;
	}

	bool CppUtils::moveWindowSpecific(System::Windows::Forms::Form^ f, MOVEWINDOWTYPE type)
	{
		if ( !f || !f->IsHandleCreated || f->IsDisposed )
		{
			return false;
		}

		System::Drawing::Rectangle screenRect = System::Windows::Forms::Screen::GetWorkingArea(f);
		System::Drawing::Size curSize = f->Size;
		System::Drawing::Point targetPos;
		switch(type)
		{
		case MOVEWINDOWTYPE::MOVEWINDOW_TOPLEFT:
			targetPos = screenRect.Location;
			break;
		case MOVEWINDOWTYPE::MOVEWINDOW_TOPRIGHT:
			targetPos.X = screenRect.Right - curSize.Width;
			targetPos.Y = screenRect.Location.Y;
			break;
		case MOVEWINDOWTYPE::MOVEWINDOW_BOTTOMLEFT:
			targetPos.X = screenRect.Location.X;
			targetPos.Y = screenRect.Bottom - curSize.Height;
			break;
		case MOVEWINDOWTYPE::MOVEWINDOW_BOTTOMRIGHT:
			targetPos.X = screenRect.Right - curSize.Width;
			targetPos.Y = screenRect.Bottom - curSize.Height;
			break;

		default:
			return false;
		}

		f->Location = targetPos;

		return true;
	}


	String^ CppUtils::humanReadableByteCount(System::UInt64 len) 
	{
		array<String^>^ sizes = { "B", "KB", "MB", "GB", "TB" };

		int order = 0;
		while (len >= 1024 && order < sizes->Length - 1) {
			order++;
			len = len/1024;
		}

		// Adjust the format string to your preferences. For example "{0:0.#}{1}" would
		// show a single decimal place, and no space.
		String^ result = String::Format("{0:0.##} {1}", len, sizes[order]);
		return result;
	}

	int CppUtils::CopyFile(String^ src, String^ dest)
	{
		pin_ptr<const wchar_t> pSrc=PtrToStringChars(src);
		pin_ptr<const wchar_t> pDest=PtrToStringChars(dest);

		return SHCopyFile(pDest, pSrc);
	}
	int CppUtils::DeleteFile(String^ file)
	{
		pin_ptr<const wchar_t> pSrc = PtrToStringChars(file);
		return SHDeleteFile(pSrc);
	}

	int CppUtils::MoveFiles(cli::array<String^>^ froms, cli::array<String^>^ tos)
	{
		if (!froms || !tos)
			return false;
		if (froms->Length == 0 || tos->Length == 0)
			return false;
		if (froms->Length != tos->Length)
			return false;

		vector<wstring> stdFroms;
		vector<wstring> stdTos;

		for each(String^ s in froms)
			stdFroms.push_back(toWstring(s));
		for each(String^ s in tos)
			stdTos.push_back(toWstring(s));

		int ret;
		SHMoveFile(stdTos, stdFroms, &ret);
		return ret;
	}
	int CppUtils::DeleteFiles(cli::array<String^>^ files)
	{
		vector<wstring> stdfiles;
		for each(String^ s in files)
			stdfiles.push_back(toWstring(s));

		int ret;
		SHDeleteFile(stdfiles, &ret);
		return ret;
	}
	bool CppUtils::WriteAlternate(String^ filename, String^ alterpath, array<unsigned char>^ data)
	{
		if (data->Length <= 0)
			return true;

		wstring stdfile = toWstring(filename);
		stdfile += L":" + toWstring(alterpath);
		pin_ptr<unsigned char > pData = &data[0];

		HANDLE hFile = CreateFile(stdfile.c_str(),
			GENERIC_WRITE,
			FILE_SHARE_WRITE,
			NULL,
			OPEN_ALWAYS,
			0,
			NULL);
		if (hFile == INVALID_HANDLE_VALUE)
			return false;

		stlsoft::scoped_handle<HANDLE> freer(hFile, CloseHandle);

		DWORD dwWritten = 0;
		if (!WriteFile(hFile, pData, data->Length, &dwWritten, NULL))
			return false;
		if (dwWritten != data->Length)
			return false;

		return true;
	}
	bool CppUtils::ReadAlternate(String^ filename, String^ alterpath, array<unsigned char>^% data)
	{
		if (!File::Exists(filename))
			return false;

		wstring stdfile = toWstring(filename);
		stdfile += L":" + toWstring(alterpath);


		HANDLE hFile = CreateFile(stdfile.c_str(),
			GENERIC_READ,
			FILE_SHARE_READ,
			NULL,
			OPEN_ALWAYS,
			0,
			NULL);
		if (hFile == INVALID_HANDLE_VALUE)
			return false;

		stlsoft::scoped_handle<HANDLE> freer(hFile, CloseHandle);

		DWORD dwWritten = 0;
		vector<unsigned char> all;
		unsigned char buff[128];
		DWORD dwRead = 0;
		for (;;)
		{
			if (!ReadFile(hFile, buff, sizeof(buff), &dwRead, NULL))
				return false;
			if (dwRead == 0)
				break;
			all.insert(all.end(), &buff[0], &buff[dwRead]);
		}
		data = gcnew array<unsigned char>(all.size());
		if (!all.empty())
		{
			pin_ptr<unsigned char> pData = &data[0];
			memcpy(pData, &all[0], all.size());
		}
		return true;
	}

}