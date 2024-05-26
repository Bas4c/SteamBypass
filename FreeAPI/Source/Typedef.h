#ifndef _TYPEDEF_
#define _TYPEDEF_

// ----
// Generic Pointer
// ----

typedef const void *pCVoid;
typedef void       *pVoid;

// ----
// Bit Fields
// ----

typedef const unsigned char    CByte,  *pCByte;  /*  (8 Bits) */
typedef unsigned char          Byte,   *pByte;   /*  (8 Bits) */
typedef const unsigned __int16 CWord,  *pCWord;  /* (16 Bits) */
typedef unsigned __int16       Word,   *pWord;   /* (16 Bits) */
typedef const unsigned __int32 CDword, *pCDword; /* (32 Bits) */
typedef unsigned __int32       Dword,  *pDword;  /* (32 Bits) */
typedef const unsigned __int64 CQword, *pCQword; /* (64 Bits) */
typedef unsigned __int64       Qword,  *pQword;  /* (64 Bits) */

// ----
// Signed Integers
// ----

typedef const char    CInt8,  *pCInt8;
typedef char          Int8,   *pInt8;

#define Int8_MIN ((Int8)(0x80))
#define Int8_MAX ((Int8)(0x7F))

typedef const __int16 CInt16, *pCInt16;
typedef __int16       Int16,  *pInt16;

#define Int16_MIN ((Int16)(0x8000))
#define Int16_MAX ((Int16)(0x7FFF))

typedef const __int32 CInt32, *pCInt32;
typedef __int32	      Int32,  *pInt32;

#define Int32_MIN ((Int32)(0x80000000))
#define Int32_MAX ((Int32)(0x7FFFFFFF))

typedef const __int64 CInt64, *pCInt64;
typedef __int64       Int64,  *pInt64;

#define Int64_MIN ((Int64)(0x8000000000000000))
#define Int64_MAX ((Int64)(0x7FFFFFFFFFFFFFFF))

// ----
// Unsigned Integers
// ----

typedef const unsigned char    CUint8,  *pCUint8;
typedef unsigned char          Uint8,   *pUint8;

#define Uint8_MIN ((Uint8)(0x00))
#define Uint8_MAX ((Uint8)(0xFF))

typedef const unsigned __int16 CUint16, *pCUint16;
typedef unsigned __int16       Uint16,  *pUint16;

#define Uint16_MIN ((Uint16)(0x0000))
#define Uint16_MAX ((Uint16)(0xFFFF))

typedef const unsigned __int32 CUint32, *pCUint32;
typedef unsigned __int32       Uint32,  *pUint32;

#define Uint32_MIN ((Uint32)(0x00000000))
#define Uint32_MAX ((Uint32)(0xFFFFFFFF))

typedef const unsigned __int64 CUint64, *pCUint64;
typedef unsigned __int64       Uint64,  *pUint64;

#define Uint64_MIN ((Uint64)(0x0000000000000000))
#define Uint64_MAX ((Uint64)(0xFFFFFFFFFFFFFFFF))

// ----
// Floating Point (IEEE 754)
// ----

typedef const float  CFloat,  *pCFloat;
typedef float        Float,   *pFloat;

#define Float_MAX ((Float)(3.40282347E+38F))
#define Float_MIN ((Float)(1.17549435E-38F))

typedef const double CDouble, *pCDouble;
typedef double       Double,  *pDouble;

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
	typedef CUint64 CSizeOF, *pCSizeOF;
	typedef Uint64  SizeOF,  *pSizeOF;
	#define SizeOF_MIN Uint64_MIN
	#define SizeOF_MAX Uint64_MAX
#else // Win32 (x86)
	typedef CUint32 CSizeOF, *pCSizeOF;
	typedef Uint32  SizeOF,  *pSizeOF;
	#define SizeOF_MIN Uint32_MIN
	#define SizeOF_MAX Uint32_MAX
#endif

// ----
// Conditional Expressions
// ----

#ifdef __cplusplus
	typedef const bool  CBool, *pCBool;
	typedef bool        Bool,  *pBool;
#else // !C++
	typedef const _Bool CBool, *pCBool;
	typedef _Bool       Bool,  *pBool;
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
