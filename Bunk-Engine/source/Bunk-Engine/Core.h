#pragma once

#ifdef _WIN64
	#ifdef BNK_BUILD_DLL
		#define BNK_API __declspec(dllexport)
	#else
		#define BNK_API __declspec(dllimport)
	#endif // BNK_BUILD_DLL
#else
	#error Bunk-Engine so far only supports windows x64
#endif // _WIN64