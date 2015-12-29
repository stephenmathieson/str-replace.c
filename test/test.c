#include <stdio.h>
#include "str-replace.h"


int
main(void)
{

	char phrase[] = "linux OS it is better for pentesters";
	printf("normal: %s\n", phrase);
	printf("replaced: %s\n", str_replace(phrase, "linux", "Window"));

	return 0;
}