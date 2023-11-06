#include <iostream>
#include <string>
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
	#ifdef _WIN64
		//64 Bit
		#include <windows.h>
	#else
		//32 Bit
		#include <windows.h>
	#endif
#elif __linux__
	#include <unistd.h>
#elif TARGET_OS_MAC
	//kutuphane eklenecek
#endif

using namespace std;