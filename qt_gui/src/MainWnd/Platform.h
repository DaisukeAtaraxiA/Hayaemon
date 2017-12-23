﻿//----------------------------------------------------------------------------
// Platform.h : プラットフォーム依存の関数
//----------------------------------------------------------------------------
#ifndef PlatformH
#define PlatformH

#if WIN32
#include <tchar.h>

#elif __APPLE__

#include "../Common/Define.h"

//----------------------------------------------------------------------------
// Windows固有のAPIを実装
//----------------------------------------------------------------------------
#ifdef UNICODE
# define lstrcpy wcscpy
template <size_t N, typename ... Args>
int _stprintf_s(wchar_t (&buf)[N], const wchar_t *format, Args const & ... args)
{
	swprintf(buf, N, format, args ...);
}
#else
# define lstrcpy strcpy
# define _stprintf_s sprintf
#endif

UINT GetPrivateProfileInt(LPCTSTR lpAppName, LPCTSTR lpKeyName, int nDefault,
													LPCTSTR lpFileName);
BOOL WritePrivateProfileString(LPCTSTR lpAppName, LPCTSTR lpKeyName,
															 LPCTSTR lpString, LPCTSTR lpFileName);
#endif

#endif // PlatformH
