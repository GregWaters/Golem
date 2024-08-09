#include "../inc/file.h"

bool file_init(struct File *file, const char *filename)
{
    file->name = filename;
    struct stat statbuf;
    stat(filename, &statbuf);
    int fd = open(filename, O_RDONLY);
        
    if (fd == -1)
        return true;

#if defined (__unix__) || (defined (__APPLE__) && defined (__MACH__))
        // Make file->contents point to a virtual address space with our file's data
        // Prefault pages with the MAP_POPULATE flag, we must read the entire file anyway
        file->contents = (char *) mmap(NULL, statbuf.st_size, PROT_READ, MAP_POPULATE, fd, 0);
        
        // Hint to the kernel that we're going to be reading sequentially (commented out for now)
        // madvise(file->contents, statbuf.st_size, MADV_SEQUENTIAL);

#else
    // A more standard way of performing mmap
    file->contents = (char *) malloc(statbuf.st_size);
    read(fd, file->contents, statbuf.st_size);
#endif

    file->end = file->contents + statbuf.st_size;
    return false;
}