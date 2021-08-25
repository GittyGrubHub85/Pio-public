#include "piopch.h"
#include "Application.h"

#include "Log.h"

#include <GLFW/glfw3.h>

namespace Pio {

#define BIND_EVEN_FN(x) std::bind(&Application::x, this, std::placeholders::_1)// code 1 (uncomment if code 1 seteventcallback was also uncommented)
//#define BIND_EVEN_FN(x) std::bind(&x, this, std::placeholders::_1)// code 2 (uncomment if code 2 seteventcallback was also uncommented)

	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
		//m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));//This was the first code he wrote before he used Macros below this line.
		m_Window->SetEventCallback(BIND_EVEN_FN(OnEvent));//code 1
		//m_Window->SetEventCallback(BIND_EVEN_FN(Application::OnEvent));//code 2
	}

	Application::~Application() {

	}

	void Application::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVEN_FN(OnWindowClosed));
		PIO_CORE_TRACE("{0}", e);
	}

	void Application::Run() {

		while (m_Running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
		//glfwTerminate(); //Removing this function in part 12 I already had OnWindowClosed now otherwise I get a GLFW not initialized error.
	}

	bool Application::OnWindowClosed(WindowCloseEvent& e) {
		m_Running = false;
		return true;
	}

	

}