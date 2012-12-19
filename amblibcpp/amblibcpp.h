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

	public ref class AmbLib
	{
	public:
		static bool moveWindowSpecific(System::Windows::Forms::Form^ f, MOVEWINDOWTYPE type)
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

	};
}
