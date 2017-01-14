// amblibcpp.h

#pragma once

using namespace System;

namespace Ambiesoft {
	public enum class MOVEWINDOWTYPE
	{
		MOVEWINDOW_TOPLEFT,
		MOVEWINDOW_TOPRIGHT,
		MOVEWINDOW_BOTTOMLEFT,
		MOVEWINDOW_BOTTOMRIGHT,
	};

	public ref class AmbLibCpp abstract sealed
	{
	public:
		static bool moveWindowSpecific(System::Windows::Forms::Form^ f, MOVEWINDOWTYPE type);
		
		static String^ AmbLibCpp::humanReadableByteCount(System::UInt64 len) ;
	};
}
