#include <stdio.h>
#define MAXLINE  1000/*maximum input line size*/

int getline(char line[], int maxline);
int remove(char s[]);

/*remove trading blanks and tabs, and delete blank lines*/
main(){
	char line[MAXLINE]; /*current input line */
	
	while (getline(line, MAXLINE) > 0)
		if (remove(line) > 0)
			printf("%s", line);
	return 0;
}
/* getline: read a line into s, return length */
/*j记录了被复制到字符串s里的字符的个数*/
int getline(char s[],int lim)
{
	int c, i, j;
	j = 0;
	for (i=0; (c=getchar())!=EOF && c!='\n'; ++i)
		if (i < lim-2 ){
			s[j] = c;
			++j;
		}
	if (c == '\n') {
		s[j] = c;
		++i;
		++j;
	}
	s[j] = '\0';
	return i;
}
