#include<stdio.h>
#include<stdlib.h>
#include<string.h>

extern char **environ;

int main()
{
	char file_dir[30];
	char file_name[30];
	char result[50];

	printf("FLIEDIR = %s\n",getenv("FILEDIR"));
	printf("FILENAME = %s\n",getenv("FILENAME"));

	sprintf(file_dir,"%s",getenv("FILEDIR"));
	sprintf(file_name,"%s",getenv("FILENAME"));
	sprintf(result,"gcc -o HELLO ");
	
	strcat(result,file_dir);
	strcat(result,file_name);

/*
	printf("%s\n",file_dir);
	printf("%s\n",file_name);
*/

//	system(gcc -o HELLO /home/은아/0426/HELLO.C);
	
	printf("%s\n",result);
	
	system(result);	//결과값 : gcc -o HELLO /home/euna/은아/0426/HELLO.c //HELLO.c파일 컴파일	
	system("./HELLO"); //컴파일한 HELLO를 실행
	return 0;
		
}
