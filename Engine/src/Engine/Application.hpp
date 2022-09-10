#pragma once

#include "Engine/Core.hpp"
#include "Engine/Log.hpp"
#include "Engine/Window.hpp"
#include "Engine/Events/Event.hpp"
#include "Engine/Events/ApplicationEvent.hpp"

namespace Engine 
{
    class Application 
    {

    public:
        Application();
        virtual ~Application();

        void Run();      

	void OnEvent(Event& e);

private:
	bool OnWindowClose(WindowCloseEvent& e);

private:
	std::unique_ptr<Window> m_Window;
	bool m_Running = true;
    };

    Application* CreateApplication();
}
