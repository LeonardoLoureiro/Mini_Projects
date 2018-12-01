/* The FizzBuzz program is a program that displays numbers from 1 to 100, and for multiples of 3
 * only "Fizz" is displayed and for multiples of 5 it displays "Buzz". If the number is a multiple
 * of 3 and 5, then it shows "FizzBuzz". 
 */

#include <stdio.h>
#include <string.h>

int main() {
	int limit = 100, num ;
	char fb[20] ;
	
	for ( num=1 ; num<=limit ; ++num ) {
		fb[0] = 0 ;
		
		if ( num % 3 == 0 ) strcat( fb, "Fizz" ) ;
		if ( num % 5 == 0 ) strcat( fb, "Buzz" ) ;
		if ( fb[0] == 0 ) continue ; 	// otherwise get empty lines...

		printf("%s\n", fb) ;
	} ;
} ;
