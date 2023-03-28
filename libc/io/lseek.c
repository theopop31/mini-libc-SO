// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

off_t lseek(int fd, off_t offset, int whence)
{
	/* TODO: Implement lseek(). */
	if (fd < 0) {
		errno = EBADF;
		return -1;
	}
	if (whence != SEEK_CUR && whence != SEEK_END && whence != SEEK_SET) {
		errno = EINVAL;
		return -1;
	}
	if (offset < 0) {
		errno = EINVAL;
		return -1;
	}
	off_t numBytes = syscall(__NR_lseek, fd, offset, whence);
	if (numBytes < 0) {
		errno = -numBytes;
		return -1;
	}
	return numBytes;
}
