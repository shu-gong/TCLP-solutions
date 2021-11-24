#include<stdio.h>
main(){
	int c;
	while((c = getchar()) != EOF){
		if (c!='\n')
			putchar(c);
		else
			;
	}
}
