﻿//--------------------------------------------------------------------------
// Define.h : 共通定義
//--------------------------------------------------------------------------
#ifndef DefineH
#define DefineH

#include <stdint.h>
#include <string>

//--------------------------------------------------------------------------
// DEFINITION
//--------------------------------------------------------------------------
#ifndef _T
# ifdef UNICODE
#  define _T(x) L ## x
# else
#  define _T(x) x
# endif
#endif

#ifndef TRUE
# define TRUE 1
#endif
#ifndef FALSE
# define FALSE 0
#endif
#ifndef LVCFMT_LEFT
# define LVCFMT_LEFT 0
#endif
#ifndef LVCFMT_RIGHT
# define LVCFMT_RIGHT 1
#endif

//--------------------------------------------------------------------------
// TYPES
//--------------------------------------------------------------------------
typedef int BOOL;
typedef long LONG;
typedef unsigned int UINT;
typedef unsigned long long UINT_PTR;
typedef uint64_t QWORD;
typedef long long LRESULT;

#ifdef UNICODE
typedef wchar_t TCHAR;
#else
typedef char TCHAR;
#endif
typedef const TCHAR *LPCTSTR;

typedef std::basic_string<TCHAR> tstring;

#ifndef SW_HIDE
# define SW_HIDE 0
#endif
#ifndef SW_SHOW
# define SW_SHOW 5
#endif

#ifndef MF_UNCHECKED
# define MF_UNCHECKED        0x00000000L
#endif
#ifndef MF_CHECKED
# define MF_CHECKED          0x00000008L
#endif
#ifndef MF_ENABLED
# define MF_ENABLED          0x00000008L
#endif
#ifndef MFS_GRAYED
# define MFS_GRAYED          0x00000003L
#endif
#ifndef MFS_ENABLED
# define MFS_ENABLED         MF_ENABLED
#endif
#ifndef MFS_DISABLED
# define MFS_DISABLED        MF_GRAYED
#endif

#endif // DefineH
