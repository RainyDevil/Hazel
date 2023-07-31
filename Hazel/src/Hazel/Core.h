#pragma once

#ifdef HAZEL_PLATFORM_WINDOWS
	#ifdef HAZEL_BUILD_DLL
		#define HAZEL_DLL_API __declspec(dllexport)
	#else
		#define HAZEL_DLL_API __declspec(dllimport)
	#endif
#else
	#error Hazel now only support Windows!
#endif