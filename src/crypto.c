#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>



char * crypt(const char * key, const char * salt) {
	static char * (*real_crypt)(const char *, const char *) = NULL;

	char * ret = NULL;
	if (!real_crypt) real_crypt = dlsym(RTLD_NEXT, "crypt");

	ret = real_crypt(key, salt);
	printf("%s = crypt(%s, %s)\n", ret, key, salt);
	return(ret);
}

char * crypt_r(const char * key, const char * salt, 
		struct crypt_data * data) {
	static char * (*real_crypt_r)(const char *, const char *, struct crypt_data *) = NULL;
	char * ret = NULL;


	if (!real_crypt_r) real_crypt_r = dlsym(RTLD_NEXT, "real_crypt_r");
	ret = real_crypt_r(key, salt, data);
	printf("%s = crypt(%s, %s, %p)\n", ret, key, salt, data);
	return(ret);
}
