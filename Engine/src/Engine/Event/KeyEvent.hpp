#pragma once

#include "Event.hpp"

namespace Engine
{
	class KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }
	protected:
		KeyEvent(int keycode)
			: m_KeyCode(keycode) {}

		int m_KeyCode;
	};

	class KeyPressEvent : public KeyEvent
	{
	public:
		KeyPressEvent(int keycode, int repeatCount)
			: m_KeyCode(keycode), m_RepeatCount(repeatCount) {}

		int GetEventCount() { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

	private:
		int m_RepeatCount;
	}
}
