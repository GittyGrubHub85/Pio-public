#include <Pio.h>//How do I add a Pio directory outside the Sandbox directory? This file is not descended in the directory.

class ExampleLayer : public Pio::Layer {
public:
	ExampleLayer() : Layer("Example") {

	}

	void OnUpdate() override {
		PIO_INFO("ExampleLayer::Update");
	}

	void OnEvent(Pio::Event& event) override {
		PIO_TRACE("{0}", event);
	}
};

class Sandbox : public Pio::Application { //Sandbox class inherits the Pio Engine
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new Pio::ImGuiLayer()); 
	}
	~Sandbox() {

	}
};

Pio::Application* Pio::CreateApplication() {//Creates a class instance which will be the actual application that have been built
	return new Sandbox();//This is the Sandbox.obj
}