#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
				pid_t pid;
				int sum = 0 ,sum1 = 0 ,sum2 = 0;

				pid = vfork(); //자식 프로세서가 생성, 부모 정지.


				switch(pid)	//자식만 해당
				{
								case -1:
												perror("fork faild");
												exit(1);

								case 0: //자식프로세서
												for(int i = 5001; i <= 10000; i++)
																sum2 += i;
												printf("child sum2 = %d\n",sum2);
												exit(0);
					
								/*default: //부모프로세서
												for(int i = 1; i <= 5000; i++)
																sum1 += i;
												printf("sum1 = %d\n",sum1);
									*/		
				} //자식 종료 후 부모 다시 실행
	
				for(int i = 1; i <= 5000; i++)
								sum1 += i;

				printf("parent sum1 = %d\n",sum1);

				sum = sum1 + sum2;
				printf("sum = %d\n",sum);

				
				return sum;
}




