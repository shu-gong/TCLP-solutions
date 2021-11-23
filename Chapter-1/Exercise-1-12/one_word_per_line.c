#include<stdio.h>
/* Write a program that prints its input one word per line.*/
#define IN 1
#define OUT 0
main() {
	int c, state;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
			putchar('\n');
		}
		else {
			state = IN;
			putchar(c);
		}
	}

}
