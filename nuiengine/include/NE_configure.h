//  **************************************
//  File:        Ne_configure.h
//  Copyright:   Copyright(C) 2013-2017 Wuhan KOTEI Informatics Co., Ltd. All rights reserved.
//  Website:     http://www.nuiengine.com
//  Description: This code is part of NUI Engine (NUI Graphics Lib)
//  Comments:
//  Rev:         2
//  Created:     2017/4/12
//  Last edit:   2017/4/28
//  Author:      Chen Zhi
//  E-mail:      cz_666@qq.com
//  License: APACHE V2.0 (see license file) 
//  ***************************************

#ifndef _NE_CONFIGURE_H_
#define _NE_CONFIGURE_H_

#define _LINUX_PLATFORM		0x01
#define _WIN32_PLATFORM		0x02
#define _WINCE_PLATFORM		0x03

// OS Platform
#if defined(_WIN32_WCE)
	#define _CURRENT_PLATFORM _WINCE_PLATFORM
	#ifndef WIN32
		#define WIN32
	#endif
#elif defined(_WINDOWS)
    #define _CURRENT_PLATFORM _WIN32_PLATFORM
    #ifndef WIN32
        #define WIN32
    #endif
#else
    #define _CURRENT_PLATFORM _LINUX_PLATFORM
    #define LINUX
#endif // OS Platform

#ifdef WIN32
    #define WIN32_LEAN_AND_MEAN		// 从 Windows 头中排除极少使用的资料

    #include <windows.h>
    #include <tchar.h>
#endif

// C++ Compiler
#if   _CURRENT_PLATFORM == _LINUX_PLATFORM
    #ifndef KOTEI_GCC
		#include "LINUXTCHAR.h"
        #define KOTEI_GCC
    #endif
#elif _CURRENT_PLATFORM == _WIN32_PLATFORM
    #ifndef KOTEI_VC
        #define KOTEI_VC
    #endif
#elif _CURRENT_PLATFORM == _WINCE_PLATFORM
    #ifndef KOTEI_EVC
        #define KOTEI_EVC
    #endif
#endif // C++ Compiler

// 定义DEBUG和_DEBUG宏
#if defined(KOTEI_EVC) && defined(DEBUG) && !defined(_DEBUG)
    #define _DEBUG
#endif

#if defined(KOTEI_VC) && defined(_DEBUG) && !defined(DEBUG)
    #define DEBUG
#endif // DEBUG

#ifdef IOS_DEV
	#include "LINUXTCHAR.h"
#endif
#endif // _NE_CONFIGURE_H_
