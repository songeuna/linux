#include<stdio.h>
#include<stdlib.h>
#define DATA if(data==num*num) break;
void main(void)
{
	int **snail;
	int i = 0, j = 0;
	int num , count;
	int countx = 0;
	int county = 0;
	int data = 0;
	int d = 0;

	printf("사이즈를 입력하세요 : ");
	scanf("%d",&num);
	
	snail = malloc(sizeof(int *) * num);
	
	for(i = 0; i <= num; i++){
		snail[i] = malloc(sizeof(int *) * num);
	}

	i = 0;

	county = countx = num;

	while(data < num*num){
		while(j < county){
			DATA;
			snail[i][j] = ++data;
			//printf("1. %d %d %d\n",i,j,snail[i][j]);
			j++;
		}
		j--;
		i++;
		county--;

		while(i < countx){
			DATA;
			snail[i][j] = ++data;
			//printf("2. %d %d %d\n",i,j,snail[i][j]);
			i++;
		}
		countx--;
		i--;
		j--;
			
		while(j >= d){
			DATA;
			snail[i][j] = ++data;
			//printf("3. %d %d %d\n",i,j,snail[i][j]);
			j--;
		}
		j++;
		i--;

		while(i > d){
			DATA;
			snail[i][j] = ++data;
			//printf("4. %d %d %d\n",i,j,snail[i][j]);
			i--;
		}
		j++;
		i++;
		d++;
	}



//출력
	for(i = 0; i < num; i++){
		for(j = 0; j < num; j++)
			printf("|  %d  |",snail[i][j]);
		printf("\n");
	}
		printf("\n");

	
}
