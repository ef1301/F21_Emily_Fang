#pragma once

#ifdef SUZU_WINDOWS
	#ifdef SUZU_LIB
		#define SUZU_API __declspec(dllexport)
	#else
		#define SUZU_API __declspec(dllimport) //was dllexport
	#endif
#else 
	#define SUZU_API
#endif

#ifdef SUZU_DEBUG
	#define SUZU_LOG(x) std::cout << x << std::endl;
#else 
	#define SUZU_LOG(x)
#endif