/* This program just counts the total amount of vowels within a sentence/paragraph and returns
 * the total number of each as well as percentage.
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

char count_vowels	( char *dir ) ;
char make_lower		( char letter ) ;
bool isvowel			( char letter ) ;
void process_line	( char line[256] ) ;
void display_freq	() ;

typedef struct
{
	char vowel ;
	int freq ;
} Vowel ;

Vowel freq_table[] = {
	{'a', 0}, {'e', 0},
	{'i', 0}, {'o', 0},
	{'u', 0}
} ;

int main( int argc, char *argv[] )
{
	char *dir = argv[1] ;

	if ( dir == NULL )
	{
		printf("Please enter file dir. \n") ;
		return 0 ;
	} ;

	count_vowels( dir ) ;

	display_freq() ;

	return 0 ;
} ;

// function to get each line of file individually and then pass it onto function
// 'process_line' for chars to be 'counted'...
char count_vowels( char *dir )
{
	printf("Checking file %s... \n", dir) ;
	char line[256], letter ;
	FILE *f_ptr = fopen(dir, "r") ;
	int size = sizeof(line) ;

	while (fgets( line, size, f_ptr ))
	{
		process_line( line ) ;
	} ;

	fclose(f_ptr) ;
} ;

// this function is to iterate over each char in the line, then, if char is vowel,
// it will iterate over table of structs (freq_table) and then add accordingly...
void process_line( char line[256] )
{
	int i, j, len = strlen(line);
	char letter, vowel ;

	for( i = 0 ; i < len ; ++i )
	{
		letter = line[i] ;
		letter = make_lower( letter ) ;

		if ( !isvowel( letter ) )
		{
			continue ;
		} ;

		for ( j = 0 ; j < 5 ; ++j )
		{
			if ( freq_table[j].vowel == letter )
			{
				freq_table[j].freq += 1 ;
				break ;
			} ;
		} ;
	} ;
} ;

bool isvowel( char letter )
{
	letter = tolower(letter) ;

	return ( letter == 'a' || letter == 'e' ||
	      	 letter == 'i' || letter == 'o' || letter == 'u' ) ;
} ;

char make_lower( char letter )
{
	return tolower(letter) ;
} ;

void display_freq()
{
	int i ;

	for ( i = 0 ; i < 5 ; ++i )
	{
		printf("> %c : %d \n", 	freq_table[i].vowel,
														freq_table[i].freq) ;
	} ;
} ;
