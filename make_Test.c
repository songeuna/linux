#define MUL2(x,y) (x*y)
#define MUL3(x,y) ((x)*(y))
#include<stdio.h>
void main()
{
	int a=1, b=2, c=3, d=4, k=0;
	k=MUL2(a+b,c+d);
	printf("%d\n",k);

	k=MUL3(a+b,c+d);	
	printf("%d\n",k);
}
