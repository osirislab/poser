#define _GNU_SOURCE
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include <string.h>
//#include <sys/ptrace.h>

bool value_of_strP(const char * var, const char * value) {
	size_t max = strlen(value); 
	bool ret = strlen(var) == max;
	if (ret) ret = strncmp(var, value, max)==0;
	//printf("value_of_strP = %d\n", ret);
	return(ret);
}

char * getenv(const char * name) {
	static char * (*real_getenv)(const char *) = NULL;
	char * ret = NULL;
	
	if (value_of_strP(name, "LD_PRELOAD")==true)  {
		printf("Antidebugging detected: getenv(\"LD_PRELOAD\")\n");
		printf("setting getenv(%s) = NULL\n", name);
	} else { 
		if (!real_getenv) real_getenv = dlsym(RTLD_NEXT, "getenv");
		ret = real_getenv(name);
	} 

	printf("%s = getenv(%s)\n", ret, name);
	return(ret);
}

#define PTRACE_TRACEME 0

long ptrace(int request, pid_t pid, void *addr, void *data) {
	long ret;

	static long (*real_ptrace)(int, pid_t, void *, void *) = NULL;
	if (request == PTRACE_TRACEME) {
		printf("Antidebugging detected: PTRACE_TRACEME call\n");
		ret = 0;
	} else {
		if (!real_ptrace) real_ptrace = dlsym(RTLD_NEXT, "ptrace");
		ret = real_ptrace(request, pid, addr, data);
	}
	return(ret);
}
