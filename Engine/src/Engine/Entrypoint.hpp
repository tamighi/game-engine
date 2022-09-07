#pragma once

extern  Engine::Application* Engine::CreateApplication();

int main(int argc, char** argv) 
{
    (void) argc;
    (void) argv;

    Engine::Log::Init();
    HZ_CORE_WARN("Initialized logger !");

    Engine::Application* app = Engine::CreateApplication();
    app->run();
    delete app;
}
