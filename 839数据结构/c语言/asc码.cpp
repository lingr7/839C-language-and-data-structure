#include <stdio.h>
int main(char argc, char *aegv[]){
	printf("%d\n", '0');
	printf("%d\n", '0'-'\0');/*这个可以获取字符和数字的asc码数值*/
	printf("%d\n", 'a');
	printf("%d\n", 'a'-'\0');
	printf("%c\n", 'a'+1);
	printf("%d\n", '9'-'0');
	return 0;
} 
