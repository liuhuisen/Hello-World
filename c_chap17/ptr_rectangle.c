#include <stdio.h>//printf()
#include <stdlib.h>//calloc()

struct point
{
	int x;
	int y;
};

struct retangle
{
	struct point upper_left;
	struct point lower_right;
};

int main()
{
	struct retangle *p=calloc(1,sizeof(struct retangle));
	if (NULL==p)
	{
		printf("allocate error\n");
		return -1;
	}
	p->upper_left.x=10;
	p->upper_left.y=25;
	p->lower_right.x=20;
	p->lower_right.y=15;
	
	printf("upper_left:(%d,%d)\nlower_right:(%d,%d)\n",p->upper_left.x,p->upper_left.y,p->lower_right.x,p->lower_right.y);

	return 0;
}
