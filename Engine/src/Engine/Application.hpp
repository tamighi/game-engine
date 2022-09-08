#pragma once

#include "Engine/Core.hpp"
#include "Engine/Log.hpp"
#include "Events/KeyEvent.hpp"

namespace Engine 
{

    class Application 
    {

    public:
        Application();
        virtual ~Application();

        void run();      
    };

    Application* CreateApplication();
}
