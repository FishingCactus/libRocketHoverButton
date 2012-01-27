#ifndef ROCKETHOVERBUTTONHEADER_H
#define ROCKETHOVERBUTTONHEADER_H

#include <Rocket/Core/Platform.h>

#if !defined STATIC_LIB
	#ifdef ROCKET_PLATFORM_WIN32
		#ifdef RocketHoverButton_EXPORTS
			#define ROCKETHOVERBUTTON_API __declspec(dllexport)
		#else
			#define ROCKETHOVERBUTTON_API __declspec(dllimport)
		#endif
	#else
		#define ROCKETHOVERBUTTON_API __attribute__((visibility("default")))
	#endif
#else
	#define ROCKETHOVERBUTTON_API
#endif

#endif
