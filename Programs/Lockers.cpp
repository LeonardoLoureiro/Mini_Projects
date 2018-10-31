#include <iostream>
#include <map>

int main() {
	std::map <int, std::string> Lockers ;

	int N_OF_LOCKERS = 100 ; 

	// This creates the dict. of lockers 
	// +1 N_OF_LOCKERS since numbering starts at 1 and would leave 99 lockers.
	int i ;
	for ( i = 1 ; i < N_OF_LOCKERS+1 ; ++i ) {
		Lockers[i] = "closed" ;
	} ;

	// This loop is supposed to continue for 100 times, meanwhile the 
	// 'for' nested in the 'while' loop is to iterate however many times
	// it needs, each time with a step being the number of rounds the 
	// 'while' loop has done, each iteration closing or opening the lockers. 
	int rounds = 0 ;
	while(1) {
		++rounds ;
		
		if (rounds == N_OF_LOCKERS+1) break ;

		for ( i = rounds ; i < N_OF_LOCKERS+1 ; i += rounds ) {
			if (	Lockers[i] == std::string("open") ) {
				Lockers[i] = std::string("closed") ; 
			} else if ( 	Lockers[i] == std::string("closed") ) {
					Lockers[i] = std::string("open") ;
			} ;
		} ;
	} ;

	// This automatically iterate through all keys in dict. using
	// 'locker' to refer to each key.
	// 'first' refers to the key, and 'second' to the value. 
	for ( auto& locker : Lockers ) {
		if ( locker.second == "open" ) {
			std::cout << "Locker #" << locker.first ;
			std::cout << " is " << locker.second << std::endl ;
		} ;
	} ; 

	return 0 ;
} ;
