#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
#define LONGLINE 80
int getline(char line[], int maxline);
void copy(char to[], char from[]);
/* print the longest input line */
main()
{
	int len; /* current line length */
	int max; /* maximum length seen so far */
	char line[MAXLINE]; /* current input line */
	char longest[MAXLINE]; /* longest line saved here */
	
	max = 0;
	while ((len = getline(line, MAXLINE)) > LONGLINE){
		printf("%d, %s", len, line);
	}
	return 0;
}
/* getline: read a line into s, return length */
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

