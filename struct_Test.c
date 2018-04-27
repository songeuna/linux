#include<stdio.h>

struct Test1{
	char a;
	char b;
	short c;
	int d;
};

int main()
{
	struct Test1 t;
	printf("%p\n",&t.a);
	printf("%p\n",&t.b);
	printf("%p\n",&t.c);
	printf("%p\n",&t.d);
}
