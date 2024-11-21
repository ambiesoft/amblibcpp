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

#include "AmbLibcpp.h"

using std::vector;
using std::wstring;
using namespace System::IO;

namespace Ambiesoft {
	namespace platform {

		std::string CppUtils::getStdStringLoc(String^ s, LPCSTR pLoc)
		{
			char szLang[4];
			if (!pLoc)
			{
				::GetLocaleInfoA(LOCALE_USER_DEFAULT,
					LOCALE_SABBREVLANGNAME,
					szLang,
					4);
				pLoc = szLang;
			}
			setlocale(LC_CTYPE, pLoc);

			std::string ret;
			if (s == nullptr)
				return ret;

			pin_ptr<const wchar_t> p = PtrToStringChars(s);
			size_t len = (s->Length + 1) * sizeof(wchar_t);
			char* pT = (char*)malloc(len);
			size_t retutrnvalue;

			if (0 != wcstombs_s(&retutrnvalue,
				pT,
				len,
				p,
				len))
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
			if (s == nullptr)
				return ret;

			pin_ptr<const wchar_t> p = PtrToStringChars(s);
			size_t len = (s->Length + 1) * sizeof(wchar_t);
			char* pT = (char*)malloc(len);
			size_t retutrnvalue;

			if (0 != wcstombs_s(&retutrnvalue,
				pT,
				len,
				p,
				len))
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
			if (s == nullptr)
				return ret;

			pin_ptr<const wchar_t> p = PtrToStringChars(s);
			ret = p;
			return ret;
		}

		bool CppUtils::moveWindowSpecific(System::Windows::Forms::Form^ f, CPPUTIL_MOVEWINDOWTYPE type)
		{
			if (!f || !f->IsHandleCreated || f->IsDisposed)
			{
				return false;
			}

			System::Drawing::Rectangle screenRect = System::Windows::Forms::Screen::GetWorkingArea(f);
			System::Drawing::Size curSize = f->Size;
			System::Drawing::Point targetPos;
			switch (type)
			{
			case CPPUTIL_MOVEWINDOWTYPE::TOPLEFT:
				targetPos = screenRect.Location;
				break;
			case CPPUTIL_MOVEWINDOWTYPE::TOPRIGHT:
				targetPos.X = screenRect.Right - curSize.Width;
				targetPos.Y = screenRect.Location.Y;
				break;
			case CPPUTIL_MOVEWINDOWTYPE::BOTTOMLEFT:
				targetPos.X = screenRect.Location.X;
				targetPos.Y = screenRect.Bottom - curSize.Height;
				break;
			case CPPUTIL_MOVEWINDOWTYPE::BOTTOMRIGHT:
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
				len = len / 1024;
			}

			// Adjust the format string to your preferences. For example "{0:0.#}{1}" would
			// show a single decimal place, and no space.
			String^ result = String::Format("{0:0.##} {1}", len, sizes[order]);
			return result;
		}

		int CppUtils::CopyFile(System::Windows::Forms::IWin32Window^ win, String^ src, String^ dest)
		{
			pin_ptr<const wchar_t> pSrc = PtrToStringChars(src);
			pin_ptr<const wchar_t> pDest = PtrToStringChars(dest);

			return SHCopyFileEx(win ? (HWND)win->Handle.ToPointer() : NULL, pSrc, pDest);
		}
		int CppUtils::CopyFile(String^ src, String^ dest)
		{
			return CopyFile(nullptr, src, dest);
		}
		int CppUtils::DeleteFile(System::Windows::Forms::IWin32Window^ win, String^ file)
		{
			pin_ptr<const wchar_t> pSrc = PtrToStringChars(file);
			return SHDeleteFileEx(win ? (HWND)win->Handle.ToPointer() : NULL, pSrc);
		}
		int CppUtils::DeleteFile(String^ file)
		{
			return DeleteFile(nullptr, file);
		}
		int CppUtils::MoveFile(System::Windows::Forms::IWin32Window^ win, String^ src, String^ dest)
		{
			pin_ptr<const wchar_t> pSrc = PtrToStringChars(src);
			pin_ptr<const wchar_t> pDest = PtrToStringChars(dest);

			return SHMoveFileEx(win ? (HWND)win->Handle.ToPointer() : NULL, pSrc, pDest);
		}
		int CppUtils::MoveFile(String^ src, String^ dest)
		{
			return MoveFile(nullptr, src, dest);
		}

