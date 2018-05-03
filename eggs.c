#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#define BUF_SIZE 10

int main(void)
{
	char temp[10];
	char rbuf[10];
	int fd;
	int wcount;
	int rcount;

	fd = open("./test.txt", O_RDWR | O_CREAT | O_TRUNC, \
		S_IRWXU | S_IWGRP | S_IRGRP | S_IROTH);

	if(fd == -1){
		printf("file open error\n");
		return -1; //비정상적인 종료
	}
	
	sprintf(temp,"test\n");		//문자열 copy
	
	write(1,temp,strlen(temp));	//temp를 stdout으로 출력
	
	wcount = write(fd,temp,strlen(temp));	//text.txt파일에 문자열 쓰기
	printf("wcount = %d\n",wcount);		//파일에 쓴 문자열 갯수 출력
	
	lseek(fd, 0, SEEK_SET);			//lseek로 파일 포인터(파일오프셋)을 파일의 시작(SEEK_SET으로이동) 책 152p 참고
	
	rcount = read(fd,rbuf,BUF_SIZE);	//파일 읽기 -> rbuf배열에 채움
	printf("rcount = %d\n",rcount);		//읽은 문자열 갯수 출력

	printf("rbuf = %s",rbuf);
	printf("fd = %d\n",fd); //3, 0은 stdin, 1은 stdout, 2는 stderr 를 무조건 받음 따라서 fd값은 최소가 3부터

	close(fd);
	/*
	fd = creat("./test2.txt", 0764);
	
	if(fd == -1){
		printf("file creat error\n");
		return -1;
	}
	
	printf("fd = %d\n",fd); //3 위에 close를 했기때문에 fd값은 반납

	close(fd);
	*/
	return 0;
}
