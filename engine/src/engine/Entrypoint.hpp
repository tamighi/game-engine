#pragma once

extern  engine::Application* engine::CreateApplication();

int main(int argc, char** argv) {
    (void) argc;
    (void) argv;
    engine::Application* app = engine::CreateApplication();

    app->run();

    delete app;
}