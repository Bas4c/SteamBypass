#ifndef _TYPEDEF_
#define _TYPEDEF_

// ----
// Generic Pointer
// ----

typedef void *pVoid;

// ----
// Bit Fields
// ----

typedef unsigned char    Byte,  *pByte;  /*  (8 Bits) */
typedef unsigned __int16 Word,  *pWord;  /* (16 Bits) */
typedef unsigned __int32 Dword, *pDword; /* (32 Bits) */
typedef unsigned __int64 Qword, *pQword; /* (64 Bits) */

// ----
// Signed Integers
// ----

typedef char    Int8,  *pInt8;

#define Int8_MIN ((Int8)(0x80))
#define Int8_MAX ((Int8)(0x7F))

typedef __int16 Int16, *pInt16;

#define Int16_MIN ((Int16)(0x8000))
#define Int16_MAX ((Int16)(0x7FFF))

typedef __int32	Int32, *pInt32;

#define Int32_MIN ((Int32)(0x80000000))
#define Int32_MAX ((Int32)(0x7FFFFFFF))

typedef __int64 Int64, *pInt64;

#define Int64_MIN ((Int64)(0x8000000000000000))
#define Int64_MAX ((Int64)(0x7FFFFFFFFFFFFFFF))

// ----
// Unsigned Integers
// ----

typedef unsigned char    Uint8,  *pUint8;

#define Uint8_MIN ((Uint8)(0x00))
#define Uint8_MAX ((Uint8)(0xFF))

typedef unsigned __int16 Uint16, *pUint16;

#define Uint16_MIN ((Uint16)(0x0000))
#define Uint16_MAX ((Uint16)(0xFFFF))

typedef unsigned __int32 Uint32, *pUint32;

#define Uint32_MIN ((Uint32)(0x00000000))
#define Uint32_MAX ((Uint32)(0xFFFFFFFF))

typedef unsigned __int64 Uint64, *pUint64;

#define Uint64_MIN ((Uint64)(0x0000000000000000))
#define Uint64_MAX ((Uint64)(0xFFFFFFFFFFFFFFFF))

// ----
// Floating Point (IEEE 754)
// ----

typedef float  Float, *pFloat;

#define Float_MAX ((Float)(3.40282347E+38F))
#define Float_MIN ((Float)(1.17549435E-38F))

typedef double Double, *pDouble;

#define Double_MAX ((Double)(1.7976931348623157E+308))
#define Double_MIN ((Double)(2.2250738585072014E-308))

// ----
// Chars And Strings
// ----

#ifdef _MSC_VER
	#ifdef __cplusplus
		typedef const wchar_t          CCharW, *pCStrW;
		typedef wchar_t                CharW,  *pStrW;
	#else // !C++
		typedef const unsigned __int16 CCharW, *pCStrW;
		typedef unsigned __int16       CharW,  *pStrW;
	#endif
#else
	typedef const unsigned __int16 CCharW, *pCStrW;
	typedef unsigned __int16       CharW,  *pStrW;
#endif

typedef const char             CCharA, *pCStrA;
typedef char                   CharA,  *pStrA;

#ifdef UNICODE
	typedef CCharW CCharT, *pCStrT;
	typedef CharW  CharT,  *pStrT;
	#define T(quote) L ##quote
#else // ANSI
	typedef CCharA CCharT, *pCStrT;
	typedef CharA  CharT,   *pStrT;
	#define T(quote) quote
#endif

// ----
// Size of Memory
// ----

#ifdef _WIN64
	typedef Uint64 SizeOF, *pSizeOF;
	#define SizeOF_MIN Uint64_MIN
	#define SizeOF_MAX Uint64_MAX
#else // Win32 (x86)
	typedef Uint32 SizeOF, *pSizeOF;
	#define SizeOF_MIN Uint32_MIN
	#define SizeOF_MAX Uint32_MAX
#endif

// ----
// Conditional Expressions
// ----

#ifdef __cplusplus
	typedef bool  Bool, *pBool;
#else // !C++
	typedef _Bool Bool, *pBool;
#endif

#define False 0
#define True  1

// ----
// Invalid Pointer
// ----

#ifndef NULL
	#define NULL ((pVoid)(0))
#endif

#endif // !_TYPEDEF_
