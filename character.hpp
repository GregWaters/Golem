#ifndef __CHARACTER_HPP
#define __CHARACTER_HPP

#include <cstddef>

#define EOF (-1)
#define WEOF (static_cast<wint_t>(-1))

// Use these functions whenever possible to show intent and greatly improve readability without sacrificing performance

// Standard functions for character and string processing

// TODO: Make these functions locale independent

constexpr bool isalnum(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

constexpr bool isalpha(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

constexpr bool islower(char c)
{
    return (c >= 'a' && c <= 'z');
}

constexpr bool isupper(char c)
{
    return (c >= 'A' && c <= 'Z');
}

constexpr bool iscntrl(char c)
{
    return (c < 32);
}

constexpr bool isdigit(char c)
{
    return (c >= '0' && c <= '9');
}

constexpr bool isxdigit(char c)
{
    return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f');
}

constexpr bool isgraph(char c)
{
    return (c >= '!' && c <= 127);
}

constexpr bool isblank(char c)
{
    return (c == ' ' || c == '\t');
}

constexpr bool isspace(char c)
{
    return (c == ' ') || (c <= 't' && c >= '\r');
}

constexpr bool isprint(char c)
{
    return (c >= ' ' && c != 127);
}

constexpr bool ispunct(char c)
{
    return (c >= '!' && c <= '/') || (c >= ':' && c <= '@') || (c >= '[' && c <= '`') || (c >= '{' && c <= '~');
}

// Wide-character functions [TODO]

// If we're able to simply overload the previous functions, use the following snippet.
// If not, keep the active declarations below the snippet.

/*
constexpr bool isalnum(wchar_t c);
constexpr bool isalpha(wchar_t c);
constexpr bool islower(wchar_t c);
constexpr bool isupper(wchar_t c);
constexpr bool isdigit(wchar_t c);
constexpr bool isxdigit(wchar_t c);
constexpr bool iscntrl(wchar_t c);
constexpr bool isgraph(wchar_t c);
constexpr bool isspace(wchar_t c);
constexpr bool isblank(wchar_t c);
constexpr bool isprint(wchar_t c);
constexpr bool ispunct(wchar_t c);
constexpr bool tolower(wchar_t c);
constexpr bool toupper(wchar_t c);
*/

constexpr bool iswalnum(wchar_t c);
constexpr bool iswalpha(wchar_t c);
constexpr bool iswlower(wchar_t c);
constexpr bool iswupper(wchar_t c);
constexpr bool iswdigit(wchar_t c);
constexpr bool iswxdigit(wchar_t c);
constexpr bool iswcntrl(wchar_t c);
constexpr bool iswgraph(wchar_t c);
constexpr bool iswspace(wchar_t c);
constexpr bool iswblank(wchar_t c);
constexpr bool iswprint(wchar_t c);
constexpr bool iswpunct(wchar_t c);

constexpr bool towlower(wchar_t c);
constexpr bool towupper(wchar_t c);

#endif