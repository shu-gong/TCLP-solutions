#include<stdio.h>
/* Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter?*/
#define MAXNTAB 4
#define MAXLINE 1000
void detab_line(char from[], char to[]);

main() 
{
	char from[MAXLINE];
	char to[MAXLINE];
	int i, c;
	while( i != MAXLINE && (c = getchar()) != EOF) {
		from[i] = c;
		++i;		
	}
	detab_line(from, to);
}

void detab_line(char from[], char to[]) {
	int i,j,m,n;	
	for(i=0; from[i] != '\0'; ++i) {
		to[n] = from[m];
		if(from[i] = '\t') {
			for(j=0; j<4; ++j) {
				to[n] = ' ';
				++n;
			}
			++m;
			++n;
		}
	}
	for(i=0; to[i] != '\0'; ++i) {
		putchar(to[i]);
	}
}
