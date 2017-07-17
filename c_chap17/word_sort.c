#include <stdio.h>//printf()
#include <stdlib.h>//qsort(),calloc()
#include <string.h>//strcmp(),strlen()
#define N 10

int word_comp(const void * first,const void * second);
char * readline(const char * prompt);

int main()
{
	char ** word_arr;
	int n=N;
	word_arr=calloc(n,sizeof(char *));//initial allocated memory
	if (NULL==word_arr)
	{
		printf("allocate error!\n");
		return -1;
	}
	int cur_n=0;
	char *p=NULL;//a pointer temporarily point to entered word
	while (1)
	{
		p=readline("Enter word: ");
		if (0==strlen(p))
		{
			break;
		}
		if (cur_n==n)//the word array is full,expand the memory
		{
			n*=2;
			//word_arr=(char **)realloc(word_arr,n);
			char ** temp=calloc(n,sizeof(char*));
			if (NULL==temp)
			{
				printf("allocate error!\n");
				return -1;
			}
			for (int i=0;i<cur_n;++i)
			{
				temp[i]=word_arr[i];
			}
			free(word_arr);
			word_arr=temp;
			temp=NULL;
		}
		if (NULL!=p)
		{
			word_arr[cur_n++]=p;
			p=NULL;
		}
	}

	//output the word array before sort
	for (int i=0;i<cur_n;++i)	
	{
		printf("%s\n",word_arr[i]);
	}
	printf("\n");

	//sort word array
	qsort(&word_arr[0],cur_n,sizeof(word_arr[0]),word_comp);

	//output the word array after sort
	for (int i=0;i<cur_n;++i)
	{
		printf("%s\n",word_arr[i]);
	}
	printf("\n");

	return 0;
}

int word_comp(const void * first,const void * second)
{
	return strcmp(*(const char **)first,*(const char **)second);
}

char * readline(const char * prompt)
{
	if (NULL!=prompt&&strcmp("",prompt))
	{
		printf("%s",prompt);
	}
	char buf[21];
	int ch;
	int i=0;
	while ((ch=getchar())!=EOF&&ch!='\n')
	{
		buf[i++]=ch;
	}
	buf[i]='\0';
	char * newline=calloc(strlen(buf)+1,sizeof(char));
	if (NULL!=newline)
	{
		strcpy(newline,buf);
	}
	return newline;
}