		bool prepareVector(
			cli::array<String^>^ clrfroms,
			cli::array<String^>^ clrtos,
			vector<wstring>& stdfroms,
			vector<wstring>& stdtos)
		{
			if (!clrfroms || !clrtos)
				return false;
			if (clrfroms->Length == 0 || clrtos->Length == 0)
				return false;
			if (clrfroms->Length != clrtos->Length)
				return false;

			for each(String^ s in clrfroms)
				stdfroms.push_back(toWstring(s));
			for each(String^ s in clrtos)
				stdtos.push_back(toWstring(s));

			return true;
		}
		int CppUtils::CopyFiles(System::Windows::Forms::IWin32Window^ win, cli::array<String^>^ froms, cli::array<String^>^ tos)
		{
			vector<wstring> stdFroms;
			vector<wstring> stdTos;

			if (!prepareVector(froms, tos, stdFroms, stdTos))
				return 1;

			return SHCopyFileEx(win ? (HWND)win->Handle.ToPointer() : NULL, stdFroms, stdTos);
		}
		int CppUtils::CopyFiles(cli::array<String^>^ froms, cli::array<String^>^ tos)
		{
			return CopyFiles(nullptr, froms, tos);
		}

		int CppUtils::DeleteFiles(System::Windows::Forms::IWin32Window^ win, cli::array<String^>^ files)
		{
			vector<wstring> stdfiles;
			for each(String^ s in files)
				stdfiles.push_back(toWstring(s));

			return SHDeleteFileEx(win ? (HWND)win->Handle.ToPointer() : NULL, stdfiles);
		}
		int CppUtils::DeleteFiles(cli::array<String^>^ files)
		{
			return DeleteFiles(nullptr, files);
		}

		int CppUtils::MoveFiles(System::Windows::Forms::IWin32Window^ win, cli::array<String^>^ froms, cli::array<String^>^ tos)
		{
			vector<wstring> stdFroms;
			vector<wstring> stdTos;

			if (!prepareVector(froms, tos, stdFroms, stdTos))
				return 1;

			return SHMoveFileEx(win ? (HWND)win->Handle.ToPointer() : NULL, stdFroms, stdTos);
		}
		int CppUtils::MoveFiles(cli::array<String^>^ froms, cli::array<String^>^ tos)
		{
			return MoveFiles(nullptr, froms, tos);
		}

		bool CppUtils::MoveFileAtomic(System::Collections::Generic::List<System::Collections::Generic::KeyValuePair<String^, String^>>^ srcdests)
		{
			SRCDESTVECTOR v;
			for each (System::Collections::Generic::KeyValuePair<String^, String^> kv in srcdests)
			{
				v.push_back(SRCDEST(toWstring(kv.Key), toWstring(kv.Value)));
			}
			return Ambiesoft::MoveFileAtomic(v);
		}

		bool CppUtils::WriteAlternate(String^ filename, String^ alterpath, array<unsigned char>^ data)
		{
			if (data->Length <= 0)
				return true;

			wstring stdfile = toWstring(filename);
			stdfile += L":" + toWstring(alterpath);
			pin_ptr<unsigned char > pData = &data[0];

			CFileHandle file(CreateFile(stdfile.c_str(),
				GENERIC_WRITE,
				FILE_SHARE_WRITE,
				NULL,
				OPEN_ALWAYS,
				0,
				NULL));
			if (!file)
				return false;

			DWORD dwWritten = 0;
			if (!WriteFile(file, pData, data->Length, &dwWritten, NULL))
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


			CFileHandle file(CreateFile(stdfile.c_str(),
				GENERIC_READ,
				FILE_SHARE_READ,
				NULL,
				OPEN_ALWAYS,
				0,
				NULL));
			if (!file)
				return false;

			DWORD dwWritten = 0;
			vector<unsigned char> all;
			unsigned char buff[128];
			DWORD dwRead = 0;
			for (;;)
			{
				if (!ReadFile(file, buff, sizeof(buff), &dwRead, NULL))
					return false;
				if (dwRead == 0)
					break;
				all.insert(all.end(), &buff[0], &buff[dwRead]);
			}
			data = gcnew array<unsigned char>((int)all.size());
			if (!all.empty())
			{
				pin_ptr<unsigned char> pData = &data[0];
				memcpy(pData, &all[0], all.size());
			}
			return true;
		}

		// https://stackoverflow.com/a/20647203
		String^ CppUtils::getMimeTypeFromExtention(String^ ext)
		{
			if (String::IsNullOrEmpty(ext))
				return String::Empty;
			if (ext[0] != '.')
				ext = "." + ext;

			pin_ptr<const wchar_t> str = PtrToStringChars(ext);

			LPWSTR pwzMimeOut = NULL;
			HRESULT hr = FindMimeFromData(
				NULL,
				str,
				NULL,
				0,
				NULL,
				FMFD_URLASFILENAME,
				&pwzMimeOut,
				0x0);
			if (SUCCEEDED(hr))
			{
				String^ ret = gcnew String(pwzMimeOut);
				// Despite the documentation stating to call operator delete, the
				// returned string must be cleaned up using CoTaskMemFree
				CoTaskMemFree(pwzMimeOut);
				return ret;
			}

			return String::Empty;
		}

