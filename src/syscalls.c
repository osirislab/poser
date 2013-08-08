#define _GNU_SOURCE
#include <stdlib.h>
#include <dlfcn.h>
#include <stdio.h>

int mkstemp(char * template) {
        static int (* real_mkstemp)(char *) = NULL;
        int ret;
        if (!real_mkstemp) real_mkstemp = dlsym(RTLD_NEXT, "mkstemp");

        ret = real_mkstemp(template);
        printf("%d = mkstemp(%s)\n", ret, template);
        return(ret);
}

ssize_t write(int fd, const void * buf, size_t count) {
        static ssize_t (* real_write)(int, const void *, size_t) = NULL;
        ssize_t ret;

        if (!real_write) real_write = dlsym(RTLD_NEXT, "write");
        ret = real_write(fd, buf, count);
        printf("%d = write(%d, %p:%s, %d)", ret, fd, buf, (char *)buf, count);
        return(ret);
}


ssize_t read(int fd, const void * buf, size_t count) {
	static ssize_t (* real_read)(int, const void *, size_t) = NULL;
	ssize_t ret;

	if (!real_read) real_read = dlsym(RTLD_NEXT, "read");
	ret = real_read(fd, buf, count);
	printf("%d = read(%d, %p:%s, %d)", ret, fd, buf, (char *)buf, count);
	return(ret);
}
