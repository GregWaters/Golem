# Overview
Characters and parsing of source files are more of a touchy subject than you'd assume.
There are many people who like all UTF encoding variants [built into the language](https://en.wikipedia.org/wiki/D_(programming_language)), and others who [employ UTF-8 religiously](https://utf8everywhere.org/).

I feel that it's difficult to go wrong with a purist UTF-8 format for all strings.
This is not to exclude UTF-16 (which I will be referring to as Unicode from this point forward), but rather to have one unified encoding rather than many loosely tied encodings.
However, wide-character strings are still possible by casting a standard string to a 16-bit type pointer, as in the statement `[wchar] hello { [wchar]("Ηello, world!") }`,
which casts each 8-bit character to a 16-bit wide-character type (wchar) and allows for seamless interoperability between 8-bit characters and 16-bit characters.

Interestingly, the 'H' in that string is actually a Unicode character that is pixel-to-pixel identical to a standard 'H', but it will be displayed incorrectly if used in any print functions that take in UTF-8 strings.
This is why all character types are marked with the `@explicit` attribute that warns the programmer when an implicit cast is performed to or from the type. Type-safety is very useful when dealing with UTF-8 and Unicode APIs.
