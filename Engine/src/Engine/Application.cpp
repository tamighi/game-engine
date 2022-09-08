#include "pch.hpp"
#include "Application.hpp"

namespace Engine
{

    Application::Application() 
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

    Application::~Application() {}

    void Application::run() 
    {

        while (m_Running)
		{
			m_Window->OnUpdate();
		}
    }
}
