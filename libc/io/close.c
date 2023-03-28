// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	/* TODO: Implement close(). */
	if (fd < 0) {
		errno = EINTR;
		return -1;
	}
	syscall(__NR_close, fd);
	return 0;
}
