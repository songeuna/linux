#include<sys/types.h>
#include<unistd.h>


void pr_exit(int status)
{
			//정상 종료인 경우
			if (WIFEXITED(status))
							printf("normal termination, exit status = %d\n",WEXITSTATUS(status));
		
			//시그널에 의해서 종료된 경우
			else if(WIFSIGNALED(status))
							printf("abnormal termination, signal number = %d%s\n", WTERMSIG(status),
															WCOREDUMP(status) ? "(core file generated)" : "");
			
			else if WIFSTOPPED(status))
							printf("child stopped, signal number = %d\n",WSTOPSIG(status));
}
