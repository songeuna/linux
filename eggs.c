#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#define BUF_SIZE 100

int main(void)
{
	char temp[100];
	char rbuf[100];
	char pbuf[100];
	char strBuffer[100]={"eggs"};
	int fd;
	int wcount;
	int rcount;
	//off_f offset;

	fd = open("./test.txt", O_RDWR | O_CREAT | O_TRUNC, \
		S_IRWXU | S_IWGRP | S_IRGRP | S_IROTH);

	if(fd == -1){
		printf("file open error\n");
		return -1; //비정상적인 종료
	}
	
	sprintf(temp,"Do not count the before they hatch.");
	
	wcount = write(fd,temp,strlen(temp));	
	//printf("wcount = %d\n",wcount);		
	
	
	lseek(fd, 0, SEEK_SET);		
	//rcount = read(fd,rbuf,BUF_SIZE);	//파일 읽기 -> rbuf배열에 채움
	rcount = read(fd,rbuf,17);
	rbuf[rcount]='\0';
	sprintf(pbuf,"%s", rbuf);

	rcount = read(fd, strBuffer,BUF_SIZE);
	strBuffer[rcount]='\0';
	
	strcat(pbuf, "eggs ");
	strcat(pbuf, strBuffer);
	
	printf("%s\n",pbuf);

//	printf("%s\n",strBuffer);
//	printf("rcount = %d\n",rcount);		//읽은 문자열 갯수 출력
	
	wcount = write(fd, pbuf, strlen(pbuf));
//	printf("pbuf = %s\n",pbuf);
//	printf("fd = %d\n",fd); //3, 0은 stdin, 1은 stdout, 2는 stderr 를 무조건 받음 따라서 fd값은 최소가 3부터

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
