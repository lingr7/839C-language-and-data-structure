#include <stdio.h>

#define MAXHIST 15		/*max length of histogram	*/
#define MAXWORD 11		/*max length of a word		*/
#define IN		1		/*inside a word 			*/
#define OUT		0		/*outside a word 			*/

/*print vertical histogram							*/
main(){
	int c, i, j, nc, state;
	int len;			/*length of each other		*/
	int maxvalue;		/*maximum value for wl[]	*/
	int ovflow;			/*number of overflow words	*/
	int wl[MAXWORD];	/*word length counters		*/
	
	state = OUT;
	nc = 0;				/*number of chars in a word */
	ovflow = 0;			/*number of words >= MAXWORD*/
	for (i = 0; i < MAXWORD; ++i)
		wl[i] = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t'){
			state = OUT;
			if (nc > 0)
				if (nc < MAXWORD)
					++wl[nc];
				else 
					++ovflow;
			nc = 0;
		} else if (state == OUT){
			state = IN;
			nc = 1;		/*beginning of a new word	*/
		}else
			++nc;		/*inside a word				*/
	}
	/*手动到达EOF才会执行下面的代码*/
	maxvalue = 0;
	for (i = 1; i < MAXWORD; ++i)
		if(wl[i] > maxvalue)
			maxvalue = wl[i];
	/*以上与水平直方图完全相同*/
	for (i = MAXHIST; i > 0; --i){
		for (j = 1; j < MAXWORD; ++j){
			if(wl[j] * MAXHIST / maxvalue >= i)
				printf("   * ");
			else 
				printf("     ");
		}
		putchar('\n');
	}
	for (i = 1; i < MAXWORD; ++i)
		printf("%4d ", i);
	putchar('\n');
	for (i = 1; i < MAXWORD; ++i)
		printf("%4d ", wl[i]);
	putchar('\n');
	if (ovflow > 0)
			printf("There are %d words >= %d\n", ovflow, MAXWORD);
}
