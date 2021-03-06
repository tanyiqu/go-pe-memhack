#include "stdafx.h"
#include "PokemonTool.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
static CONST WCHAR wcMapperJ[] = {
/*        0      1      2      3      4      5      6      7      8      9      A      B      C      D      E      F    */
/* 0 */	L'　', L'あ', L'い', L'う', L'え', L'お', L'か', L'き', L'く', L'け', L'こ', L'さ', L'し', L'す', L'せ', L'そ',
/* 1 */	L'た', L'ち', L'つ', L'て', L'と', L'な', L'に', L'ぬ', L'ね', L'の', L'は', L'ひ', L'ふ', L'へ', L'ほ', L'ま',
/* 2 */	L'み', L'む', L'め', L'も', L'や', L'ゆ', L'よ', L'ら', L'り', L'る', L'れ', L'ろ', L'わ', L'を', L'ん', L'ぁ',
/* 3 */	L'ぃ', L'ぅ', L'ぇ', L'ぉ', L'ゃ', L'ゅ', L'ょ', L'が', L'ぎ', L'ぐ', L'げ', L'ご', L'ざ', L'じ', L'ず', L'ぜ',
/* 4 */	L'ぞ', L'だ', L'ぢ', L'づ', L'で', L'ど', L'ば', L'び', L'ぶ', L'べ', L'ぼ', L'ぱ', L'ぴ', L'ぷ', L'ぺ', L'ぽ',
/* 5 */	L'っ', L'ア', L'イ', L'ウ', L'エ', L'オ', L'カ', L'キ', L'ク', L'ケ', L'コ', L'サ', L'シ', L'ス', L'セ', L'ソ',
/* 6 */	L'タ', L'チ', L'ツ', L'テ', L'ト', L'ナ', L'ニ', L'ヌ', L'ネ', L'ノ', L'ハ', L'ヒ', L'フ', L'ヘ', L'ホ', L'マ',
/* 7 */	L'ミ', L'ム', L'メ', L'モ', L'ヤ', L'ユ', L'ヨ', L'ラ', L'リ', L'ル', L'レ', L'ロ', L'ワ', L'ヲ', L'ン', L'ァ',
/* 8 */	L'ィ', L'ゥ', L'ェ', L'ォ', L'ャ', L'ュ', L'ョ', L'ガ', L'ギ', L'グ', L'ゲ', L'ゴ', L'ザ', L'ジ', L'ズ', L'ゼ',
/* 9 */	L'ゾ', L'ダ', L'ヂ', L'ヅ', L'デ', L'ド', L'バ', L'ビ', L'ブ', L'ベ', L'ボ', L'パ', L'ピ', L'プ', L'ペ', L'ポ',
/* A */	L'ッ', L'０', L'１', L'２', L'３', L'４', L'５', L'６', L'７', L'８', L'９', L'！', L'？', L'。', L'ー', L'・',
/* B */	L'‥', L'『', L'』', L'「', L'」', L'♂', L'♀', L'円', L'．', L'×', L'／', L'Ａ', L'Ｂ', L'Ｃ', L'Ｄ', L'Ｅ',
/* C */	L'Ｆ', L'Ｇ', L'Ｈ', L'Ｉ', L'Ｊ', L'Ｋ', L'Ｌ', L'Ｍ', L'Ｎ', L'Ｏ', L'Ｐ', L'Ｑ', L'Ｒ', L'Ｓ', L'Ｔ', L'Ｕ',
/* D */	L'Ｖ', L'Ｗ', L'Ｘ', L'Ｙ', L'Ｚ', L'ａ', L'ｂ', L'ｃ', L'ｄ', L'ｅ', L'ｆ', L'ｇ', L'ｈ', L'ｉ', L'ｊ', L'ｋ',
/* E */	L'ｌ', L'ｍ', L'ｎ', L'ｏ', L'ｐ', L'ｑ', L'ｒ', L'ｓ', L'ｔ', L'ｕ', L'ｖ', L'ｗ', L'ｘ', L'ｙ', L'ｚ', L'＞',
/* F */	L'：', L'Α', L'Β', L'Γ', L'α', L'β', L'γ', L'↑', L'↓', L'←', L'▼', L'　', L'　', L'　', L'\n', L'　'};

