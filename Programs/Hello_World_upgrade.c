/* Code to display an upgraded version of the beginner code "Hello World".
 * It will show this:
 *
 *  C       C   CCCCCCCCC   C           C           CCCCCCCCC
 *  C       C   C           C           C           C       C
 *  C       C   C           C           C           C       C
 *  CCCCCCCCC   CCCCCCCCC   C           C           C       C
 *  C       C   C           C           C           C       C
 *  C       C   C           C           C           C       C
 *  C       C   CCCCCCCCC   CCCCCCCCCC  CCCCCCCCCC  CCCCCCCCC
 *
 *
 *  C       C   CCCCCCCCC   CCCCCCCCCC  C           CCCCCC
 *  C       C   C       C   C        C  C           C      C
 *  C       C   C       C   C        C  C           C       C
 *  C   C   C   C       C   CCCCCCCCCC  C           C       C
 *  C  C C  C   C       C   C    C      C           C       C
 *  C C   C C   C       C   C      C    C           C      C
 *  CC     CC   CCCCCCCCC   C        C  CCCCCCCCCC  CCCCCC
 *
 */

#include <stdio.h>

void H( int line_n ) ;
void E( int line_n ) ;
void L( int line_n ) ;
void O( int line_n ) ;
void W( int line_n ) ;
void R( int line_n ) ;
void D( int line_n ) ;

int main(int argc, char const *argv[])
{
	printf("Hello world!\n") ;
	printf("============\n") ;
	int line_n ;

	// for the first word: HELLO
	for ( line_n = 1 ; line_n <= 7 ; ++line_n )
	{
		H( line_n ) ;
		E( line_n ) ;
		L( line_n ) ;
		L( line_n ) ;
		O( line_n ) ;

		printf("\n") ;
	} ;

	printf("\n") ;

	// for the second word: WORLD
	for ( line_n = 1 ; line_n <= 7 ; ++line_n )
	{
		W( line_n ) ;
		O( line_n ) ;
		R( line_n ) ;
		L( line_n ) ;
		D( line_n ) ;

		printf("\n") ;
	} ;

	return 0 ;
} ;

void H( int line_n )
{
	switch ( line_n )
	{
		case 1: case 2: case 3:
		case 5: case 6:
		case 7: printf("C       C   ") ; return ;

		case 4: printf("CCCCCCCCC   ") ; return ;
	} ;
} ;

void E( int line_n )
{
	switch ( line_n )
	{
		case 2: case 3: case 5:
		case 6: printf("C           ") ; return ;

		case 1: case 4:
		case 7: printf("CCCCCCCCC   ") ; return ;
	} ;
} ;

void L( int line_n )
{
	switch ( line_n )
	{
		case 1: case 2: case 3:
		case 4: case 5:
		case 6: printf("C           ") ; return ;

		case 7: printf("CCCCCCCCC   ") ; return ;
	} ;
} ;

void O( int line_n )
{
	switch ( line_n )
	{
		case 2: case 3:
		case 4: case 5:
		case 6: printf("C       C   ") ; return ;

		case 1:
		case 7: printf("CCCCCCCCC   ") ; return ;
	} ;
} ;

void W( int line_n )
{
	switch ( line_n )
	{
		case 1: case 2:
		case 3: printf("C       C   ") ; return ;
		case 4: printf("C   C   C   ") ; return ;
		case 5: printf("C  C C  C   ") ; return ;
		case 6: printf("C C   C C   ") ; return ;
		case 7: printf("CC     CC   ") ; return ;
	} ;
} ;

void R( int line_n )
{
	switch ( line_n )
	{
		case 2: case 3:
		case 7: printf("C       C   ") ; return ;
		case 1:
		case 4: printf("CCCCCCCCC   ") ; return ;
		case 5: printf("C    C      ") ; return ;
		case 6: printf("C      C    ") ; return ;
	} ;
} ;

void D( int line_n )
{
	switch ( line_n )
	{
		case 1:
		case 7: printf("CCCCCC      ") ; return ;
		case 2:
		case 6: printf("C      C    ") ; return ;

		case 3: case 4:
		case 5: printf("C       C   ") ; return ;
	} ;
} ;
