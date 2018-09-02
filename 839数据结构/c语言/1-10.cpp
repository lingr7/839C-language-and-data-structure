#include <stdio.h>
#define NONBLANK 'a'
main(){
	int c, lastc;
	lastc = NONBLANK;
	while((c = getchar()) != EOF){
		if ( c == '\t')
			printf("\\t");
		else if (c == '\b')
			printf("\\b");
		else if (c == '\=')
			printf("\\");
		else putchar(c);
	}
		
}
