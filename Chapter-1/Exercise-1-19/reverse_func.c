#include<stdio.h>
/* Write a function reverse(s) that reverses the character string s. Use it to write a program that reverse its input a line at a time.*/ #define MAXLEN 1000
void reverse(char from[], char to[]);
main() {
	int c;

	while((c = getchar()) != EOF){
	char line[MAXLEN];
	char reverse_line[MAXLEN];

	reverse(line, reverse_line);
	} }

void reverse(char from[], char to[]){

	int i, j;
	j = 0;

	for (i = 0; from[i] != '\0'; i++);

	while (i != 0)	{
		from[i] = to[j];
		++j;
		--i;
	}

	to[i] = '\0';
	i = 0;	
	while(to[i] != '\0'){
		putchar(to[i]);
		++i;
	}
}

void read_line()
