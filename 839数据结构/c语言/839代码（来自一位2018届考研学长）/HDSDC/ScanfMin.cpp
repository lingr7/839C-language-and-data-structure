#include<stdio.h>
#include<stdarg.h>
#include<string.h>
#include<ctype.h>
void minscanf(char *fmt,...){
	char *sval,localfmt[100],*p;
	int *ival,i=0;
	unsigned *uval;
	va_list ap;
	va_start(ap,fmt);
	for(p=fmt;*p;p++){
		if(*p!='%'){
	    	localfmt[i++]=*p;
	    	continue;
		}
		for(;!isalpha(*p);p++)
			localfmt[i++]=*p;
		localfmt[i++]=*p;
		localfmt[i]='\0';
		switch(*p){
			case 'o':
			case 'u':
			case 'x':
			case 'X':uval=va_arg(ap,unsigned*);
					 scanf(localfmt,uval);break;
			case 'd':ival=va_arg(ap,int*);
					 scanf(localfmt,ival);break;
			case 's':sval=va_arg(ap,char*);
					 scanf(localfmt,sval);
			default:scanf(localfmt);break;
		}
		i=0;
	}
	va_end(ap);
}
int main(){
	int a;
	unsigned b;
	minscanf("sf%dfsno%x",&a,&b);
	printf("%d, %d",a,b);
	return 0;
}
