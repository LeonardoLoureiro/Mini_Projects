/* This program will randomly choose a letter and have the user guess it, then it will say 
 * whether the letter comes before, after the letter provided until either user runs out of
 * turns left or guesses correctly.
 */
#include <iostream>
#include <string>

char ran_char() ;
void game_start() ;
void game_end() ;
unsigned int get_index(char letter) ;
const std::string alpha = "abcdefghijklmnopqrstuvwxyz" ;

int main() {
	alpha.c_str() ;
	std::srand( time( NULL ) ) ;

	bool state = true ;
	char pc_letter, user_letter, play_again ;
	int turns, guesses, tries ;
	do {
		turns = 0 ;
		guesses = 7 ;

		pc_letter = ran_char() ;
		game_start() ;

		while( 1 ) {
			tries = guesses - turns ;
			std::cout << "You have " << tries ;
			std::cout << " tries left." << std::endl ;

			std::cout << "Enter letter:\n> " ;
			std::cin >> user_letter ;
			
			++turns ;
			if ( turns == 7 ) break ;
			
			if ( user_letter == pc_letter ) {
				std::cout << "\nCongratulations! You've guessed correctly in " ; 
				std::cout << turns << " turns!" << std::endl ;
				break ;
			} ;

			if ( get_index(user_letter) > get_index(pc_letter) ) {
				std::cout << "The letter comes before " ;
				std::cout << user_letter << "\n" << std::endl ;
			
			} else if ( get_index(user_letter) < get_index(pc_letter) ) {
				std::cout << "The letter comes after " ;
				std::cout << user_letter << "\n" << std::endl ;
			} ;
		} ;

		if (turns == guesses) std::cout << "\nI was thinking of " << pc_letter << std::endl ;

		game_end() ;
		std::cin >> play_again ;

		if ( play_again == 'n' ) state = false ;

	} while( state ) ;


	return 0 ;
} ;

void game_end() {
	std::cout << "\n======================== " ;
	std::cout << " GAME OVER " ;
	std::cout << "========================\n" ;
	std::cout << "Would you like to play again?\n> " ;
} ;

void game_start() {
	std::cout << "\n========================= " ;
	std::cout << " WELCOME " ;
	std::cout << "=========================\n" ;
	std::cout << "I'm thinking of a letter... \n" ;
	std::cout << "Guess what that letter is! \t(please enter in lower case)" << std::endl ;
} ;

unsigned int get_index(char letter) {
	int index, i, len ;
	len = alpha.size() ;

	for( i=0 ; i<len ; ++i ) {
		if (alpha[i] == letter) return i ;
	} ;
} ;

char ran_char() {
	unsigned int index ;
	index = rand() % alpha.size() ;
	char letter = alpha[index] ;

	return letter ;
} ;
