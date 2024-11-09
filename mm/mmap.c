// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	/* TODO: Implement mmap(). */
	long map = syscall(9, addr, length, prot, flags, fd, offset);
	if (map < 0) {
		errno = -map;
		return (void*)-1;
	}
    return (void *)map;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	/* TODO: Implement mremap(). */
	long remap = syscall(25, old_address, old_size, new_size, flags);
	if (remap < 0) {
		errno = -remap;
		return (void*)-1;
	}
	return (void *)remap;
}

int munmap(void *addr, size_t length)
{
	/* TODO: Implement munmap(). */
	int mun = syscall(11, addr, length);
	if (mun < 0) {
		errno = -mun;
		return -1;
	}
	return 0;
}
