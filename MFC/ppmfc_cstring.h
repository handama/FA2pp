#pragma once

#include "ppmfc_forward.h"
#include <string>
#include <algorithm>
#include <cctype>
#include <cstdarg>
#include <cstdio>
#include <stdexcept>
#include <vector>
#include <type_traits>
#include <utility>
#include <variant>

class FString;

_PPMFC_BEGIN

_PPMFC_STRUCT(CStringData)
{
    long nRefs;     // reference count
    int nDataLength;
    int nAllocLength;
    // TCHAR data[nAllocLength]

    TCHAR* data()
    {
        return (TCHAR*)(this + 1);
    }
};

_PPMFC_CLASS(CString)
{
public:
    CString() _PPMFC_THISCALL(0x406F70);
    CString(LPCTSTR lpch, int nLength) _PPMFC_THISCALL(0x54F598);
    CString(const CString & stringSrc) _PPMFC_THISCALL(0x555C84);
    CString(LPCSTR lpsz) _PPMFC_THISCALL(0x555F7D);
    CString(LPCWSTR lpsz) _PPMFC_THISCALL(0x555FCF);
    ~CString() _PPMFC_THISCALL(0x555F0F);

    CStringData* GetData() const
        { ASSERT(m_pchData != NULL); return ((CStringData*)m_pchData) - 1; }
    int GetLength() const
        { return GetData()->nDataLength; }
    int GetAllocLength() const
        { return GetData()->nAllocLength; }
    BOOL IsEmpty() const
        { return GetData()->nDataLength == 0; }

    const CString& operator=(TCHAR ch)
        _PPMFC_THISCALL(0x54F5CC);

    int Delete(int at, int length)
        _PPMFC_THISCALL(0x54F5E1);

    int Insert(int at, LPCSTR lpsz)
        _PPMFC_THISCALL(0x54F639);

    int Replace(LPCSTR from, LPCSTR to)
        _PPMFC_THISCALL(0x54F6EE);

    CString* Right(CString * stringMem, int at)
        _PPMFC_THISCALL(0x54F851);

    CString Right(int at)
        { CString ret; Right(&ret, at); return ret; }

    CString* Left(CString* stringMem, int at)
        _PPMFC_THISCALL(0x54F8CD);

    CString Left(int at)
        { CString ret; Left(&ret, at); return ret; }

    int ReverseFind(TCHAR ch) const
        _PPMFC_THISCALL(0x54F945);

    int Find(LPCTSTR lpszSub) const
        _PPMFC_THISCALL(0x54F967);

    int Find(std::string& text) const {
        return Find(text.c_str());
    }

    int Find(LPCTSTR lpszSub, int from) const
        _PPMFC_THISCALL(0x54F975);

    void TrimRight()
        _PPMFC_THISCALL(0x54F9A0);

    void TrimLeft()
        _PPMFC_THISCALL(0x54F9EC);

    void Trim()
        { TrimLeft(); TrimRight(); }

    void AllocBuffer(int nLen)
        _PPMFC_THISCALL(0x555D7C);

    void FreeData()
        _PPMFC_THISCALL(0x555DFE);

    void Release()
        _PPMFC_THISCALL(0x555E46);

    static void _PPMFC_API Release(CStringData* pStringData)
        _PPMFC_STDCALL(0x555E77);

    void Empty()
        _PPMFC_THISCALL(0x555E9A);

    void CopyBeforeWrite()
        _PPMFC_THISCALL(0x555EB8);

    void AllocBeforeWrite(int nLen)
        _PPMFC_THISCALL(0x555EE6);

    void AllocCopy(CString& dest, int nCopyLen, int nCopyIndex, int nExtraLen) const
        _PPMFC_THISCALL(0x555F39);

    void AssignCopy(int nSrcLen, LPCTSTR lpszSrcData)
        _PPMFC_THISCALL(0x55601B);

    const CString& operator=(CString& str)
        _PPMFC_THISCALL(0x556048);

    const CString& operator=(LPCSTR lpsz)
        _PPMFC_THISCALL(0x556098);

    const CString& operator=(const std::string& text) {
        return (*this = text.c_str());
    }

    const CString& operator=(LPCWSTR lpsz)
        _PPMFC_THISCALL(0x5560BF);

    void ConcatCopy(int nSrc1Len, LPCTSTR lpszSrc1Data, int nSrc2Len, LPCTSTR lpszSrc2Data)
        _PPMFC_THISCALL(0x556100);

    friend CString _PPMFC_API operator+(const CString& string1,
        const CString& string2)
        _PPMFC_STDCALL(0x55613E);

    friend CString _PPMFC_API operator+(const CString& string, LPCTSTR lpsz)
        _PPMFC_STDCALL(0x5561A4);

    friend CString operator+(const CString& string, const std::string& text) {
        return operator+(string, text.c_str()); 
    }

    friend CString _PPMFC_API operator+(LPCTSTR lpsz, const CString& string)
        _PPMFC_STDCALL(0x556218);

    void ConcatInPlace(int nSrcLen, LPCTSTR lpszSrcData)
        _PPMFC_THISCALL(0x55628C);

    const CString& operator+=(LPCTSTR lpsz)
        _PPMFC_THISCALL(0x5562EB);

    const CString& operator+=(const std::string& text) {
        return (*this += text.c_str());
    }

    const CString& operator+=(TCHAR ch)
        _PPMFC_THISCALL(0x556312);

    const CString& operator+=(const CString& string)
        _PPMFC_THISCALL(0x556327);

    LPTSTR GetBuffer(int nMinBufLength)
        _PPMFC_THISCALL(0x55633F);

    void ReleaseBuffer(int nNewLength = -1)
        _PPMFC_THISCALL(0x55638E);

    LPTSTR GetBufferSetLength(int nNewLength)
        _PPMFC_THISCALL(0x5563B6);

    int Find(TCHAR ch) const
        _PPMFC_THISCALL(0x5563D6);

    int Find(TCHAR ch, int from) const
        _PPMFC_THISCALL(0x5563E4);

    void MakeUpper()
        _PPMFC_THISCALL(0x556411);

    void MakeLower()
        _PPMFC_THISCALL(0x556423);

    void SetAt(int nIndex, TCHAR ch)
        _PPMFC_THISCALL(0x556435);

    BOOL LoadString(UINT nID)          // load from string resource, 255 chars max
        _PPMFC_THISCALL(0x556507);

    operator const char*() const
        { return m_pchData; }

    bool operator< (const CString& another) const
        { return strcmp(this->m_pchData, another) < 0; }

	bool operator> (const CString& another) const
		{ return strcmp(this->m_pchData, another) > 0; }

	bool operator<= (const CString& another) const
		{ return !(*this > another); }

	bool operator>= (const CString& another) const
		{ return !(*this < another); }

	bool operator== (const CString& another) const
		{ return strcmp(this->m_pchData, another) == 0; }

	bool operator!= (const CString& another) const
		{ return !(*this == another); }

    bool operator== (const std::string& another) const
    {
        return strcmp(this->m_pchData, another.c_str()) == 0;
    }

    bool operator!= (const std::string& another) const
    {
        return !(*this == another);
    }

	bool operator< (const char* another) const
        { return strcmp(this->m_pchData, another) < 0; }

	bool operator> (const char* another) const
		{ return strcmp(this->m_pchData, another) > 0; }

	bool operator<= (const char* another) const
		{ return !(*this > another); }

	bool operator>= (const char* another) const
		{ return !(*this < another); }

	bool operator== (const char* another) const
		{ return strcmp(this->m_pchData, another) == 0; }

	bool operator!= (const char* another) const
		{ return !(*this == another); }

	char& operator[] (const int idx)
		{ return this->m_pchData[idx]; }

	const char operator[] (const int idx) const
		{ return this->m_pchData[idx]; }

    LPTSTR m_pchData;   // pointer to ref counted string data


public:
    // Extra implements not contained in FA2

    CString Mid(int nFirst) const
    {
        return Mid(nFirst, GetData()->nDataLength - nFirst);
    }

    CString Mid(int nFirst, int nCount) const
    {
        // out-of-bounds requests return sensible things
        if (nFirst < 0)
            nFirst = 0;
        if (nCount < 0)
            nCount = 0;

        if (nFirst + nCount > GetData()->nDataLength)
            nCount = GetData()->nDataLength - nFirst;
        if (nFirst > GetData()->nDataLength)
            nCount = 0;

        CString dest;
        AllocCopy(dest, nCount, nFirst, 0);
        return dest;
    }

	// Process strings contains %1, %2
	void ReplaceNumString(int value, const char* to)
	{
		char buffer[64], num[64];
		_itoa_s(value, num, 10);
		num[63] = '\0';
		buffer[0] = '%';
		buffer[1] = '\0';
		strcat_s(buffer, num);
		buffer[63] = '\0';
		if (Find(buffer) >= 0)
			Replace(buffer, to);
	}

	void ReplaceNumString(int value, int to)
	{
		char num[64];
		sprintf_s(num, "%d", to);
		ReplaceNumString(value, num);
	}

private:
	static CString* __cdecl ReplaceNumString(CString* ret, int value, const char* source, const char* to)
	{
		JMP_STD(0x43D960);
	}

    template<typename T>
    void convertArg(std::vector<std::variant<int, double, const char*, const wchar_t*>>& vec, T&& arg) {
        using U = std::decay_t<T>;
        if constexpr (std::is_same_v<U, FString>) {
            vec.push_back(arg.c_str());
        }
        else if constexpr (std::is_same_v<U, CString>) {
            vec.push_back(arg.m_pchData);
        }
        else if constexpr (std::is_same_v<U, ppmfc::CString>) {
            vec.push_back(arg.m_pchData);
        }
        else if constexpr (std::is_same_v<U, std::string>) {
            vec.push_back(arg.c_str());
        }
        else if constexpr (std::is_same_v<U, std::wstring>) {
            vec.push_back(arg.c_str());
        }
        else if constexpr (std::is_same_v<U, const char*>) {
            vec.push_back(arg);
        }
        else if constexpr (std::is_same_v<U, char*>) {
            vec.push_back(static_cast<const char*>(arg));
        }
        else if constexpr (std::is_same_v<U, const wchar_t*>) {
            vec.push_back(arg);
        }
        else if constexpr (std::is_same_v<U, int>) {
            vec.push_back(arg);
        }
        else if constexpr (std::is_same_v<U, size_t>) {
            vec.push_back(static_cast<int>(arg));
        }
        else if constexpr (std::is_same_v<U, short>) {
            vec.push_back(static_cast<int>(arg));
        }
        else if constexpr (std::is_same_v<U, word>) {
            vec.push_back(static_cast<int>(arg));
        }
        else if constexpr (std::is_same_v<U, dword>) {
            vec.push_back(static_cast<int>(arg));
        }
        else if constexpr (std::is_same_v<U, char>) {
            vec.push_back(static_cast<int>(arg));
        }
        else if constexpr (std::is_same_v<U, byte>) {
            vec.push_back(static_cast<int>(arg));
        }
        else if constexpr (std::is_same_v<U, bool>) {
            vec.push_back(static_cast<int>(arg));
        }
        else if constexpr (std::is_same_v<U, double>) {
            vec.push_back(arg);
        }
        else if constexpr (std::is_same_v<U, float>) {
            vec.push_back(static_cast<double>(arg));
        }
        else if constexpr (std::is_same_v<U, void*>) {
            vec.push_back(reinterpret_cast<intptr_t>(arg));
        }
        else if constexpr (std::is_same_v<U, int*>) {
            vec.push_back(reinterpret_cast<intptr_t>(arg));
        }
        else {
            static_assert(false, "Unsupported argument type for Format");
        }
    }

    void FormatVImpl(const std::string& format, const std::vector<std::variant<int, double, const char*, const wchar_t*>>& args) {
        constexpr int FORCE_ANSI = 0x10000;
        constexpr int FORCE_UNICODE = 0x20000;

        size_t argIndex = 0;
        std::string result;
        result.reserve(format.length() + 32);

        for (const char* p = format.c_str(); *p; ++p) {
            if (*p != '%') {
                result += *p;
                continue;
            }

            ++p;
            if (*p == '%') {
                result += '%';
                continue;
            }

            std::string formatSpec = "%";
            int nWidth = 0;
            int nPrecision = 0;
            int nModifier = 0;

            while (*p == '#' || *p == '*' || *p == '-' || *p == '+' || *p == '0' || *p == ' ') {
                formatSpec += *p;
                if (*p == '*') {
                    if (argIndex >= args.size()) throw std::runtime_error("Too few arguments for width");
                    nWidth = std::get<int>(args[argIndex++]);
                }
                ++p;
            }

            if (isdigit(*p)) {
                formatSpec += std::string(p, strspn(p, "0123456789"));
                nWidth = atoi(p);
                while (isdigit(*p)) ++p;
            }

            if (*p == '.') {
                formatSpec += '.';
                ++p;
                if (*p == '*') {
                    formatSpec += '*';
                    if (argIndex >= args.size()) throw std::runtime_error("Too few arguments for precision");
                    nPrecision = std::get<int>(args[argIndex++]);
                    ++p;
                }
                else if (isdigit(*p)) {
                    formatSpec += std::string(p, strspn(p, "0123456789"));
                    nPrecision = atoi(p);
                    while (isdigit(*p)) ++p;
                }
            }

            switch (*p) {
            case 'h':
                nModifier = FORCE_ANSI;
                formatSpec += 'h';
                ++p;
                break;
            case 'l':
                nModifier = FORCE_UNICODE;
                formatSpec += 'l';
                ++p;
                break;
            case 'F':
            case 'N':
            case 'L':
                formatSpec += *p;
                ++p;
                break;
            }

            if (argIndex >= args.size()) throw std::runtime_error("Too few arguments for format specifier");
            formatSpec += *p;

            switch (*p | nModifier) {
            case 'c':
            case 'C':
            case 'c' | FORCE_ANSI:
            case 'C' | FORCE_ANSI:
            {
                int value = std::get<int>(args[argIndex++]);
                char buf[16];
                snprintf(buf, sizeof(buf), formatSpec.c_str(), value);
                result += buf;
                break;
            }
            case 'c' | FORCE_UNICODE:
            case 'C' | FORCE_UNICODE:
            {
                wchar_t value = static_cast<wchar_t>(std::get<int>(args[argIndex++]));
                wint_t wvalue = static_cast<wint_t>(value);
                char buf[16];
                snprintf(buf, sizeof(buf), "%lc", wvalue);
                result += buf;
                break;
            }
            case 's':
            case 's' | FORCE_ANSI:
            case 'S':
            case 'S' | FORCE_ANSI:
            {
                const char* str = std::get<const char*>(args[argIndex++]);
                char buf[1024];
                snprintf(buf, sizeof(buf), formatSpec.c_str(), str ? str : "(null)");
                result += buf;
                break;
            }
            case 's' | FORCE_UNICODE:
            case 'S' | FORCE_UNICODE:
            {
                const wchar_t* str = std::get<const wchar_t*>(args[argIndex++]);
                if (str) {
                    int ansiSize = WideCharToMultiByte(CP_ACP, 0, str, -1, nullptr, 0, nullptr, nullptr);
                    if (ansiSize == 0) {
                        result += "(null)";
                        break;
                    }
                    std::vector<char> ansiStr(ansiSize);
                    WideCharToMultiByte(CP_ACP, 0, str, -1, ansiStr.data(), ansiSize, nullptr, nullptr);
                    char buf[1024];
                    snprintf(buf, sizeof(buf), "%s", ansiStr.data());
                    result += buf;
                }
                else {
                    char buf[1024];
                    snprintf(buf, sizeof(buf), "%s", "(null)");
                    result += buf;
                }
                break;
            }
            case 'd':
            case 'i':
            case 'u':
            case 'x':
            case 'X':
            case 'o':
            case 'p':
            case 'n':
            {
                int value = std::get<int>(args[argIndex++]);
                char buf[64];
                snprintf(buf, sizeof(buf), formatSpec.c_str(), value);
                result += buf;
                break;
            }
            case 'e':
            case 'f':
            case 'g':
            case 'G':
            {
                double value = std::get<double>(args[argIndex++]);
                char buf[128];
                snprintf(buf, sizeof(buf), formatSpec.c_str(), value);
                result += buf;
                break;
            }
            default:
                throw std::invalid_argument("Unsupported format specifier: " + formatSpec);
            }
            }

        if (argIndex < args.size()) {
            throw std::runtime_error("Too many arguments provided");
        }

        *this = result.c_str();
    }
public:

    template<typename... Args>
    void Format(const std::string& lpszFormat, Args&&... args) {
        if (lpszFormat.empty()) {
            throw std::invalid_argument("Invalid format string");
        }

        std::vector<std::variant<int, double, const char*, const wchar_t*>> convertedArgs;
        (convertArg(convertedArgs, std::forward<Args>(args)), ...);

        FormatVImpl(lpszFormat, convertedArgs);
    }

    template<typename... Args>
    void Format(const char* lpszFormat, Args&&... args) {
        if (!lpszFormat) {
            throw std::invalid_argument("Invalid format string");
        }

        std::vector<std::variant<int, double, const char*, const wchar_t*>> convertedArgs;
        (convertArg(convertedArgs, std::forward<Args>(args)), ...);

        FormatVImpl(std::string(lpszFormat), convertedArgs);
    }

    template<typename... Args>
    void Format(UINT nFormatID, Args&&... args) {
        CString strFormat;
        VERIFY(strFormat.LoadString(nFormatID) != 0);

        std::vector<std::variant<int, double, const char*, const wchar_t*>> convertedArgs;
        (convertArg(convertedArgs, std::forward<Args>(args)), ...);

        FormatVImpl(strFormat, convertedArgs);
    }
};

