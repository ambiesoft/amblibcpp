// amblibcpp.h

#pragma once



namespace Ambiesoft {

	using namespace System;

	public enum class MOVEWINDOWTYPE
	{
		MOVEWINDOW_TOPLEFT,
		MOVEWINDOW_TOPRIGHT,
		MOVEWINDOW_BOTTOMLEFT,
		MOVEWINDOW_BOTTOMRIGHT,
	};


	public ref class CppUtils {
	public:
		static std::string getStdStringLoc(String^ s);
		static std::string getStdStringLoc(String^ s, LPCSTR pLoc);

		static std::string getStdString(String^ s);
		static std::wstring getStdWstring(String^ s);

		static bool moveWindowSpecific(System::Windows::Forms::Form^ f, MOVEWINDOWTYPE type);
		static String^ humanReadableByteCount(System::UInt64 len);

		static bool CopyFile(String^ src, String^ dest);
		static int MoveFiles(cli::array<String^>^ froms, cli::array<String^>^ tos);
		static void donothing();
	};

}
