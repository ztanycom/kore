#pragma once

#ifdef KR_PLATFORM_WINDOWS
	#ifdef KR_BUILD_DLL
		#define Kore_API __declspec(dllexport)
	#else
		#define Kore_API __declspec(dllimport)
	#endif
#else
	#error GameEngine only supports Windows
#endif