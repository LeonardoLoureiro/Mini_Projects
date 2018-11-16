/* Just a simple program to check if a number is prime or not. 
 */

#include <stdio.h>
#include <stdbool.h>
bool isPrime( int number ) ;

int main() {
	int user_n ;
	
	printf("Enter number to check if its a prime or not. \n> ") ;
	scanf("%d", &user_n) ;

	printf( "Number %d is %s. \n", user_n, ( isPrime(user_n) ? "a prime" : "not a prime" ) ) ;

	return 0 ;
} ;

bool isPrime( int number ) {
	int k=5 ;
	
	if ( number <= 1 ) return false ;
	else if ( number <= 3 ) return true ;
	
	if ( ((number % 2) == 0) || ((number % 3) == 0) ) return false ;

	for ( k = 5 ; k*k <= number ; k += 2 ) {
		if ( (number%k) == 0 ) return false ;
	} ;
	

	return true ;
} ;
