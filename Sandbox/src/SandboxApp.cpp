#include <Pio.h>//How do I add a Pio directory outside the Sandbox directory? This file is not descended in the directory.


class Sandbox : public Pio::Application { //Sandbox class inherits the Pio Engine
public:
	Sandbox() {

	}
	~Sandbox() {

	}
};

Pio::Application* Pio::CreateApplication() {//Creates a class instance which will be the actual application that have been built
	return new Sandbox();//This is the Sandbox.obj
}

/*
int main() {
	Sandbox* sandbox = new Sandbox();
	sandbox->Run();
	delete sandbox;
}*/