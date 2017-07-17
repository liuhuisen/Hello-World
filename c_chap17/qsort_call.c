#include <stdio.h>
#include <stdlib.h>//qsort(),srand(),rand()
#include <time.h>//time()
#define N 100

int comp(const void * first,const void * second)
{
	return *(const int *)first-*(const int *)second;
}

int main()
{
	srand(time(NULL));
	int arr[N];
	for (int i=0;i<N;++i)
	{
		arr[i]=rand()%(N*10);
	}
	
	printf("----Befoe sort----\n");
	for (int i=0;i<N;++i)
	{
		printf("%d ",arr[i]);
	}
	printf("\n\n");

	//sort
	qsort(&arr[50],50,sizeof(int),comp);

	//output
	printf("----After sort----\n");
	for (int i=0;i<N;++i)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
