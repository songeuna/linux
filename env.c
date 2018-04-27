#include<stdio.h>
#include<stdlib.h>

extern char **environ;

int main()
{
	setenv("MYDIR","/home/pi",0);
	setenv("KENEL_SRC","/usr/src/linux",0);
	
	printf("MYDIR = %s\n", getenv("MYDIR"));
	printf("KERNEL_SRC = %s\n", getenv("DERNEL_SRC"));

	//현재 설정된 환경 변수 값을 모두 출력할 경우

	
	while(*environ)
		printf("%s\n",*environ++);
	
	
	return 0;
}
