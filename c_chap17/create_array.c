#include <stdio.h>//printf()
#include <stdlib.h>
#define N 10

int * create_array(int n, int initial_value)
{
	int *p=calloc(N,sizeof(int));
	if (NULL!=p)
	{
		for (int i=0;i<N;++i)
		{
			p[i]=initial_value;
		}
	}
	return p;
}
int main()
{
	int *p=create_array(N,3);
	if (NULL==p)
	{
		printf("allocate error\n");
		return -1;
	}
	for (int i=0;i<N;++i)
	{
		printf("%d ",p[i]);
	}
	printf("\n");
	return 0;
}
