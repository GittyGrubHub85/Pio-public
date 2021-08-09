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

#ifdef PIO_ENABLE_ASSERTS
	#define PIO_ASSERT(x, ...) { if(!(x)) {PIO_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define PIO_CORE_ASSERT(x, ...) { if(!(x)) { PIO_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define PIO_ASSERT(x, ...)
	#define PIO_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)