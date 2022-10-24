#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
int main()
{
	void *handle;
	int (*add)(int, int), (*substract)(int, int), (*multiply)(int, int), (*divide)(int, int);
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
	substract = dlsym(handle, "addsubstract");
	if ((error = dlerror()) != NULL) {
		fprintf (stderr, "%s", error);
		exit(1);
	}
	multiply = dlsym(handle, "multiply");
	if ((error = dlerror()) != NULL) {
		fprintf (stderr, "%s", error);
		exit(1);
	}
	divide = dlsym(handle, "divide");
	if ((error = dlerror()) != NULL) {
		fprintf (stderr, "%s", error);
		exit(1);
	}

	printf ("add(1,2)=%d\n", (*add)(1,2));
	printf ("substract(1,2)=%d\n", (*substract)(1,2));
	printf ("multiply(1,2)=%d\n", (*multiply)(1,2));
	printf ("divide(1,2)=%d\n", (*divide)(1,2));
	dlclose(handle);
	return 0;
}


