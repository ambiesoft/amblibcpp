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


#pragma once



namespace Ambiesoft {
	namespace platform {

		using namespace System;

		public enum class CPPUTIL_MOVEWINDOWTYPE
		{
			TOPLEFT,
			TOPRIGHT,
			BOTTOMLEFT,
			BOTTOMRIGHT,
		};

		// cetering feature currently does not support multithread
		// 
		//
		ref class CheckThread sealed abstract
		{
			static int threadID_;
		public:
			static CheckThread()
			{
				threadID_ = System::Threading::Thread::CurrentThread->ManagedThreadId;
			}
			static property bool IsMainThread
			{
				bool get()
				{
					return threadID_ == System::Threading::Thread::CurrentThread->ManagedThreadId;
				}
			}
		};

		public ref class CppUtils {
			static std::string getStdStringLoc(String^ s);
			static std::string getStdStringLoc(String^ s, LPCSTR pLoc);

			static std::string getStdString(String^ s);
			static std::wstring getStdWstring(String^ s);
		public:
			static bool moveWindowSpecific(System::Windows::Forms::Form^ f, CPPUTIL_MOVEWINDOWTYPE type);
			static String^ humanReadableByteCount(System::UInt64 len);

			static int CopyFile(System::Windows::Forms::IWin32Window^ win, String^ src, String^ dest);
			static int CopyFile(String^ src, String^ dest);
			static int DeleteFile(System::Windows::Forms::IWin32Window^ win, String^ file);
			static int DeleteFile(String^ file);
			static int MoveFile(String^ src, String^ dest);
			static int MoveFile(System::Windows::Forms::IWin32Window^ win, String^ src, String^ dest);

			static int CopyFiles(System::Windows::Forms::IWin32Window^ win, cli::array<String^>^ froms, cli::array<String^>^ tos);
			static int CopyFiles(cli::array<String^>^ froms, cli::array<String^>^ tos);
			static int DeleteFiles(System::Windows::Forms::IWin32Window^ win, cli::array<String^>^ files);
			static int DeleteFiles(cli::array<String^>^ files);
			static int MoveFiles(System::Windows::Forms::IWin32Window^ win, cli::array<String^>^ froms, cli::array<String^>^ tos);
			static int MoveFiles(cli::array<String^>^ froms, cli::array<String^>^ tos);


			static bool WriteAlternate(String^ filename, String^ alterpath, array<unsigned char>^ data);
			static bool ReadAlternate(String^ filename, String^ alterpath, array<unsigned char>^% data);

			static String^ getMimeTypeFromExtention(String^ ext);

			static void testMessageBox(String^ message);

			static System::Windows::Forms::DialogResult CenteredMessageBox(
				System::Windows::Forms::IWin32Window^ owner,
				String^ text,
				String^ caption,
				System::Windows::Forms::MessageBoxButtons buttons,
				System::Windows::Forms::MessageBoxIcon icon,
				System::Windows::Forms::MessageBoxDefaultButton defaultButton);
			static System::Windows::Forms::DialogResult CenteredMessageBox(
				System::Windows::Forms::IWin32Window^ owner,
				String^ text,
				String^ caption,
				System::Windows::Forms::MessageBoxButtons buttons,
				System::Windows::Forms::MessageBoxIcon icon)
			{
				return CenteredMessageBox(
					owner,
					text,
					caption,
					buttons,
					icon,
					System::Windows::Forms::MessageBoxDefaultButton::Button1);
			}
			static System::Windows::Forms::DialogResult CenteredMessageBox(
				System::Windows::Forms::IWin32Window^ owner,
				String^ text,
				String^ caption,
				System::Windows::Forms::MessageBoxButtons buttons)
			{
				return CenteredMessageBox(
					owner,
					text,
					caption,
					buttons,
					System::Windows::Forms::MessageBoxIcon::None);
			}
			static System::Windows::Forms::DialogResult CenteredMessageBox(
				System::Windows::Forms::IWin32Window^ owner,
				String^ text,
				String^ caption)
			{
				return CenteredMessageBox(
					owner,
					text,
					caption,
					System::Windows::Forms::MessageBoxButtons::OK);
			}
			static System::Windows::Forms::DialogResult CenteredMessageBox(
				System::Windows::Forms::IWin32Window^ owner,
				String^ text)
			{
				return CenteredMessageBox(
					owner,
					text,
					String::Empty);
			}


			// no owner
			static System::Windows::Forms::DialogResult CenteredMessageBox(
				String^ text,
				String^ caption,
				System::Windows::Forms::MessageBoxButtons buttons,
				System::Windows::Forms::MessageBoxIcon icon,
				System::Windows::Forms::MessageBoxDefaultButton defaultButton)
			{
				return CenteredMessageBox(
					nullptr,
					text,
					caption,
					buttons,
					icon,
					defaultButton);
			}
			static System::Windows::Forms::DialogResult CenteredMessageBox(
				String^ text,
				String^ caption,
				System::Windows::Forms::MessageBoxButtons buttons,
				System::Windows::Forms::MessageBoxIcon icon)
			{
				return CenteredMessageBox(
					nullptr,
					text,
					caption,
					buttons,
					icon,
					System::Windows::Forms::MessageBoxDefaultButton::Button1);
			}
			static System::Windows::Forms::DialogResult CenteredMessageBox(
				String^ text,
				String^ caption,
				System::Windows::Forms::MessageBoxButtons buttons)
			{
				return CenteredMessageBox(
					nullptr,
					text,
					caption,
					buttons,
					System::Windows::Forms::MessageBoxIcon::None);
			}
			static System::Windows::Forms::DialogResult CenteredMessageBox(
				String^ text,
				String^ caption)
			{
				return CenteredMessageBox(
					nullptr,
					text,
					caption,
					System::Windows::Forms::MessageBoxButtons::OK);
			}
			static System::Windows::Forms::DialogResult CenteredMessageBox(
				String^ text)
			{
				return CenteredMessageBox(
					nullptr,
					text,
					String::Empty);
			}

			//static CppUtils()
			//{
			//	CheckThread::IsMainThread;
			//}

			//static System::Windows::Forms::DialogResult Alert(
			//	System::Windows::Forms::IWin32Window^ owner, String^ text)
			//{
			//	return CenteredMessageBox(
			//		owner,
			//		text,
			//		System::Windows::Forms::Application::ProductName,
			//		System::Windows::Forms::MessageBoxButtons::OK,
			//		System::Windows::Forms::MessageBoxIcon::Warning);
			//}
			//static System::Windows::Forms::DialogResult Alert(
			//	String^ text)
			//{
			//	return Alert(nullptr, text);
			//}

			static String^ GetSelectedFolder(System::Windows::Forms::IWin32Window^ win, String^ title);

			static void OpenFolder(System::Windows::Forms::IWin32Window^ win, String^ path);
			static String^ GetShortFileName(String^ longname);

			static String^ GetNativeVersionString(String^ filename);
		};


		public ref class CenteringDialog
		{
		public:
			CenteringDialog(System::Windows::Forms::IWin32Window^ owner);
			~CenteringDialog();
		};
	}
}