//BOOL _PPMFC_API AfxExtractSubString(CString& rString, LPCTSTR lpszFullString,
//    int iSubString, TCHAR chSep = '\n')
//    _PPMFC_STDCALL(0x5565B2);
//
//void _PPMFC_API AfxFormatStrings(CString& rString, UINT nIDS,
//    LPCTSTR const* rglpsz, int nString)
//    _PPMFC_STDCALL(0x55FBB7);
//
//void _PPMFC_API AfxFormatStrings(CString& rString, LPCTSTR lpszFormat,
//    LPCTSTR const* rglpsz, int nString)
//    _PPMFC_STDCALL(0x55FBF1);
//
//void _PPMFC_API AfxFormatString1(CString& rString, UINT nIDS, LPCTSTR lpsz1)
//    _PPMFC_STDCALL(0x55FCF0);
//
//void _PPMFC_API AfxFormatString2(CString& rString, UINT nIDS,
//    LPCTSTR lpsz1, LPCTSTR lpsz2)
//    _PPMFC_STDCALL(0x55FD07);

_PPMFC_END

#include <format>

template <class CharT>
struct std::formatter<ppmfc::CString, CharT> : public std::formatter<const CharT*, CharT>
{
	template<class FormatContext>
	auto format(const ppmfc::CString& t, FormatContext& fc) {
		return std::formatter<const CharT*, CharT>::format(t.m_pchData, fc);
	}
};