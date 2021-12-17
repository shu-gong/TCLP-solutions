#include<stdio.h>

main() {
	int x = 5;
	switch( x ) {
		case 5:
			printf( "x is five!\n" );
		case 2:
			printf( "x is two!\n" );
			break;
		default:
			printf( "I don't know about x\n" );
	}
}
