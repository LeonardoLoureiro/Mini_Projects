/* A simple program that displays the timestable row by row,
 * also allowing user to set the boundaries, e.g. 12x12 etc. 
 */

#include "stdio.h"

int main() {
	int num ;

	printf("Please enter the limits for table:\n> ") ;
	scanf("%d", &num) ;

	for ( int i=1 ; i<=num ; ++i ) {

		for (int j=1 ; j<=num ; ++j ) {
			printf("|  %d\t|", ( j*i ) ) ;
		} ;
		
		printf("\n") ;
	} ;

	return 0 ;
} ;
