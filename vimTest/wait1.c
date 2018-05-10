#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
				pid_t pid;
				char *message;
				int n;
				int exit_code;
			
				//프로그램 시작시 문자열 출력
				printf("fork program starting\n");
				
				//fork함수로 자식프로세서 호출
				pid = fork();

				switch(pid)
				{
								case -1:	//fork가 실행 안된경우
												perror("fork failed");
												exit(1);
								case 0:		//자식프로세서인 경우
												message = "This is the child";
												n = 5;
												exit_code = 37;
												break;
								default:	//부모프로세서인 경우
												message = "This is the parent";
												n = 3;
												exit_code = 0;
												break;
				}

				for(; n > 0; n--)
				{
								puts(message);
								sleep(1);
				}

				if(pid != 0)	// 부모 프로세스인 경우 실행
				{
								int stat_val;
								pid_t child_pid;

								child_pid = wait(&stat_val); //자식 프로세서가 끝나길 기다림.
								printf("Child has finished: PID = %d\n", child_pid);

								if(WIFEXITED(stat_val))	//정상종료조건 
												printf("Child exited with code %d\n", WEXITSTATUS(stat_val));
								else
												printf("Childe terminated abnormally\n");
				}

				exit(exit_code);
}

