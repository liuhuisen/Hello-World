#include <stdio.h>
#include <stdlib.h>
#define N 10

void * my_malloc(size_t n)
{
	void *p=malloc(n);
	if (NULL==p)
	{
		printf("mallocate error!\n");
	}
	return p;
}

int main()
{
	int *p=my_malloc(N);
	for (int i=0;i<N;++i)
	{
		printf("%d ",p[i]);
	}
	printf("\n");

	return 0;
}
