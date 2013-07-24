#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>

typedef void * (*malloc_ptr)(size_t);

void * malloc(size_t size) {
	static void * (*real_malloc)(size_t) = NULL;
	void * ret;
		
	if (!real_malloc) real_malloc = dlsym(RTLD_NEXT, "malloc");
	//printf ("%p=", malloc);
	//printf ("%p\n", real_malloc);
	ret = real_malloc(size);
	//printf("size = %d address=%p\n", (unsigned int) size, ret);	
	printf("%p = malloc(size = %d)\n", ret, (unsigned int) size);	
	return(ret);
}
