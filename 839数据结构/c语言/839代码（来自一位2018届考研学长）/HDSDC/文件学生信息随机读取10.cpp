#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
typedef struct Std{
	int   num;
	char  name[20];
	int   score;	
}Std;
int compare(const void*a,const void *b){
	return ((Std*)a)->num-((Std*)b)->num;
}
main(){
	FILE *fp;
	Std  s[32];
	Std  news[10];
	int rand0[10];
	int i,j=0,f=1,randNum;
	if((fp=fopen("D:\\liu.dat","r"))==NULL){
		printf("Cannot open this file.\n");
		exit(1);
	}
	for(i=0;i<32;i++)
	fscanf(fp,"%d%s%d",&s[i].num,&s[i].name,&s[i].score);
	fclose(fp);
	for(i=0;i<10;i++){
		
		while(f){f=0;
			randNum=rand()%32;
			for(j=0;j<i;j++) 
				if(randNum==rand0[i]){
					f=1;
					break;
				}
			 	
		}
		rand0[i]=randNum;
		memcpy(&news[i],&s[i],sizeof(Std));		
	}
	qsort(news, 10, sizeof(Std), compare);
	for(i=0;i<10;i++){
		printf("%-10d%10s%6d\n",news[i].num,news[i].name,
		news[i].score);
	}
	return 0;
}
