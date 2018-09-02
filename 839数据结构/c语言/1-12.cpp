#include <stdio.h>
#define IN 1/*inside a word		*/
#define OUT 0/*outside a word 	*/
/*print input one word per line */
main(){
	int c, state;
	state = OUT;
	while((c = getchar()) != EOF){
		if ( c == ' ' || c == '\n' || c == '\t'){
			if (state == IN) {/*finish word*/
				putchar('\n');
				state = OUT;
			}	
		} else if (state == OUT) {/*begin the word*/
			state = IN;
			putchar(c);
		} else
			putchar(c);/*inside word*/
	}
		
}
