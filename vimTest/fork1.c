#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
				pid_t pid;
				char *message;
				int n;

				printf("fork program starting\n");
				pid = fork();

				switch(pid)
				{
								case -1:
												perror("fork failed");
												exit(1);

								case 0:
												message = "This is the child";
												n = 5;	//자식과, 부모 프로세서 각각에 n 이 선언 되있음
												break;

								default:
												message = "This is the parent";
												n = 3;
												break;
				}

				for(; n > 0; n--)
				{
								puts(message);
								printf("n = %d\n",n);	//자식은 5번, 부모는 3번 반복
								sleep(1);		//wait를 하지 않았기 때문에 부모프로세스가 종료되고 자식프로세스가 종료됨. 그래서 프롬프토 다음에 값이 출력
				}

				exit(0);
}
