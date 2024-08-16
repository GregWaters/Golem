#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fputs("usage: golem <file>\n", stderr);
        exit(1);
    }
}
