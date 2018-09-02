#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void a2b(unsigned n){
	if(n/2) a2b(n/2);
	printf("%d",n%2);
}
void PRINT(char fmt[],unsigned value){
	int i;
	for(i=0;i<strlen(fmt);i++){
		if(fmt[i]!='%'){
			putchar(fmt[i]);
			continue;
		}
		switch(fmt[++i]){
			case 'b':
					a2b(value);break;
			case 'u':
					printf("%u",value);break;
			case 'x':
					printf("%x",value);break;
			case 'o':
					printf("%o",value);break;
			default:
					printf("%%c",fmt[i]);break; 	
		}
	}
}
int main(){
	PRINT("¶þ½øÖÆ: %u\nsdfds",12);
	return 0;
}