//static CONST WCHAR wcMapperE[] = {
///*        0      1      2      3      4      5      6      7      8      9      A      B      C      D      E      F    */
///* 0 */	L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　',
///* 1 */	L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'￡', L'　', L'　', L'　', L'　',
///* 2 */	L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'＆', L'＋', L'　',
///* 3 */	L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　',
///* 4 */	L'　', L'　', L'　', L'　', L'　', L'＝', L'；', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　',
///* 5 */	L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'％', L'（', L'）', L'　', L'　',
///* 6 */	L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　',
///* 7 */	L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'↑', L'↓', L'←', L'→', L'　', L'　', L'　',
///* 8 */	L'　', L'　', L'　', L'　', L'　', L'＜', L'＞', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　',
///* 9 */	L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　',
///* A */	L'　', L'０', L'１', L'２', L'３', L'４', L'５', L'６', L'７', L'８', L'９', L'！', L'？', L'。', L'－', L'・',
///* B */	L'…', L'“', L'”', L'‘', L'’', L'♂', L'♀', L'￡', L'，', L'×', L'／', L'Ａ', L'Ｂ', L'Ｃ', L'Ｄ', L'Ｅ',
///* C */	L'Ｆ', L'Ｇ', L'Ｈ', L'Ｉ', L'Ｊ', L'Ｋ', L'Ｌ', L'Ｍ', L'Ｎ', L'Ｏ', L'Ｐ', L'Ｑ', L'Ｒ', L'Ｓ', L'Ｔ', L'Ｕ',
///* D */	L'Ｖ', L'Ｗ', L'Ｘ', L'Ｙ', L'Ｚ', L'ａ', L'ｂ', L'ｃ', L'ｄ', L'ｅ', L'ｆ', L'ｇ', L'ｈ', L'ｉ', L'ｊ', L'ｋ',
///* E */	L'ｌ', L'ｍ', L'ｎ', L'ｏ', L'ｐ', L'ｑ', L'ｒ', L'ｓ', L'ｔ', L'ｕ', L'ｖ', L'ｗ', L'ｘ', L'ｙ', L'ｚ', L'＞',
///* F */	L'：', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'　', L'▼', L'　', L'　', L'　', L'\n', L'　'};

