// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int truncate(const char *path, off_t length)
{
	/* TODO: Implement truncate(). */
	off_t result = syscall(76, path, length);
	if (result < 0) {
		errno = -result;
		return -1;
	}
	return result;
}
