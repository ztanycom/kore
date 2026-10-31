#pragma once

#ifdef KR_PLATFORM_WINDOWS
	#ifdef KR_BUILD_DLL
		#define KORE_API __declspec(dllexport)
	#else
		#define KORE_API __declspec(dllimport)
	#endif
#else
	#error GameEngine only supports Windows
#endif

#define BIT(x) (1 <<x)   //位运算宏，生成一个第X位为1，其余位为0的二进制整数