		void CppUtils::testMessageBox(String^ message)
		{
			pin_ptr<const wchar_t> pMessage = PtrToStringChars(message);
			MessageBox(NULL, pMessage, L"Title", MB_OK);
		}

		static HHOOK ghCMB;
		static HWND ghOwner;
		static LRESULT CALLBACK cmbCBTProc(
			_In_ int    nCode,
			_In_ WPARAM wParam,
			_In_ LPARAM lParam
			)
		{
			if (nCode < 0)
				return CallNextHookEx(ghCMB, nCode, wParam, lParam);

			switch (nCode)
			{
			case HCBT_CREATEWND:
			{
				HWND hWnd = (HWND)wParam;
				CBT_CREATEWND* pCW = (CBT_CREATEWND*)lParam;

				TCHAR szClass[256]; szClass[0] = 0;
				GetClassName(hWnd, szClass, _countof(szClass));
				if (lstrcmpi(szClass, L"#32770") == 0)
				{
					RECT rThis;
					rThis.left = pCW->lpcs->x;
					rThis.top = pCW->lpcs->y;
					rThis.right = pCW->lpcs->x + pCW->lpcs->cx;
					rThis.bottom = pCW->lpcs->y + pCW->lpcs->cy;

					HWND hParent = ghOwner;
					if (hParent == NULL)
						hParent = pCW->lpcs->hwndParent;
					if (hParent == NULL)
						hParent = GetDesktopWindow();

					RECT rParent;
					if (!GetWindowRect(hParent, &rParent))
						break;

					int xNew, yNew;
					CenterRect(rThis, rParent, xNew, yNew);

					pCW->lpcs->x = xNew;
					pCW->lpcs->y = yNew;
				}
			}
			break;
			}
			return CallNextHookEx(ghCMB, nCode, wParam, lParam);
		}

		// https://stackoverflow.com/a/6924332
		static HMODULE cmbGetModuleHandle()
		{
			HMODULE hm = NULL;

			if (!GetModuleHandleEx(
				GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
				(LPCWSTR)&cmbGetModuleHandle,
				&hm))
			{
				DASSERT(false);
				return NULL;
			}
			return hm;
		}

		// TODO: Not thread safe
		System::Windows::Forms::DialogResult CppUtils::CenteredMessageBox(
			System::Windows::Forms::IWin32Window^ owner,
			String^ text,
			String^ caption,
			System::Windows::Forms::MessageBoxButtons buttons,
			System::Windows::Forms::MessageBoxIcon icon,
			System::Windows::Forms::MessageBoxDefaultButton defaultButton)
		{
			if (!CheckThread::IsMainThread)
			{
				return System::Windows::Forms::MessageBox::Show(
					owner,
					text,
					caption,
					buttons,
					icon,
					defaultButton);
			}

			DASSERT(!ghOwner);
			ghOwner = owner ? (HWND)owner->Handle.ToPointer() : nullptr;
			DASSERT(!ghCMB);
			ghCMB = SetWindowsHookEx(WH_CBT, cmbCBTProc, cmbGetModuleHandle(), GetCurrentThreadId());
			DASSERT(ghCMB);
			System::Windows::Forms::DialogResult ret = System::Windows::Forms::MessageBox::Show(
				owner,
				text,
				caption,
				buttons,
				icon,
				defaultButton);
			DVERIFY(UnhookWindowsHookEx(ghCMB));
			ghCMB = NULL;
			ghOwner = NULL;
			return ret;
		}


		CenteringDialog::CenteringDialog(System::Windows::Forms::IWin32Window^ owner)
		{
			if (!CheckThread::IsMainThread)
				return;

			DASSERT(!ghOwner);
			ghOwner = owner ? (HWND)owner->Handle.ToPointer() : nullptr;
			DASSERT(!ghCMB);
			ghCMB = SetWindowsHookEx(WH_CBT, cmbCBTProc, cmbGetModuleHandle(), GetCurrentThreadId());
			DASSERT(ghCMB);
		}
		CenteringDialog::~CenteringDialog()
		{
			if (!CheckThread::IsMainThread)
				return;

			ghOwner = nullptr;
			DASSERT(ghCMB);
			DVERIFY(UnhookWindowsHookEx(ghCMB));
			ghCMB = NULL;
		}

