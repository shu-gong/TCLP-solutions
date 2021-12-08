#include<stdio.h>
/* Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter?*/
#define MAXNTAB 4
#define MAXLINE 1000
int get_line(char from[], char to[]);

main() 
{
	char from[MAXLINE];
	char to[MAXLINE];
	int c;
	while((c = getchar()) != EOF) {
		get_line(from, to);
	}

}

int get_line(char from[], char to[]) {
	int i;	
	for(i=0; from[i] != '\0'; ++i) {
		if(from[i] = '\t') {
				
		}
	}

}
