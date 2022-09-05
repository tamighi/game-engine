#pragma once

extern  engine::Application* engine::CreateApplication();

int main(int argc, char** argv) 
{
    (void) argc;
    (void) argv;

    engine::Log::Init();
    HZ_CORE_WARN("Initialized logger !");

    engine::Application* app = engine::CreateApplication();
    app->run();
    delete app;
}