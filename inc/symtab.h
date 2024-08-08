#pragma once

#include <stdio.h>
#include <string.h>

struct Dynamic_string_table
{
    const char **keys;
    const char **values;
}

static
char *dynamic_strdup(const char *nul_term_str)
{
    size_t len = strlen(nul_term_str);

    char *dstring = malloc(len + sizeof(unsigned));

}

struct Symtab
{
    
}

void symtab_add(const char *symbol);
void symtab_del(const char *symbol);
const char *symtab_get();