#include<stdio.h>
/* Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter?*/
#define MAXLINE 1000
#define TABWIDTH 4
int get_line(char line[], int maxline);
void detab(char to[], char from[]);
main() 
{
	int len;
	char line[MAXLINE];
	char nline[MAXLINE];

	while((len = get_line(line, MAXLINE)) > 0) {
		detab(nline, line);
		printf("%s", nline);
	}
}

// get_line: reads a line s, return line length
int get_line(char s[], int lim) {
	int i, c;

	for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) {
		s[i] = c;
	}
	if(c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';

	return i;
}

// detab: replace tabs with blanks
void detab(char to[], char from[]) {
	int i, j, n;

	i = j = n = 0;
	while((to[j] = from[i]) != '\0') {
		if(to[j] == '\t') {
			for(n=0; n<TABWIDTH; ++n, ++j) {
				to[j] = ' ';
			}
		}
		else {
			++j;
		}
		++i;
	}
}
