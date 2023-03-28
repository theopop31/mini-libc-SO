// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	destination = memcpy(destination, source, strlen(source) + 1);
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	int i;
	for (i = 0; i < len && source[i] != '\0'; ++i) {
		destination[i] = source[i];
	}
	for( ; i < len; ++i) {
		destination[i] = 0;
	}
	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	int destLength = strlen(destination);
	char* start = destination;

	while (*source != 0) {
		*(destination + destLength) = *source;
		++source;
		++destination;
	}
	*(destination + destLength) = 0;
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	int destLength = strlen(destination);
	char* start = destination;
	while (*source != 0 && len > 0) {
		*(destination + destLength) = *source;
		++source;
		++destination;
		--len;
	}
	*(destination + destLength) = 0;
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	while (*str1 != 0 && *str2 != 0) {
		if (*str1 < *str2) {
			return -1;
		} else if (*str1 > *str2) {
			return 1;
		} else {
			++str1;
			++str2;
		}
	}
	if (*str1 != 0) {
		return 1;
	} else if (*str2 != 0) {
		return -1;
	} else {
		return 0;
	}
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	while (*str1 != 0 && *str2 != 0 && len > 0) {
		if (*str1 < *str2) {
			return -1;
		} else if (*str1 > *str2) {
			return 1;
		} else {
			++str1;
			++str2;
			--len;
		}
	}
	if (len == 0) {
		return 0;
	} else if (*str1 != 0) {
		return 1;
	} else if (*str2 != 0) {
		return -1;
	} else {
		return 0;
	}
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	while (*str != 0) {
		if (*str == c) {
			return str;
		}
		++str;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	char* poz = NULL;
	while (*str != 0) {
		if (*str == c) {
			poz = str;
		}
		++str;
	}
	return poz;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	char* start = NULL;
	char* oldNeedle = needle;
	while (*haystack != 0) {
		if (*haystack == *needle) {
			start = haystack;
			while (*haystack == *needle && *haystack != 0 && *needle != 0) {
				++haystack;
				++needle;
			}
			if (*needle == 0) {
				return start;
			}
			needle = oldNeedle;
			haystack = start;
		}
		++haystack;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	char* poz = NULL;
	while (1) {
		char* p = strstr(haystack, needle);
		if (p == NULL) {
			return poz;
		}
		poz = p;
		haystack = p + strlen(needle);
	}
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	const char *sourcePoz = (const char *)source;
	char *destinationPoz = (char *)destination;

	if (destinationPoz != NULL && sourcePoz != NULL) {
		while (num > 0) {
			*(destinationPoz++) = *(sourcePoz++);
			--num;
		}
	}

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char* dest = (char*) destination;
	char* src = (char*) source;
	if (src == dest || num == 0) {
		return destination;
	}
	if (dest > src) {
		// overlapping
		for (int i = (int)num - 1; i >= 0; --i) {
			*(dest + i) = *(src + i);
		}
		return (void*)dest;
	}
	if (src > dest) {
		// overlapping the other way
		for (int i = 0; i < num; ++i) {
			*(dest + i) = *(src + i);
		}
		return destination;
	}
	memcpy(destination, source, num);
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	if (num == 0) {
		return 0;
	}
	unsigned char* p1 = (unsigned char*)ptr1;
	unsigned char* p2 = (unsigned char*)ptr2;

	while (p1 != NULL && p2 != NULL && num > 0) {
		if (*p1 > *p2) {
			return 1;
		} else if (*p1 < *p2) {
			return -1;
		} else {
			++p1;
			++p2;
			--num;
		}
	}
	
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	char* s = (char*) source;
	while (num > 0) {
		*s = value;
		++s;
		--num;
	}

	return source;
}
