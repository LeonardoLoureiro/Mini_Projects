/* A self dividing number is a number which is divisible by its own digits. Example:
 * 	128:
 * 	  128 % 1 = 0
 * 	  128 % 2 = 0
 * 	  128 % 8 = 0
 *
 * There should be an upper and lower bound and the program should find all possible
 * self-diving numbers within that range.
 */
#include <iostream>
#include <string>

unsigned int char2int( char letter ) ;
void show_numbs( int sd_num[], int arr_size ) ;
bool is_self_div( int number ) ;

int main() {
	int lower_b, upper_b ;

	std::cout << "Lower bound: " ;
	std::cin >> lower_b ;

	std::cout << "Upper bound: " ;
	std::cin >> upper_b ;
	
	int i, j=0, sd_nums[100] ;
	for ( i=lower_b ; i<=upper_b ; ++i ) {
		if ( is_self_div( i ) ) {
			sd_nums[j] = i ; ++j ;
		} ;
	} ;

	show_numbs( sd_nums, j ) ;

	return 0 ;
} ;

bool is_self_div( int number ) {
	std::string s_number = std::to_string( number ) ;
	s_number.c_str() ;

	int i, current_digit, num_len=s_number.size() ;

	for ( i=0 ; i<num_len ; ++i ) {
		current_digit = char2int( s_number[i] ) ;

		if ( ( current_digit == 0 ) or /* can't divide by 0... */
		   ( ( number % current_digit) != 0 ) ) return 0 ;
	} ;

	return 1 ;
} ;

void show_numbs( int sd_nums[], int arr_size ) {
	int i ;

	std::cout << "The numbers are: " ;
	for ( i=0 ; i<arr_size-1 ; ++i ) {
		std::cout << sd_nums[i] << ", " ;
	} ;

	std::cout << sd_nums[i] << std::endl ;
} ;

unsigned int char2int( char letter ) {
	return ( (int) letter ) - 48 ;
} ;
