#include <stdio.h>
#include <ctype.h>

#define MAXHIST 15		/*max length of histogram			*/
#define MAXCHAR 128		/*max different characters			*/

/*print horizontal histogram freq. of different characters	*/
main(){
	int c, i;
	int len;			/*length of each bar		*/
	int maxvalue;		/*maximum value for cc[]	*/
	int cc[MAXCHAR];	/*character counters		*/
	
	for (i = 0; i < MAXCHAR; ++i)
		cc[i] = 0;
	while ((c = getchar()) != EOF) {
		if (c < MAXCHAR ){
			++cc[c];
		}
	}
	/*手动到达EOF才会执行下面的代码*/
	/*找到出现次数最多的*/
	maxvalue = 0;
	for (i = 1; i < MAXCHAR; ++i)
		if(cc[i] > maxvalue)
			maxvalue = cc[i];
			
	for (i = 1; i < MAXCHAR; ++i){
		if (isprint(i))
			printf("%5d - %c - %5d : ", i, i, cc[i]);//此处体现了数字%c显示该asc2码得其对应字符 
		else
			printf("%5d -    - %5d : ", i, cc[i]);
		if (cc[i] > 0){
			if ((len = cc[i] * MAXHIST / maxvalue) <= 0)
				len = 1;
		} else 
			len = 0;
			
		while (len > 0){
			putchar('*');
			--len;
		}
		putchar('\n');
	}
}
