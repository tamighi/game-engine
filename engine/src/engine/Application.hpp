#pragma once

namespace engine {

    class Application {

    public:
        Application();
         virtual ~Application();

        void run();      
    };

    Application* CreateApplication();
}