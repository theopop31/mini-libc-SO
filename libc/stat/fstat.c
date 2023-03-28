// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <errno.h>
#include <internal/syscall.h>

int fstat(int fd, struct stat *st)
{
	/* TODO: Implement fstat(). */
	if (syscall(__NR_fstat, fd, st) == 0) {
		return 0;
	}
	errno = EBADF;
	return -1;
}
