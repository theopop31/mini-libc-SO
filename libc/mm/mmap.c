// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

// void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
// {
// 	/* TODO: Implement mmap(). */
// 	// void* rez = syscall(__NR_mmap, length, prot, flags, fd, offset);
// 	// if (rez == NULL) {
// 	// 	return MAP_FAILED;
// 	// }
// 	return (void*)syscall(__NR_mmap, length, prot, flags, fd, offset);
// }

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset) {
    void *ret = (void *)-1;
    int mmap_flags = 0;
    int mmap_prot = 0;

    // if (prot & PROT_EXEC) mmap_prot |= PROT_EXEC;
    // if (prot & PROT_WRITE) mmap_prot |= PROT_WRITE;
    // if (prot & PROT_READ) mmap_prot |= PROT_READ;

    // if (flags & MAP_PRIVATE) mmap_flags |= MAP_PRIVATE;
    // if (flags & MAP_SHARED) mmap_flags |= MAP_SHARED;
    // if (flags & MAP_ANONYMOUS) mmap_flags |= MAP_ANONYMOUS;
    // if (flags & MAP_FIXED) mmap_flags |= MAP_FIXED;
	
	if (!((flags & MAP_PRIVATE) || (flags & MAP_SHARED))) {
		errno = EINVAL;
		return MAP_FAILED;
	}
    ret = (void *)syscall(__NR_mmap, addr, length, prot, flags, fd, offset);

    if (ret == (void *)-1) {
        errno = ENOMEM;
        return MAP_FAILED;
    }

    return ret;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	/* TODO: Implement mremap(). */
	return MAP_FAILED;
}

int munmap(void *addr, size_t length)
{
	/* TODO: Implement munmap(). */
	return -1;
}
