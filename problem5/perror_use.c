#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void myperror(const char* str){
	printf("%s error message: %s \n",str,strerror(errno));
}

int main(int argc, char *argv[])
{
	FILE *f;
	if(argc<2) {
		printf("Usage : myperror_use file_name\n");
		exit(1);
	}
	if((f=fopen(argv[1], "r"))==NULL) {
		myperror("fopen");
		exit(1);
	}
	printf("Open a file %s ", argv[1]);
	fclose(f);
}
