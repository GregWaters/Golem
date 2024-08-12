#include "../inc/file.h"

bool file_init(struct File *file, const char *filename)
{
    file->name = filename;
    struct stat statbuf;
    stat(filename, &statbuf);
    int fd = open(filename, O_RDONLY);
        
    if (fd == -1)
        return true;

#if defined (__linux__) || (defined (__APPLE__) && defined (__MACH__))
        // Make file->contents point to a virtual address space with our file's data
        // Prefault pages with the MAP_POPULATE flag, we must read the entire file anyway
        file->start = (char *) mmap(NULL, statbuf.st_size, PROT_READ, MAP_POPULATE | MAP_PRIVATE, fd, 0);
        if (file->start == (char *) -1)
	    return true;

        // Hint to the kernel that we're going to be reading sequentially
        madvise(file->contents, statbuf.st_size, MADV_SEQUENTIAL);

#else
    // A more standard way of performing mmap
    file->start = (char *) malloc(statbuf.st_size);
    read(fd, file->start, statbuf.st_size);
#endif

    close(fd);

    // Initialize the contents to the start
    file->contents = file->start;
    file->end = file->contents + statbuf.st_size;
    return false;
}

bool file_exit(struct File *file)
{
#if defined (__linux__) || (defined (__APPLE__) && defined (__MACH__))
    return munmap(file->start, file->end - file->start);
#endif

    free(file->start);
    return false;
}
