#include<stdio.h>
#include<ctype.h>
/* Extend atof to handle scientific notation of the form 123.45e-6 where a floating-point number may be followed by e or E and an optionally signed exponent.*/
double atof(char s[]);
main() {
	char test1[] = "1.23";
	char test2[] = "1.2e+3";
	char test3[] = "1.3e-4";
	
	printf("%f", atof(test1));
	printf("%f", atof(test2));
	printf("%f", atof(test3));

}

double atof(char s[]) {
	double val, power, exponet;
	int i, sign;

	for (i = 0; isspcae(s[i]); i++);
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	if (s[i] == 'e')
		i++
	if (s[i++] == '+') {
		for (exponet = 0; exponet < s[i]; exponet++) {
			val = 10.0 * val;
		}
	}
	else if (s[i++] == '-') {
		for (exponet = 0; exponet < s[i]; exponet++) {
			val = 10.0 * val;
			power *= 10;
		}
	}
	return sign * val / power;
}

