#include<stdio.h>
#define L 128
typedef struct{
	int length;
	char value[L];
}LNUM;
int add(LNUM a,LNUM b,LNUM *c){
	int i;
	for(i=0;i<L;i++) c->value[i]='0';
	for(i=L-1;i>L-a.length-1||i>L-b.length-1;i--){
		int d=a.value[i]-'0'+b.value[i]-'0'+c->value[i]-'0';
		if(d>=10&&i>0)	 c->value[i-1]='1';
		if(d>=10&&i==0)  return 1;
		c->value[i]=d%10+'0';
	}
	for(i=0;i<L;i++)
		if(c->value[i]!='0') break;
	c->length=L-i;
	return 0;
}
int main(){
	LNUM a,b,c;
	int i,j;
	a.length=b.length=13;
	for(i=0;i<128;i++)
		b.value[i]=a.value[i]='0';
	for(i=127;i>=115;i--)
		a.value[i]=(i-113)%9+'1';
	for(i=127;i>=115;i--)
		b.value[i]=(i%34-7)%10+'0';
	add(a,b,&c);
	for(i=L-a.length;i<L;i++)        //·´ÏòÊä³ö 
		printf("%c",a.value[i]);
	putchar('\n');
	for(i=L-b.length;i<L;i++)
		printf("%c",b.value[i]);
	printf("\nThe total:\n");
	for(i=L-c.length;i<L;i++)
		printf("%c",c.value[i]);	
	return 0;
}
