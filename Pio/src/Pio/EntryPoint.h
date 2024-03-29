#pragma once

#ifdef PIO_PLATFORM_WINDOWS

extern Pio::Application* Pio::CreateApplication();

int main(int argc, char** argv) {
	Pio::Log::Init();
	//Pio::Log::GetCoreLogger()->warn("Initialized Log");
	//Pio::Log::GetClientLogger()->info("Hello");
	PIO_CORE_WARN("Initialized Log");
	int a = 5;
	PIO_INFO("Hello! Var={0}",a);
	//PIO_TRACE("PIO_TRACE");//This one doesn't show an output (but it's now fixed, it's in Log.cpp at line 17)
	//PIO_FATAL("a09diwa9d");//This one shows an error saying this is not a member (not yet fixed)
	//PIO_ERROR("PIO_ERROR");

	auto app = Pio::CreateApplication();
	app->Run();
	delete app;
}

#endif // PIO_PLATFORM_WINDOWS
