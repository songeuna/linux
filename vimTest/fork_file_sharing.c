/*************************************************************************\
*                  Copyright (C) Michael Kerrisk, 2017.                   *
*                                                                         *
* This program is free software. You may use, modify, and redistribute it *
* under the terms of the GNU General Public License as published by the   *
* Free Software Foundation, either version 3 or (at your option) any      *
* later version. This program is distributed without any warranty.  See   *
* the file COPYING.gpl-v3 for details.                                    *
\*************************************************************************/

/* Listing 24-2 */

#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "tlpi_hdr.h"

int
main(int argc, char *argv[])
{
    int fd, flags;
    char template[] = "/tmp/testXXXXXX"; //mkstemp의 경로명, 반드시 마지막 6자는 X형태, 파일이름을 고유하게 하는 문자열로 대체된다.

    setbuf(stdout, NULL); //stdout을 NULL로 셋팅            /* Disable buffering of stdout */

    fd = mkstemp(template);	//mkstemp : 파일의 소유자가 읽기와 쓰기 권한을 갖도록(다른 사용자는 권한 X) 파일생성, 호출자의 배타적 접근을 보장

		if (fd == -1)//파일 open이 실패하면 실행
        errExit("mkstemp");

    printf("File offset before fork(): %lld\n",
            (long long) lseek(fd, 0, SEEK_CUR));

    flags = fcntl(fd, F_GETFL);//fcntl() : 접근 모드와 열린 파일 상태 플래그를 읽거나 수정. 
															 //fcntl(int fd, int cmd, ...);
															 //매개변수로 사용
    
		if (flags == -1)//파일 수정 실패시 
        errExit("fcntl - F_GETFL");
    
		printf("O_APPEND flag before fork() is: %s\n",
            (flags & O_APPEND) ? "on" : "off"); //

    switch (fork()) { 
    case -1:	//fork 실패시
        errExit("fork");

    case 0:   //자식프로세서 /* Child: change file offset and status flags */
        if (lseek(fd, 1000, SEEK_SET) == -1) //fd의 파일오프셋을 파일의 시작으로부터, 1000번째 떨어진곳으로 설정
            errExit("lseek");

        flags = fcntl(fd, F_GETFL);//현재 플래그         /* Fetch current flags */
        													 //F_GETFL이 무엇인지? : Read the file descriptor flags; arg is ignored.
				if (flags == -1)
            errExit("fcntl - F_GETFL");
        
				flags |= O_APPEND;     //O_APPEND : 언제나 파일끝에 추가해서 씀             /* Turn O_APPEND on */
        											 //O_APPEND 설정 (왜? 이게 설정인지? : )
				
				if (fcntl(fd, F_SETFL, flags) == -1) //
            errExit("fcntl - F_SETFL");
        
				_exit(EXIT_SUCCESS);

    default:    /* Parent: can see file changes made by child */
        if (wait(NULL) == -1)	//wait(NULL) : 자식프로세서 종료시 종료상태값을 받지 않겠다.
            errExit("wait");                /* Wait for child exit */
        
				printf("Child has exited\n");

        printf("File offset in parent: %lld\n",
                (long long) lseek(fd, 0, SEEK_CUR));

        flags = fcntl(fd, F_GETFL);
        
				if (flags == -1)
            errExit("fcntl - F_GETFL");
        
				printf("O_APPEND flag in parent is: %s\n",
                (flags & O_APPEND) ? "on" : "off");
        
				exit(EXIT_SUCCESS);
    }
}
