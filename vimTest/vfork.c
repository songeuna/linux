#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int glob = 6;
int main(void)
{
				int var;
				pid_t pid;

				var = 88;
				printf("before vfork\n");

				if((pid = vfork()) < 0) perror("vfork error"); //호출되지 않으면 error 출력

				else if(pid == 0) //값이 보이지 않지만 pid는 부모 한번 자식 한번 할당이 됨 그래서 pid 값이 +2씩 출력
				{
								glob++;
								var++;
								exit(0);
				}	//부모프로세서랑 자식이랑은 동시에 돌지 않으므로 else로 부모일때의 조건은 걸어줄 필요가 없음

				printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
				exit(0);
}
