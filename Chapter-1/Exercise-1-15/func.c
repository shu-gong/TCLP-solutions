#include<stdio.h>
/* Rewrite the temperature conversion program of Section 1.2 to use a function for conversion. */
int temp_conver(int f);
main() {
	int f, c;
	int lower, upper, step;
	lower = 0;
	upper = 300;
	step = 20;

	f = lower;
	while (f <= upper) {
		c = temp_conver(f);
		printf("%d\t%d\n", f, c);
		f = f + step ;
	}

	
}

int temp_conver(int f){
	int c;
	c = 5 * (f - 32) / 9;
	return c;
}