///////////////////////////////////////////////////////////////////////////////////////////////////
//static CONST WCHAR wcMapperJ[] = {
///*        0      1      2      3      4      5      6      7      8      9      A      B      C      D      E      F    */
///* 0 */	L'　', L'あ', L'い', L'う', L'え', L'お', L'か', L'き', L'く', L'け', L'こ', L'さ', L'し', L'す', L'せ', L'そ',
///* 1 */	L'た', L'ち', L'つ', L'て', L'と', L'な', L'に', L'ぬ', L'ね', L'の', L'は', L'ひ', L'ふ', L'へ', L'ほ', L'ま',
///* 2 */	L'み', L'む', L'め', L'も', L'や', L'ゆ', L'よ', L'ら', L'り', L'る', L'れ', L'ろ', L'わ', L'を', L'ん', L'ぁ',
///* 3 */	L'ぃ', L'ぅ', L'ぇ', L'ぉ', L'ゃ', L'ゅ', L'ょ', L'が', L'ぎ', L'ぐ', L'げ', L'ご', L'ざ', L'じ', L'ず', L'ぜ',
///* 4 */	L'ぞ', L'だ', L'ぢ', L'づ', L'で', L'ど', L'ば', L'び', L'ぶ', L'べ', L'ぼ', L'ぱ', L'ぴ', L'ぷ', L'ぺ', L'ぽ',
///* 5 */	L'っ', L'ア', L'イ', L'ウ', L'エ', L'オ', L'カ', L'キ', L'ク', L'ケ', L'コ', L'サ', L'シ', L'ス', L'セ', L'ソ',
///* 6 */	L'タ', L'チ', L'ツ', L'テ', L'ト', L'ナ', L'ニ', L'ヌ', L'ネ', L'ノ', L'ハ', L'ヒ', L'フ', L'ヘ', L'ホ', L'マ',
///* 7 */	L'ミ', L'ム', L'メ', L'モ', L'ヤ', L'ユ', L'ヨ', L'ラ', L'リ', L'ル', L'レ', L'ロ', L'ワ', L'ヲ', L'ン', L'ァ',
///* 8 */	L'ィ', L'ゥ', L'ェ', L'ォ', L'ャ', L'ュ', L'ョ', L'ガ', L'ギ', L'グ', L'ゲ', L'ゴ', L'ザ', L'ジ', L'ズ', L'ゼ',
///* 9 */	L'ゾ', L'ダ', L'ヂ', L'ヅ', L'デ', L'ド', L'バ', L'ビ', L'ブ', L'ベ', L'ボ', L'パ', L'ピ', L'プ', L'ペ', L'ポ',
///* A */	L'ッ', L'0',  L'1',  L'2',  L'3',  L'4',  L'5',  L'6',  L'7',  L'8',  L'9',  L'！', L'？', L'。', L'ー', L'・',
///* B */	L'…', L'『', L'』', L'「', L'」', L'♂', L'♀', L'円', L'．', L'×', L'／', L'A',  L'B',  L'C',  L'D',  L'E',
///* C */	L'F',  L'G',  L'H',  L'I',  L'J',  L'K',  L'L',  L'M',  L'N',  L'O',  L'P',  L'Q',  L'R',  L'S',  L'T',  L'U',
///* D */	L'V',  L'W',  L'X',  L'Y',  L'Z',  L'a',  L'b',  L'c',  L'd',  L'e',  L'f',  L'g',  L'h',  L'i',  L'j',  L'k',
///* E */	L'l',  L'm',  L'n',  L'o',  L'p',  L'q',  L'r',  L's',  L't',  L'u',  L'v',  L'w',  L'x',  L'y',  L'z',  L'＞',
///* F */	L'：', L'Α', L'Β', L'Γ', L'α', L'β', L'γ', L'↑', L'↓', L'←', L'▼', L'　', L'　', L'　', L'\n', L'　'};

static CONST WCHAR wcMapperE[] = {
/*        0      1      2      3      4      5      6      7      8      9      A      B      C      D      E      F    */
/* 0 */	L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ', 
/* 1 */	L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L'é',  L' ',  L' ',  L' ',  L' ', 
/* 2 */	L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L'&',  L'+',  L' ', 
/* 3 */	L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ', 
/* 4 */	L' ',  L' ',  L' ',  L' ',  L' ',  L'=',  L';',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ', 
/* 5 */	L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L'%',  L'(',  L')',  L' ',  L' ', 
/* 6 */	L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ', 
/* 7 */	L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L'↑', L'↓', L'←', L'→', L' ',  L' ',  L' ', 
/* 8 */	L' ',  L' ',  L' ',  L' ',  L' ',  L'<',  L'>',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ', 
/* 9 */	L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ', 
/* A */	L' ',  L'0',  L'1',  L'2',  L'3',  L'4',  L'5',  L'6',  L'7',  L'8',  L'9',  L'!',  L'?',  L'.',  L'-',  L'·',
/* B */	L'…', L'\"', L'\"', L'\'', L'\'', L'♂', L'♀', L'￡', L',',  L'×', L'／', L'A',  L'B',  L'C',  L'D',  L'E',
/* C */	L'F',  L'G',  L'H',  L'I',  L'J',  L'K',  L'L',  L'M',  L'N',  L'O',  L'P',  L'Q',  L'R',  L'S',  L'T',  L'U',
/* D */	L'V',  L'W',  L'X',  L'Y',  L'Z',  L'a',  L'b',  L'c',  L'd',  L'e',  L'f',  L'g',  L'h',  L'i',  L'j',  L'k',
/* E */	L'l',  L'm',  L'n',  L'o',  L'p',  L'q',  L'r',  L's',  L't',  L'u',  L'v',  L'w',  L'x',  L'y',  L'z',  L'＞',
/* F */	L':',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L' ',  L'▼', L' ',  L' ',  L' ',  L'\n', L' '};

