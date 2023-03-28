// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>
#include <sys/stat.h>

int open(const char *filename, int flags, ...)
{
	/* TODO: Implement open system call. */
	
	struct stat fileInfo;
	//memset(&fileInfo, 0, sizeof(struct stat));
	
	int rez = stat(filename, &fileInfo);
	if (rez == -1) {
		//write(1, "here\n", 5);
		if (!(flags & O_CREAT)) {
			errno = ENOENT;
			return -1;
		}
	} else {
		
		//  && (flags & O_RDWR || flags & O_WRONLY)
		// unsigned int aux = fileInfo.st_mode;
		// unsigned int reverse = 0;
		// unsigned int c;
		// int k = 0;
		// char buffer[80];
		// while (aux > 0) {
		// 	c = aux % 10;
		// 	buffer[k] = c + '0';;
		// 	aux /= 10;
		// 	++k;
		// }
		// buffer[k] = '\n';
		// write(1, buffer, k);
		// int a = __S_IFMT;
		// int b = __S_IFDIR;
		// aux = a;
		// reverse = 0;
		// k = 0;
		// while (aux > 0) {
		// 	c = aux % 10;
		// 	reverse = reverse * 10 + c;
		// 	aux /= 10;
		// }
		// while (reverse > 0) {
		// 	c = reverse % 10;
		// 	buffer[k] = c + '0';
		// 	++k;
		// 	reverse /= 10;
		// }
		// buffer[k] = '\n';
		//write(1, buffer, k);
		//int a = fileInfo.st_mode;
		if ((fileInfo.st_mode & __S_IFMT)  == __S_IFDIR && (flags & O_RDWR || flags & O_WRONLY)) {
			errno = EISDIR;
			return -1;
		}
		
		if ((flags & O_WRONLY) && !(fileInfo.st_mode & S_IWUSR)) {
			errno = EACCES;
			return -1;
		}
		if ((flags & O_RDONLY) && !(fileInfo.st_mode & S_IRUSR)) {
			errno = EACCES;
			return -1;
		}
		if ((flags & O_RDWR) && !((fileInfo.st_mode & S_IRUSR) && (fileInfo.st_mode & S_IWUSR))) {
			errno = EACCES;
			return -1;
		}

		if (flags & O_DIRECTORY && !((fileInfo.st_mode & __S_IFMT)  == __S_IFDIR)) {
			errno = ENOTDIR;
			return -1;
		}

		if ((flags & O_CREAT) && (flags & O_EXCL)) {
			errno = EEXIST;
			return -1;
		}
		
	}

	int fd = syscall(__NR_open, filename, flags);
	if (fd < 0) {
		errno = ENOENT;
		return -1;
	}
	return fd;
}
