#include "modules.h"

mod_t module_open(const char *filename)
{
    mod_t module = { strdup(filename), fopen(filename, "r") };

    if (module.file == NULL)
    {
        perror("module_open()");
        exit(-1);
    }

    return module;
}

// Returns 0 if successful, EOF if not
int module_close(mod_t module)
{
    free(module.name);
    return fclose(module.file);
}