static CONST DWORD dwMapperSize = sizeof(wcMapperJ) / sizeof(wcMapperJ[0]);

DWORD CodeToString(LPTSTR *pszString, LPBYTE pbCode, DWORD cbCodeLength, BYTE bTerminatingCode, DWORD dwLang)
{
	DWORD	n, cchUnicode;
	LPWSTR	wszString = NULL;
	LPCWSTR	wcMapper;

	if(dwLang == lang_en)
		wcMapper = wcMapperE;
	else
		wcMapper = wcMapperJ;

	#ifndef UNICODE
	DWORD	cchAnsi;
	LPSTR	szString = NULL;
	#endif

	try
	{
		if(pszString == NULL || pbCode == NULL || cbCodeLength == 0)
			throw 0;

		*pszString = NULL;

		// get the unicode string length
		for(n = 0; n < cbCodeLength; ++n)
		{
			if(pbCode[n] == 0xFF || pbCode[n] == bTerminatingCode)
				break;
		}
		if(n == 0)
			throw 0;
		cchUnicode = n + 1;

		// get the unicode string
		wszString = reinterpret_cast<LPWSTR>(LocalAlloc(LMEM_FIXED, cchUnicode * sizeof(WCHAR)));
		if(wszString == NULL)
			throw 0;

		for(n = 0; n < cbCodeLength && n < cchUnicode; ++n)
		{
			wszString[n] = wcMapper[pbCode[n]];
		}
		if(cbCodeLength < cchUnicode)
			wszString[cbCodeLength] = L'\0';
		else
			wszString[cchUnicode - 1] = L'\0';

		#ifndef UNICODE
		// convert unicode to ansi
		cchAnsi = WideCharToMultiByte(CP_ACP, 0, wszString, cchUnicode, NULL, 0, NULL, NULL);
		if(cchAnsi == 0)
			throw 0;

		szString = reinterpret_cast<LPSTR>(LocalAlloc(LMEM_FIXED, cchAnsi * sizeof(CHAR)));
		cchAnsi = WideCharToMultiByte(CP_ACP, 0, wszString, cchUnicode, szString, cchAnsi, NULL, NULL);
		if(cchAnsi == 0)
			throw 0;

		*pszString = szString;
		#else	// #ifdef UNICODE
		*pszString = wszString;
		#endif
	}
	catch(int)
	{
		#ifndef UNICODE
		cchAnsi = 0;
		#else
		cchUnicode = 0;
		#endif
	}

	#ifndef UNICODE
	if(wszString)
	{
		LocalFree(reinterpret_cast<HLOCAL>(wszString));
	}

	if(cchAnsi == 0)
	{
		if(szString)
			LocalFree(reinterpret_cast<HLOCAL>(szString));
	}
	#else	// #ifdef UNICODE
	if(cchUnicode == 0)
	{
		if(wszString)
			LocalFree(reinterpret_cast<HLOCAL>(wszString));
	}
	#endif

	#ifndef UNICODE
	return cchAnsi;
	#else
	return cchUnicode;
	#endif
}

BOOL CodeToString(CString &szString, LPBYTE pbCode, DWORD cbCodeLength, BYTE bTerminatingCode, DWORD dwLang)
{
	LPTSTR	pStr = NULL;

	if(CodeToString(&pStr, pbCode, cbCodeLength, bTerminatingCode, dwLang) != 0)
	{
		szString = pStr;
		LocalFree(reinterpret_cast<HLOCAL>(pStr));
		szString.Replace(_T("\n"), _T("\r\n"));
		return TRUE;
	}
	else
	{
		szString.Empty();
		return FALSE;
	}
}

