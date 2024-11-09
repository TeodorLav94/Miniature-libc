// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	void *memory = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if(memory == MAP_FAILED) {
		return NULL;
	}
	int err = mem_list_add(memory, size);
	return memory;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	void *memory = mmap(NULL, size * nmemb, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if(memory == MAP_FAILED) {
		return NULL;
	}
	int err = mem_list_add(memory, size);
	return memory;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	struct mem_list *len = mem_list_find(ptr);
	int err = munmap(ptr, len->len);
	int err1 = mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	struct mem_list *len = mem_list_find(ptr);
	void *memory = mremap(ptr, len->len, size, MREMAP_MAYMOVE);
	if(memory == MAP_FAILED) {
		return NULL;
	}
	len->start = memory;
	return memory;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	struct mem_list *len = mem_list_find(ptr);
	void *memory = mremap(ptr, len->len, size * nmemb, MREMAP_MAYMOVE);
	if(memory == MAP_FAILED) {
		return NULL;
	}
	len->start = memory;
	return memory;
}