		String^ CppUtils::GetSelectedFolder(System::Windows::Forms::IWin32Window^ win, String^ title)
		{
			String^ folder;
			return GetSelectedFolder(win, title, folder);
		}
		String^ CppUtils::GetSelectedFolder(System::Windows::Forms::IWin32Window^ win, String^ title, String^ folder)
		{
			if (!browseFolder(win, title, folder))
				return nullptr;
			return folder;
		}

		void CppUtils::OpenFolder(System::Windows::Forms::IWin32Window^ win, String^ path)
		{
			std::wstring strPath = CppUtils::getStdWstring(path);
			Ambiesoft::OpenFolder(win ? (HWND)win->Handle.ToPointer() : NULL, strPath.c_str());
		}

		String^ CppUtils::GetShortFileName(String^ longname)
		{
			wstring clongname = toWstring(longname);
			wstring cshortname = stdGetShortPath(clongname);
			return gcnew String(cshortname.c_str());
		}

		String^ CppUtils::GetNativeVersionString(String^ filename, int keta)
		{
			wstring s = toWstring(filename);
			s = Ambiesoft::GetVersionStringFromResource(s.c_str(), keta);
			return gcnew String(s.c_str());
		}
		String^ CppUtils::GetNativeVersionString(String^ filename)
		{
			return GetNativeVersionString(filename, -1);
		}
		// http://www.rw-designer.com/DPI-aware
		bool CppUtils::AmbSetProcessDPIAware()
		{
			HMODULE hUser32 = LoadLibraryA("user32.dll");
			typedef BOOL(WINAPI *SetProcessDPIAwareFunc)();
			SetProcessDPIAwareFunc setDPIAware = (SetProcessDPIAwareFunc)GetProcAddress(hUser32, "SetProcessDPIAware");
			bool ret = false;
			if (setDPIAware)
				ret = !!setDPIAware();
			FreeLibrary(hUser32);
			return ret;
		}

		bool CppUtils::CreateDesktopShortcut(System::Windows::Forms::IWin32Window^ win, String^ title, String^ exe)
		{
			String^ lnkFile = Path::Combine(
				Environment::GetFolderPath(Environment::SpecialFolder::Desktop),
				title + L".lnk");

			String^ curDir = Path::GetDirectoryName(exe);
			
			return !!CreateShortcutFile(
				win ? (HWND)win->Handle.ToPointer() : nullptr,
				getStdWstring(lnkFile).c_str(),
				getStdWstring(exe).c_str(),
				getStdWstring(curDir).c_str());
		}

		bool CppUtils::OpenCommon(System::Windows::Forms::IWin32Window^ win, String^ exe, String^ command)
		{
			std::wstring strExe = CppUtils::getStdWstring(exe);
			std::wstring strCommand = CppUtils::getStdWstring(command);
			return !!Ambiesoft::OpenCommon(win ? (HWND)win->Handle.ToPointer() : NULL,
				exe==nullptr ? nullptr : strExe.c_str(),
				command==nullptr ? nullptr : strCommand.c_str());
		}

		String^ CppUtils::getWindowDebugString(IntPtr winptr)
		{
			if (winptr == (IntPtr)0)
				return L"NullWin";
			HWND h = (HWND)winptr.ToPointer();
			if (!IsWindow(h))
				return L"Not a window";
			
			
			LONG_PTR style = ::GetWindowLongPtr(h, GWL_STYLE);
			LONG_PTR exstyle = ::GetWindowLongPtr(h, GWL_EXSTYLE);

			return String::Format(L"style={0}, exstyle={1}",
				style, exstyle);
		}
		String^ CppUtils::getWindowDebugString(System::Windows::Forms::IWin32Window^ win)
		{
			return getWindowDebugString(win ? win->Handle : (IntPtr)0);
		}
		bool CppUtils::IsCtrlPressed()
		{
			return GetAsyncKeyState(VK_CONTROL) < 0;
		}
		bool CppUtils::MakeRichEditFontPersist(System::Windows::Forms::RichTextBox^ richTextBox)
		{
			DASSERT(richTextBox);
			DASSERT(richTextBox->IsHandleCreated);
			DASSERT(!richTextBox->IsDisposed);
			LPARAM lParam = SendMessage((HWND)richTextBox->Handle.ToPointer(), EM_GETLANGOPTIONS, 0, 0);
			lParam &= ~(IMF_DUALFONT | IMF_AUTOFONT);
			return 1==SendMessage((HWND)richTextBox->Handle.ToPointer(), EM_SETLANGOPTIONS, 0, lParam);
		}
	}
}