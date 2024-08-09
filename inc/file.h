#pragma once

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>

#if defined (__unix__) || (defined (__APPLE__) && defined (__MACH__))
    #include <sys/mman.h>
    #include <unistd.h>
#elif defined(_WIN32)
    #include <io.h>
#endif

struct File
{
    // The name of our file
    const char *name;

    // Beginning of address space
    char *start;
    
    // Movable pointer to current position
    char *contents;

    // End of address space
    char *end;

    // Line and column, used for error reporting
    unsigned line, column;
};

// Returns true if an error was encountered
bool file_init(struct File *file, const char *filename);

// Returns true if an error was encountered
bool file_exit(struct File *file);
