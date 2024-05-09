#ifndef _STR_X_
#define _STR_X_

#ifdef __cplusplus
	#define _STR_X_API_ extern "C"
#else // !C++
	#define _STR_X_API_ extern
#endif

#include "Typedef.h"

#ifndef __SAL_H_VERSION
	#define _Inout_z_cap_(expr)
	#define _In_z_
	#define _Out_z_cap_(expr)
	#define _Outptr_
	#define _In_
#endif

_STR_X_API_ SizeOF __stdcall StrW_Count(
	_In_z_ const pStrW pchStr
);

_STR_X_API_ SizeOF __stdcall StrA_Count(
	_In_z_ const pStrA pchStr
);

#ifdef UNICODE
	#define Str_Count StrW_Count
#else // ANSI
	#define Str_Count StrA_Count
#endif

_STR_X_API_ pStrW __stdcall StrW_Copy(
	_Out_z_cap_(cchMax) pStrW pchDest,
	_In_ SizeOF cchMax,
	_In_z_ const pStrW pchSrc
);

_STR_X_API_ pStrA __stdcall StrA_Copy(
	_Out_z_cap_(cchMax) pStrA pchDest,
	_In_ SizeOF cchMax,
	_In_z_ const pStrA pchSrc
);

#ifdef UNICODE
	#define Str_Copy StrW_Copy
#else // ANSI
	#define Str_Copy StrA_Copy
#endif

_STR_X_API_ pStrW __stdcall StrW_Cat(
	_Inout_z_cap_(cchMax) pStrW pchDest,
	_In_ SizeOF cchMax,
	_In_z_ const pStrW pchSrc
);

_STR_X_API_ pStrA __stdcall StrA_Cat(
	_Inout_z_cap_(cchMax) pStrA pchDest,
	_In_ SizeOF cchMax,
	_In_z_ const pStrA pchSrc
);

#ifdef UNICODE
	#define Str_Cat StrW_Cat
#else // ANSI
	#define Str_Cat StrA_Cat
#endif

//*! @returns Strings are Equal: (True)
//*! @returns Strings are Not Equal: (False)
_STR_X_API_ Bool __stdcall StrW_Cmp(
	_In_z_ const pStrW pchCmp,
	_In_z_ const pStrW pchStr,
	_In_ Bool iCase
);

//*! @returns Strings are Equal: (True)
//*! @returns Strings are Not Equal: (False)
_STR_X_API_ Bool __stdcall StrA_Cmp(
	_In_z_ const pStrA pchCmp,
	_In_z_ const pStrA pchStr,
	_In_ Bool iCase
);

#ifdef UNICODE
	#define Str_Cmp StrW_Cmp
#else // ANSI
	#define Str_Cmp StrA_Cmp
#endif

#endif // !_STR_X_
