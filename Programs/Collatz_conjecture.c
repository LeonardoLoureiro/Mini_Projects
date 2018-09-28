/*  The Collatz Conjecture states that you start with any positive integer and if
 *  it is even, you halve the number, if it is odd then you multiply it by 3 and add one.
 *  You keep doing it until it reaches to 1, or at least when a pattern of 8, 4,
 *  2 and 1 emerge. All known numbers, so far, have been found to eventually follow this pattern.
 */

#include <stdio.h>
int main() {
	int num, steps = 0, x ;
	printf("Enter an integer which is positive and > 1:\n>> ") ; scanf("%d",&num) ;
	x = num ;

	while(1) {
		printf("%d ", x) ;

		if ( ( x % 2 ) == 0 ) x /= 2 ;
		else if ( ( x % 2 ) != 0 ) x = ( x*3 ) + 1 ; 

		++steps ;
		
		if ( x==1 ) { printf("1") ; break ; } ;
	} ;

	printf("\n \nFrom the number %d, it took %d steps to reach 1. \n", num, steps) ;

	return 0;
}
