#include<stdio.h> 
#include<stdarg.h>
#include<ctype.h>
void  minprintf(char *fmt,...){
	 va_list ap;
	 char *s,localfmt[100],*p;
	 int n,idval,i;
	 unsigned uval;
	 va_start(ap,fmt);
	 for(p=fmt;*p;p++){
	 	if(*p!='%'){
	 		printf("%c",*p);
	 		continue;
		 }
		 i=0;
		 for(;!isalpha(*p);p++)
		 	localfmt[i++]=*p;
		 localfmt[i++]=*p;
		 localfmt[i]='\0';		 
		 switch(*p){
		 	case 'd':idval=va_arg(ap,int);
		 			 printf(localfmt,idval);break;
			case 'u':
			case 'x':
			case 'X':
			case 'o':uval=va_arg(ap,unsigned);
		 			 printf(localfmt,uval);break;
		 	case 's':s=va_arg(ap,char*);
		 			 printf(localfmt,s);break;
		 	default:printf(localfmt);break;	
		 }
	 }
	 va_end(ap);
}
int main(){
	minprintf("sff%d\nsdf%o",3,24);
	return 0;
}
