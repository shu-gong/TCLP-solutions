#include <stdio.h>
/* copy input to output; 2nd version  */

main() {
	int c;
	int num_of_eof;
	while (num_of_eof = (c = getchar()) != EOF ){
		printf("%d",num_of_eof);
		putchar(c);
	}	
	printf("%d",num_of_eof);
}
