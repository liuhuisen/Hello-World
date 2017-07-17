#include <stdio.h>//printf()
#include <stdlib.h>//calloc()
#include <string.h>//strlen(),strcpy()

void * str_duplicate(char * str)
{
	char * str_copy=calloc(strlen(str)+1,sizeof(char));
	if (NULL!=str_copy)
	{
		strcpy(str_copy,str);
	}
	return str_copy;
}

int main()
{
	char str[]="This is a test string";
	char * str_copy=str_duplicate(str);
	printf("%s\n%s\n",str,str_copy);
	return 0;
}
