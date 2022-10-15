#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
int main()
{
	void *handle;
	int (*add)(int, int), (*sub)(int, int), (*mult)(int, int), (*div)(int, int);
	char *error;
	handle = dlopen ("./lib/libtest.so", RTLD_LAZY);
	if (!handle) {
		fputs (dlerror(), stderr);
		exit(1);
	}
	add = dlsym(handle, "add");
	if ((error = dlerror()) != NULL) {
		fprintf (stderr, "%s", error);
		exit(1);
	}
	sub = dlsym(handle, "sub");
	if ((error = dlerror()) != NULL) {
		fprintf (stderr, "%s", error);
		exit(1);
	}
	mult = dlsym(handle, "mult");
	if ((error = dlerror()) != NULL) {
		fprintf (stderr, "%s", error);
		exit(1);
	}
	div = dlsym(handle, "div");
	if ((error = dlerror()) != NULL) {
		fprintf (stderr, "%s", error);
		exit(1);
	}

	printf ("add(1,2)=%d\n", (*add)(1,2));
	printf ("substract(1,2)=%d\n", (*sub)(1,2));
	printf ("multiply(1,2)=%d\n", (*mult)(1,2));
	printf ("divide(1,2)=%d\n", (*div)(1,2));
	dlclose(handle);
	return 0;
}


