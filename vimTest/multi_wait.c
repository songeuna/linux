/*************************************************************************\
*                  Copyright (C) Michael Kerrisk, 2017.                   *
*                                                                         *
* This program is free software. You may use, modify, and redistribute it *
* under the terms of the GNU General Public License as published by the   *
* Free Software Foundation, either version 3 or (at your option) any      *
* later version. This program is distributed without any warranty.  See   *
* the file COPYING.gpl-v3 for details.                                    *
\*************************************************************************/

/* Listing 26-1 */

#include <sys/wait.h>
#include <time.h>
#include "curr_time.h"              /* Declaration of currTime() */
#include "tlpi_hdr.h"

int
main(int argc, char *argv[])
{
    int numDead;       /* Number of children so far waited for */
    pid_t childPid;    /* PID of waited for child */
    int j;

    if (argc < 2 || strcmp(argv[1], "--help") == 0)  //arg값이 2개 미만이거나 --help가 입력될때
        usageErr("%s sleep-time...\n", argv[0]);	

    setbuf(stdout, NULL);   //stdout이 버퍼링 되지 않게 한다        /* Disable buffering of stdout */
		
    for (j = 1; j < argc; j++) { //argc-1 만큼 자식 프로세서 생성  /* Create one child for each argument */
        switch (fork()) { 
        case -1: //fork 실행 실패
            errExit("fork");

        case 0:  //자식 프로세서 생성                   /* Child sleeps for a while then exits */
            printf("[%s] child %d started with PID %ld, sleeping %s "
                    "seconds\n", currTime("%T"), j, (long) getpid(),
                    argv[j]);

            sleep(getInt(argv[j], GN_NONNEG, "sleep-time")); //getInt => tlpi_hdr.h 파일에 선언, arg가 가르키는 문자열을 각각 int, long으로 변환
																														 //getInt(const char *arg, int flags, const char *name);
            
						_exit(EXIT_SUCCESS);

        default:                    /* Parent just continues around loop */
            break;
        }
    }

    numDead = 0; //죽은 자식프로세서 갯수
    
		for (;;) {                      /* Parent waits for each child to exit */
        childPid = wait(NULL);
        
				if (childPid == -1) { //기다릴 자식 프로세서가 없으면

								if (errno == ECHILD) 
								{
												printf("No more children - bye!\n");
												exit(EXIT_SUCCESS);
            		} 
						
								else
								{                /* Some other (unexpected) error */
												errExit("wait");
            		}
        }

        numDead++;

        printf("[%s] wait() returned child PID %ld (numDead=%d)\n",
                currTime("%T"), (long) childPid, numDead);
    }
}
