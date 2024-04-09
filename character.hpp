#ifndef __CHARACTER_HPP
#define __CHARACTER_HPP

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

#endif