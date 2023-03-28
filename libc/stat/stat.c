// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <internal/syscall.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	/* TODO: Implement stat(). */
	if (syscall(__NR_stat, path, buf) == 0) {
		return 0;
	}
	errno = ENOENT;
	return -1;
}
