#include<stdio.h>
#include<unistd.h>

int main(void)
{
				int x;

				x = 0;
				fork();	//fork 는 자식 프로세스를 생성, 부모의 내용을 복사.
				x = 1;
				printf("I am process %ld and my x is %d\n",(long)getpid(),x);
				//printf는 한번이지만 부모에서 한번, 자식에서 한번 총 2번 출력
				//한 버퍼에 두 개의 내용을 입력하는 것이라 문자열이 정리되지 않고 출력될수도 있음!

				return 0;
}
