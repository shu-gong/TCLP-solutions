#include<stdio.h>
/* count lines in input */
main()
{
	int c, nblank;
	prev = 0;
	while ((c = getchar()) != EOF)
		if (c == ' ') {
			prev = c;
			c = getchar();
			if (prev == c) {
				;
			} 
			else putchar(c);
		} else putchar(c);
	printf("%d\n", nblank);
}
