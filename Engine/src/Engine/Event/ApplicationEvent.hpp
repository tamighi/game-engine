#pragma once

#include <sstream>

#include "Event.hpp"

namespace Engine {

	class WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(int height, int width)
			: m_Height(height), m_Width(width) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
			return ss.str();
		}

	private:
		int m_Height;
		int m_Width;
	};

}
