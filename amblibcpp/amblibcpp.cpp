

#include "stdafx.h"

#include "amblibcpp.h"


namespace Ambiesoft {


	bool AmbLibCpp::moveWindowSpecific(System::Windows::Forms::Form^ f, MOVEWINDOWTYPE type)
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


	String^ AmbLibCpp::humanReadableByteCount(System::UInt64 len) 
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
}