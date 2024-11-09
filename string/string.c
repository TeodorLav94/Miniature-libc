// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	if (destination == NULL) {
        return NULL;
    }
    char *ptr = destination;
    while (*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
    return ptr;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	char *start = destination;
    while (len != 0 && *source) {
        *destination = *source;
        destination++;
        source++;
        len--;
    }
    while (len > 0) {
        *destination = '\0';
        destination++;
        len--;
    }
    return start;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
    char* ptr = destination + strlen(destination);
    while (*source != '\0') {
        *ptr++ = *source++;
    }
    *ptr = '\0';
    return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
    char* ptr = destination + strlen(destination);
    while (*source != '\0' && len--) {
        *ptr++ = *source++;
    }
    *ptr = '\0';
    return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	while (*str1)
    {
        if (*str1 != *str2) {
            break;
        }
        str1++;
        str2++;
    }
    return *(const unsigned char*)str1 - *(const unsigned char*)str2;
	return -1;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
    const char *first = str1;
    const char *second = str2;
	while (len > 0) {
		if (*first == '\0' || *second == '\0') {
			return -1;
		}
		if (*first != *second) {
			return (*first - *second);
		}
	first++;
	second++;
	len--;
	}
	return 0;
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
	while (*str != (char) c) {
        if (!*str++) {
            return NULL;
        }
    }
    return (char *)str;
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
    const char *out = NULL;
	while (*str) {
        if (*str == (char) c) {
            out = str;
        }
		str++;
    }
    if (out != NULL) {
        return out;
    } else if (c == '\0') {
        return str;
    } else {
        return NULL;
    }
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	int len = strlen(needle);
    while (*haystack++) {
        if (strncmp(haystack - 1, needle, len) == 0) {
            return (char *) --haystack;
        }
    }
    return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	int len = strlen(needle);
	char * last = NULL;
    while (*haystack++) {
        if (strncmp(haystack - 1, needle, len) == 0) {
            last = (char *) (haystack - 1);
        }
    }
	return last;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char *dest = (char *)destination;
    const char *src = (const char *)source;
    for (size_t i = 0; i < num; i++) {
        dest[i] = src[i];
    }
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *dest = (char *)destination;
    const char *src = (const char *)source;
    if (dest == src) {
        return destination;
    }
    if (dest < src) {
        for (size_t i = 0; i < num; i++) {
            dest[i] = src[i];
        }
    } else {
        for (size_t i = num; i > 0; i--) {
            dest[i - 1] = src[i - 1];
        }
    }
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	const unsigned char *p1 = (const unsigned char *)ptr1;
    const unsigned char *p2 = (const unsigned char *)ptr2;
    for (size_t i = 0; i < num; i++) {
        if (p1[i] < p2[i]) {
            return -1;
        } else if (p1[i] > p2[i]) {
            return 1;
        }
	}
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	unsigned char *ptr = (unsigned char *)source;
    unsigned char byteValue = (unsigned char)value;
    for (size_t i = 0; i < num; i++) {
        ptr[i] = byteValue;
    }
	return source;
}