BOOL StringToCode(LPCTSTR szString, LPBYTE pbCode, DWORD cbCodeLength, BYTE bTerminatingCode, BYTE bPaddingCode, DWORD dwLang)
{
	BOOL	br;
	DWORD	m, n;
	LPCWSTR	wcMapper;

	if(dwLang == lang_en)
		wcMapper = wcMapperE;
	else
		wcMapper = wcMapperJ;


	#ifndef UNICODE
	DWORD	cchUnicode;
	LPWSTR	wszString = NULL;
	#else	// #ifdef UNICODE
	LPCWSTR	wszString;
	#endif

	try
	{
		if(szString == NULL || pbCode == NULL || cbCodeLength == 0)
			throw 0;

		#ifndef UNICODE
		// convert ansi to unicode
		cchUnicode = MultiByteToWideChar(CP_ACP, 0, szString, -1, NULL, 0);
		if(cchUnicode == 0)
			throw 0;

		wszString = reinterpret_cast<LPWSTR>(LocalAlloc(LMEM_FIXED, cchUnicode * sizeof(WCHAR)));
		if(wszString == NULL)
			throw 0;

		cchUnicode = MultiByteToWideChar(CP_ACP, 0, szString, -1, wszString, cchUnicode);
		if(cchUnicode == 0)
			throw 0;
		#else	// #ifdef UNICODE
		wszString = szString;
		#endif

		for(m = 0; m < cbCodeLength && wszString[m] != L'\0'; ++m)
		{
			if(wszString[m] == L'\r')
			{
				continue;
			}

			for(n = 0; n < dwMapperSize; ++n)
			{
				if(wszString[m] == wcMapper[n])
				{
					pbCode[m] = static_cast<BYTE>(n);
					break;
				}
			}
			if(n >= dwMapperSize)
				break;
		}

		if(m < cbCodeLength)
		{
			pbCode[m] = bTerminatingCode;
			++m;
		}

		// add paddings
		for(; m < cbCodeLength; ++m)
		{
			pbCode[m] = bPaddingCode;
		}

		br = TRUE;
	}
	catch(int)
	{
		br = FALSE;
	}

	#ifndef UNICODE
	if(wszString)
	{
		LocalFree(reinterpret_cast<HLOCAL>(wszString));
	}
	#endif

	return br;
}

DWORD GenLongRandom(VOID)
{
	UINT	uSeed = UINT(rand()) + (UINT)(time(NULL));

	srand(uSeed);

	DWORD	dwRandValue =
			(DWORD)((rand() & 0xFF)      ) +
			(DWORD)((rand() & 0xFF) << 8 ) +
			(DWORD)((rand() & 0xFF) << 16) +
			(DWORD)((rand() & 0xFF) << 24);

	return dwRandValue;
}

WORD GenShortRandom(VOID)
{
	UINT	uSeed = UINT(rand()) + (UINT)(time(NULL));

	srand(uSeed);

	WORD	wRandValue =
			(WORD)((rand() & 0xFF)      ) +
			(WORD)((rand() & 0xFF) << 8 );

	return wRandValue;
}

WORD ConvertBreed(WORD wBreed, BOOL b387To412)
{
	WORD	wCvt = wBreed;

	if(b387To412)	// from PokemonStruct space to Rom space
	{
		if(wCvt > 386)
			wCvt = 0;
		else if(wCvt >= 252)
			wCvt += 25;
	}
	else		// from Rom space to PokemonStruct space
	{
		if (wCvt > 411)
		//if (wCvt > 800)
			wCvt = 0;
		else if(wCvt >= 277)
			wCvt -= 25;
		else if(wCvt >= 252)
			wCvt = 0;
	}

	return wCvt;
}
