#pragma once

#include "Engine/Core.hpp"
#include "Engine/Log.hpp"
#include "Engine/Window.hpp"

namespace Engine 
{
    class Application 
    {

    public:
        Application();
        virtual ~Application();

        void run();      

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
    };

    Application* CreateApplication();
}
