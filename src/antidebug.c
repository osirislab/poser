#define _GNU_SOURCE
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include <string.h>

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
	} else { 
		if (!real_getenv) real_getenv = dlsym(RTLD_NEXT, "getenv");
		ret = real_getenv(name);
	} 

	printf("%s = getenv(%s)", ret, name);
	return(ret);
}
