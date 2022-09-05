#include <iostream>
#include <engine.hpp>

class Sandbox : public engine::Application {
public:
    Sandbox() {}
    ~Sandbox() {}
};

int main(void) {
    Sandbox* sandbox = new Sandbox;

    sandbox->run();
    
    delete sandbox;
}