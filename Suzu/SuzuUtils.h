#pragma once

#ifdef SUZU_WINDOWS
	#ifdef SUZU_LIB
		#define SUZU_API __declspec(dllexport)
	#else
		#define SUZU_API __declspec(dllexport)
	#endif
#else 
	#define SUZU_API
#endif