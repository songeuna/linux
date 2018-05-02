#include<stdio.h>
#include<math.h>

int f(int *x, int *time)
{
	int sqr = 1;

	while((*x)%2 != 1)
	{
		*x = *x/2;
		(*time)++;
	}
	
	for(int i=0; i < *time; i++)
		sqr = sqr * 2;

	return sqr;
}


void main()
{	
	int n = 0;
	int time,x;
	int j;
	
	printf("자연수 입력 : ");
	scanf("%d",&n);
	
	x = n;
	
	j = f(&x, &time);

	printf("f(%d) = %d \n",n,j);
}
