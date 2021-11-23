#include <stdio.h>
#define IN 1
#define OUT 0
#define MAXC 10
/* count digits, white space, others */
main()
{
	int c, i, state, n;
	n = 0;
	int nc[MAXC];
	for (i = 0; i < MAXC; ++i)
		nc[i] = 0;
	while ((c = getchar()) != EOF){
		if (c ==' ' || c == '\n' || c == '\t')	{
			state = OUT;
			nc[n-1] += 1;
			n = 0;
		} 
		else {
			state = IN;
			n += 1;
		}
	}
	for (i =0; i< MAXC; ++i){
		printf("%d",nc[i]);
	}
}			
