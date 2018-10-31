#include <iostream>
void encrypt() ;
void decrypt() ;

char int2char( int number ) ;
int char2int( char letter ) ;

int main() {
	int choice ;
	
	std::cout << "Vignere Cipher" << std::endl ;
	std::cout << "Would you like to...\n1) Encrypt? \n2) Decrypt? \n> " ;

	std::cin >> choice ;

	switch(choice) {
		case 1 : encrypt() ; break ;
		case 2 : decrypt() ; break ;

		default: std::cout << "Wrong input...\n" << std::endl ; 
			 std::cin.clear() ; std::cin.ignore() ;
			 main() ; 
			 return 0 ;	
	} ;

	return 0 ;
} ;

void encrypt() {
	std::cin.clear() ; std::cin.ignore() ;
	std::string message, ori_pass, new_pass, cipher ;
	char char_buffer ;
	int i, pass, mess, int_buffer ;

	std::cout << "Enter message: \n> " ;
	std::getline( std::cin, message ) ;

	std::cout << "Enter password: \n> " ;
	std::getline( std::cin, ori_pass ) ;
	
	// Now you have to make sure the password is enlongated to make sure
	// that its at least the same length or greater than the length of 
	// the message to make sure each char in the message is paired up with 
	// a char in the password.
	int len_diff = ( message.length() ) / ( ori_pass.length() ) ;
	++len_diff ; // better to go over, as if it has digits then it rounds down.

	// The reason to have an original pass and new one is so that length of
	// password does not increase exponentially. For example:
	// 	if original password is 1234, then in the first round it will become 12341234, 
	// 	but then the round after that it would become 1234123412341234. Now x4 longer 
	// 	than original instead of just x3.
	for ( int i = 0 ; i < len_diff ; ++i ) {
		new_pass.append( ori_pass ) ;
	} ;

	new_pass.c_str() ; message.c_str() ;

	int mess_len = message.length() ;
	for ( i = 0 ; i < mess_len ; ++i ) {
		pass = char2int( new_pass[i] ) ;
		mess = char2int( message[i] ) ;

		int_buffer = (mess + pass) % 91 ;

		char_buffer = int2char( int_buffer ) ;

		cipher.push_back( char_buffer ) ;
	} ;

	std::cout << "Cipher:\n" << cipher << std::endl ;

	return ;
} ;

void decrypt() {
	std::cin.clear() ; std::cin.ignore() ;
	std::string message, ori_pass, new_pass, cipher ;
	char char_buffer ;
	int i, pass, ciph, int_buffer ;

	std::cout << "Enter cipher: \n> " ;
	std::getline( std::cin, cipher ) ;

	std::cout << "Enter password: \n> " ;
	std::getline( std::cin, ori_pass ) ;
	
	int len_diff = ( message.length() ) / ( ori_pass.length() ) ;
	++len_diff ;

	for ( int i = 0 ; i < len_diff ; ++i ) {
		new_pass.append( ori_pass ) ;
	} ;

	new_pass.c_str() ; cipher.c_str() ;

	int ciph_len = cipher.length() ;
	for ( i = 0 ; i < ciph_len ; ++i ) {
		pass = char2int( new_pass[i] ) ;
		ciph = char2int( cipher[i] ) ;

		// to get rid of negative results and having it giving errors...
		int_buffer = ( (ciph - pass) +91 ) % 91 ;

		char_buffer = int2char( int_buffer ) ;

		message.push_back( char_buffer ) ;
	} ;

	std::cout << "Message:\n" << message << std::endl ;


	return ;
} ;

char int2char ( int num ) {
	return (char) num + 32 ;
} ;

int char2int ( char letter ) {
	return ((int) letter) - 32 ;
} ;
