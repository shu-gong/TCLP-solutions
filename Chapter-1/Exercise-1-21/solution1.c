#include<stdio.h>
#define TAB 4
main() {
	int c, i = 0, j;
	while((c=getchar()) != EOF) {
		if(c == ' ') {
			++i;
			if((i % TAB) == 0) {
				putchar('\t');
			}
		}
		else {
			for(j=0; j<(i%TAB); ++j) {
				putchar(' ');
			}
			putchar(c);
			if(i != 0) {
				i = 0;
			}
		}
	}
}
