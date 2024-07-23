#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct module
{
    char *name;
    FILE *file;
} mod_t;

mod_t module_open(const char *filename);
