#include <stdio.h>

struct
{
	union
	{
		char a;
		char b;
		int c;
	}d;
	int e[5];
}f,*p=&f;

int main()
{
	p->e[3]=10;
	(*p).d.a='*';

	printf("%d\n%c\n%c\n",p->e[3],(*p).d.a,(*p).d.b);
	return 0;
}
