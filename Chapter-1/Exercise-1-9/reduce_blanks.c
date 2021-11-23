#include<stdio.h>
/* count lines in input */
main()
{
	int c, prev;
	prev = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			if (prev == c) {
				;	
			} 
			else {
				putchar(c);
			}
		} 
		else {
			putchar(c);
		}
		prev = c;
	}
}
