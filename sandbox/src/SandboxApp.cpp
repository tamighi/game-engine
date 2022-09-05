#include <iostream>
#include <engine.hpp>

class Sandbox : public engine::Application 
{
public:
    Sandbox() {}
    ~Sandbox() {}
};

engine::Application* engine::CreateApplication() 
{
    return new Sandbox;
}