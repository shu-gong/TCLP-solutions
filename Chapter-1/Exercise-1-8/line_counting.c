#include <stdio.h>
/* count lines in input */

main() {
	int c, nblanks, ntabs, nl;
	nl = nblanks = ntabs = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n')
			++nl;
		if (c == '\t')
			++ntabs;
		if (c == ' ')
			++nblanks;
	}
	printf("Blanks: %d\n", nblanks);
	printf("Tabs: %d\n", ntabs);
	printf("Newlines: %d\n", nl);
}
