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

#define EVENT_CLASS_TYPE(type)	static EventType GetStaticType() { return EventType::##type; } \
				virtual EventType GetEventType() const override { return GetStaticType(); } \
				virtual const char* GetName() const override {return #type; }

	class Event
	{
	public:
		virtual EventType GetEventType() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual const char* GetName() const = 0;
		virtual std::string ToString() const { return getName(); };

		inline bool IsInCategory(EventCategory& category)
		{
			return GetCategoryFlags() & category;
		}
		
	protected:
		// Already handled or not
		bool m_Handled = false;
	};
}
