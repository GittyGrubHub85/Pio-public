#pragma once
#pragma once

#ifdef PIO_PLATFORM_WINDOWS
	#ifdef PIO_BUILD_DLL
		#define PIO_API __declspec(dllexport)
	#else // PIO_BUILD_DLL
		#define PIO_API __declspec(dllimport)
	#endif
#else
	#error Pio only supports Windows!
#endif // PIO_PLATFORM_WINDOWS

#define BIT(x) (1 << x)