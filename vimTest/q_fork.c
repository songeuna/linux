#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{	
				pid_t pid;
				int sum1 = 0,sum2 = 0;


				pid = fork();//fork로 자식프로세서 생성

				switch(pid)
				{
								case -1: //fork가 실행 안됌
												perror("Fail");
												exit(1);

								case 0: //자식프로세서
												for(int i = 5001; i <= 10000; i++)
																sum1 += i;
												printf("child : %d\n",sum1);
												break;

								case 1:
												for(int i = 1; i <= 5000; i++)
																sum2 += i;
												printf("parent : %d\n",sum2);
												break;
				}

				if(pid != 0)
				{
								int stat_val;
								pid_t child_pid;

								child_pid = wait(&stat_val); //자식프로세스가 끝나면 stat_val에 값을 리턴(정상종료 : 종료된 자식프로레스 PID)

								if(WIFEXITED(stat_val)) 
																printf("exit\n");
								else
												printf("signal\n");
				}
}
