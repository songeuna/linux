#include<stdio.h>
#include<math.h>

int f(int x)
{
	int time=0;
	int sqr = 1;

	while((x)%2 != 1)
	{
		x = x/2;
		time++;
	}
	
	for(int i=0; i < time; i++)
		sqr = sqr * 2;

	return sqr;
}


void main()
{	
	int a = 0, b = 0;
	int sum = 0 ;
	
	printf("a 입력 : ");
	scanf("%d",&a);

	printf("B 입력 : ");	
	scanf("%d", &b);
	

	if(a > b)
		printf("B가 더 커야합니다\n");

	else{
		for(int i = a; i <= b; i++)
			sum = sum + f(i);
	}

	printf("%d\n",sum);
}
























