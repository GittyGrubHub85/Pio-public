#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Pio {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication)) {
			PIO_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput)) {
			PIO_TRACE(e);
		}

		while (true);
	}

}