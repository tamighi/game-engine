#include "pch.hpp"
#include "Application.hpp"

namespace Engine
{

    Application::Application() {}

    Application::~Application() {}

    void Application::run() 
    {
		KeyPressEvent e(3, true);
		if (e.IsInCategory(EventCategoryInput))
		{
			HZ_TRACE(e);
		}

        while (true);
    }
}
