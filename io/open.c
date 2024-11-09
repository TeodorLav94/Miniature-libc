// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	/* TODO: Implement open system call. */
	int result = -1;
	mode_t mode = 0;
	va_list ptr;
	va_start(ptr, flags);
	if (flags & O_CREAT) {
        mode = va_arg(ptr, mode_t);
		result = syscall(2, filename, flags, mode);
    } else {
		result = syscall(2, filename, flags);
	}
	va_end(ptr);
	if (result < 0) {
		errno = -result;
		return -1;
	}
	return result;
}
