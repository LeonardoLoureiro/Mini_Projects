#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void num_2_str( char *nums ) ;
void str_2_num( char *str ) ;
void append( char *str, char letter ) ;

int main( void )
{
	int choice ;
	char *str, *info ;

	printf("Choices:\n") ;
	printf("1) #FFFFFFF -> 255,255,255\n") ;
	printf("2) 255,255,255 -> #FFFFFFF\n>> ") ;
	scanf("%d", &choice ) ;

	getchar() ;

	// if choice is #2, then remind user to use commas (obvs)
	info = ( choice == 2 ) ? "(use commas to separate the numbers)" : "" ;
	printf("\nEnter input: %s\n>> ", info ) ;
	scanf("%s", str ) ;

	switch ( choice )
	{
		case 1: str_2_num( str ) ; break ;
		case 2: num_2_str( str ) ; break ;

		default: printf("Invalid choice\n") ;
	} ;

	return 0;
} ;

void str_2_num( char *str )
{
	if ( str[0] == '#' ) ++str ;

	char *cp = str, *pEnd ;
	char buff_3, buff_6[4] = "" ;
	char buff_c ;
	long int buff_i ;

	// e.g. #FFF
	if ( strlen( str ) == 3 )
	{
		printf(">> ") ;

		for ( ; *cp != '\0' ; ++cp )
		{
			buff_3 = *cp ;
			buff_i = strtol( &buff_3, &pEnd, 16 ) ;
			buff_i = buff_i * buff_i ;

			printf("%ld ", buff_i ) ;
		} ;

		printf("\n") ;
	} ;

	// e.g. #FAFAFA
	if ( strlen( str ) == 6 )
	{
		printf(">> ") ;

		for ( ; *cp != '\0' ; ++cp )
		{
			buff_c = *cp ;
			append( buff_6, buff_c ) ; ++cp ;
			buff_c = *cp ;
			append( buff_6, buff_c ) ;
			buff_i = strtol( buff_6, &pEnd, 16 ) ;

			printf("%ld ", buff_i ) ;
			buff_6[0] = 0 ;
		} ;

		printf("\n") ;
	} ;
} ;

void num_2_str( char *str )
{
	int nums[3] ;

	sscanf( str, "%d,%d,%d", &nums[0], &nums[1], &nums[2] ) ;

	if ( nums[0] > 255 || nums[1] > 255 || nums[2] > 255 )
	{
		printf("Numbers too large, try again\n") ;
		return ;
	} ;

	printf(">> #%X%X%X\n", 	nums[0],
													nums[1],
													nums[2]);

} ;

void append( char *str, char letter )
{
  int len = strlen( str ) ;
  str[len] = letter ;
  str[len+1] = '\0' ;
} ;
