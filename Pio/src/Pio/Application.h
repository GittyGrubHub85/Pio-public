#pragma once

#include "Core.h" //My very own created Core.h header I've seen this kind of file name in Godot's github repository.
#include "Events/Event.h"

namespace Pio {


	class PIO_API Application
	{
	public:
		Application();//This is a constructor.
		virtual ~Application(); //Cherno added this without explaining it. I still don't know how this works but my guess is when the application shuts down or closes. He said this is a Destructor. It has to be virtual because the class will inherit worldstart(I couldn't hear well) class by the sandbox which it will be making an application which inherits from Pio application.

		void Run();
	};

	// To be defined in the client
	Application* CreateApplication();
}