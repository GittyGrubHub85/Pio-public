#pragma once

#include "piopch.h"

#include "Pio/Core.h"
#include "Pio/Events/Event.h"

namespace Pio {

	struct WindowProps {
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Pio Engine",
			unsigned int width = 1280,
			unsigned int height = 720)
			: Title(title), Width(width), Height(height) {
			
		}
	};

	// Interface representing a desktop system based Window
	class PIO_API Window {
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		//Mobile applcations don't use Window, they use surface.
		virtual ~Window() {} //This is a virtual deconstructor? Yes it is. He said virtual destructor.

		//He said these functions doesn't apply any data to this class (which he mentioned 15 minutes later). Which means virtual functions doesn't apply any data on this? It's only meant to be implemented on platforms.
		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		//Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());

	};

}