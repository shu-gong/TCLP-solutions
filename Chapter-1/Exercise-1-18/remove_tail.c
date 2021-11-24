#include <stdio.h>
#define MAXLINE 1000   /* maximum input line length */
#define IN 1
#define OUT 0
/* Write a program to remove trailing blanks and tabs from each line of input and to delete entirely blank lines*/
main()
{
	int c, nb, state, i, prev;
	state = OUT;
	nb = 0;
	prev = 0;
	while ((c = getchar()) != EOF) {
		if (c != ' ' && c != '\t' && c != '\n') {
			for (i = 0; i < nb; ++i){
				putchar(' ');
			}
			putchar(c);
			prev = c;
			nb = 0;
		}
		else{
			if (c == '\n'){
				if(prev == '\n')
					;
				else putchar(c);
			}
			else if (c == '\t')
				nb += 4;
			else if (c == ' ')
				nb ++;
		}
	}
}
