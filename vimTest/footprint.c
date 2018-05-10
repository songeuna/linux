/*************************************************************************\
*                  Copyright (C) Michael Kerrisk, 2017.                   *
*                                                                         *
* This program is free software. You may use, modify, and redistribute it *
* under the terms of the GNU General Public License as published by the   *
* Free Software Foundation, either version 3 or (at your option) any      *
* later version. This program is distributed without any warranty.  See   *
* the file COPYING.gpl-v3 for details.                                    *
\*************************************************************************/

/* Listing 24-3 */

#define _BSD_SOURCE     /* To get sbrk() declaration from <unistd.h> in case
                           _XOPEN_SOURCE >= 600; defining _SVID_SOURCE or
                           _GNU_SOURCE also suffices */
#include <sys/wait.h>
#include "tlpi_hdr.h"

static int
func(int arg)
{
    int j;

    for (j = 0; j < 0x100; j++)
        if (malloc(0x8000) == NULL) //0x8000 사이즈만큼 할당 못했을때
            errExit("malloc");
 
		printf("Program break in child:  %10p\n", sbrk(0)); //sbrk(0) : 데이터 세그먼트의 최하위 주소를 얻을때
																												//sbrk(a) : a만큼호출 브레이크를 증가시킴, 성공시 프로그램 브레이크의 이전 주소 리턴

    return arg;
}

int
main(int argc, char *argv[])
{
    int arg = (argc > 1) ? getInt(argv[1], 0, "arg") : 0; //arg는 argc가 1보다 크면 getInt값, 아니면 0
    pid_t childPid;
    int status;

    setbuf(stdout, NULL);  //stdout을 NULL로 set         /* Disable buffering of stdout */

    printf("Program break in parent: %10p\n", sbrk(0));

    childPid = fork();	//자식 프로세서 생성

    if (childPid == -1)		//fork 실행 실패시
        errExit("fork");

    if (childPid == 0)    //자식 프로세서일때          /* Child calls func() and */
        exit(func(arg));  //func(arg)을 리턴값으로 종료. 따라서 func(arg)의 리턴값이 child 프로세서의 리턴값   /* uses return value as exit status */

    /* Parent waits for child to terminate. It can determine the
       result of func() by inspecting 'status' */

    if (wait(&status) == -1)	//status에 자식프로세서 종료 상태값을 저장, 그 값이 -1 = 자식프로세서가 없다
        errExit("wait");

    printf("Program break in parent: %10p\n", sbrk(0));

    printf("Status = %d %d\n", status, WEXITSTATUS(status));

    exit(EXIT_SUCCESS);
}
