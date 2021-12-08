#include<stdio.h>

#define CHARS 4

main(void) {
	int i, c;
	while((c=getchar()) != EOF) {
		if(c == '\t') {
			for(i=0; i<CHARS; ++i) {
				putchar(' ');
			}
		}
		else {
			putchar(c);
		}
	}
}
