#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	FILE *fp=fopen("D:\\lw.dat","rb");
	int  c;
	int i=0;
	char s[17];
	if(fp==NULL){
		printf("Cannot open this file\n");
		exit(1);
	}
	c=fgetc(fp);	
	while(!feof(fp)){ 
		if(i%16==0) printf("%.8x  ",i); 
		if(isprint(c)) s[i%16]=(char)c;
		else s[i%16]='.';
		printf("%.2x ",c);
		i++;
		if(i%8==0)  printf(" ");
		if(i%16==0){
			s[16]='\0';
			printf(" %s",s);
			printf("\n");
		}
		c=fgetc(fp); 
		if(feof(fp)){
			for(int j=16-i%16;j>0;j--) printf("   ");
			printf(" ");
			s[i%16]='\0';
			printf(" %s",s);
		}
	}
	fclose(fp);
	return 0;
} 
