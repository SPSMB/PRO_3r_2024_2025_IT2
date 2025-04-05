#include <stdio.h>
#include <string.h>

// potlaci warning o zastarale funkci (scanf apod)
#pragma warning(disable:4996)

int main(int argc, char ** argv){

	for(int i = 0; i < argc; i++){
		printf("%d: %s\n", i, argv[i]);
	}

	
	return 0;

}