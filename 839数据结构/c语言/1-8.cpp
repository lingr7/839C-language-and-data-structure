#include <stdio.h>
main(){
	int c, n1, n2, n3;
	n1 = 0;
	n2 = 0;
	n3 = 0;
	while((c = getchar()) != EOF){
		if(c == 32)//空格 ' '
			n1++;
		else if(c == 9)//制表符'\t'
			n2++;
		else if(c == 10) //换行符'\n'
			n3++;	
	} 
	printf("%d %d %d\n", n1, n2, n3); 
}
