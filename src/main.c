#include "../inc/modules.h"
#include <assert.h>

int main(int argc, char **argv)
{
    if (argc < 2)
        return -1;

    

    mod_t module_test = module_open(argv[1]);

    printf("Successfully opened module '%s', exiting", module_test.name);
}
