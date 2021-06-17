#pragma once

#ifdef PIO_PLATFORM_WINDOWS

extern Pio::Application* Pio::CreateApplication();

int main(int argc, char** argv) {
	Pio::Log::Init();
	//Pio::Log::GetCoreLogger()->warn("Initialized Log");
	//Pio::Log::GetClientLogger()->info("Hello");
	//PIO_CORE_WARN("Initialized Log");
	int a = 5;
	//PIO_INFO("Hello! Var={0}",a);

	auto app = Pio::CreateApplication();
	app->Run();
	delete app;
}

#endif // PIO_PLATFORM_WINDOWS
