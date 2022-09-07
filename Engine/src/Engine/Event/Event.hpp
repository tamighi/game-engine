#pragma once
#include "../Core.hpp"

namespace Engine
{
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender, 
		KeyPressed, KeyRelease,
		MouseButtonPressed, MouseButtonRelease, MouseMove, MouseScrolled
	};

	// Use of BIT because events can go in different categories
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput		= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse		= BIT(3),
		EventCategoryMouseButton	= BIT(4)
	};

	class Event
	{
		virtual int GetCategoryFlags() = 0;

		inline bool IsInCategory(EventCategory& category)
		{
			return GetCategoryFlags() & category;
		}
		
	protected:
		// Already handled or not
		bool m_Handled = false;
	};
}
