#include<stdio.h>

struct Flags{
	unsigned int a : 1;
	unsigned int b : 3;
	unsigned int c : 7;
};

int main()
{
	struct Flags f1;

	f1.a = 1;
	f1.b = 15;
	f1.c = 255;
	
	printf("%d\n",sizeof(f1));
	//printf("%p\n",&f1.b);//비트필드는 주소값출력불가
	//printf("%p\n",&f1.c);

	printf("%u\n",f1.a);
	printf("%u\n",f1.b);
	printf("%u\n",f1.c);

	return 0;
}
