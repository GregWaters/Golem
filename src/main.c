#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "../inc/file.h"
#include "../inc/lexer.h"

static void usage_exit(int exit_code)
{
    fputs("usage: golem <file>\n", stderr);
    exit(exit_code);
}

int main(int argc, char **argv)
{
    if (argc < 2)
        usage_exit(1);

    file.name = argv[1];
    file.ptr = fopen(file.name, "r");
        
    if (!file.ptr)
        fprintf(stderr, "fopen(): Could not open file '%s' - %s", file.name, strerror(errno));
    
    // Lexer goes here!
}
