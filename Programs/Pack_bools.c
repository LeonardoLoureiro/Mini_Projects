/* This program 'tackles' the problem where 800 bytes' worth of bool values
 * and condense it down to 100 bytes worth.
 */

// make sure 'SIZE' is divisible 32 otherwise the last bits will be skipped...

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 800 // total number of bools you want to use...
#define ARR_SIZE SIZE/32

void create_states() ;
void show_bools() ;
void show_nums() ;

// now create arrays to store bool and int values
bool BOOLS[SIZE] ;
int NUMS[ARR_SIZE] ;

int main()
{
    int chunk, bit_pos, arr_n = 0 ;
    unsigned int buffer ;

    printf("Memory used up by BOOLS\t-> %ld bytes.\n", sizeof(BOOLS) ) ;
    create_states() ;
    //show_bools() ; //remove if you want...

    chunk = 0 ;
    while( chunk < SIZE )
    {
        buffer = 0 ;

        for( bit_pos = chunk ; bit_pos < chunk+32 ; ++bit_pos )
        {
            buffer += BOOLS[bit_pos] ;
            buffer = buffer << 1 ;
        } ;

        chunk += 32 ;
        buffer += BOOLS[chunk] ;

        NUMS[arr_n] = buffer ;
        ++arr_n ;
    } ;

    printf("Memory used up by NUMS \t-> %ld bytes.\n", sizeof(NUMS) ) ;
    //show_nums() ; //remove if you want...

    return 0;
} ;

// this func creates the instances in the BOOLS array and sets their bool
// values as well as their 'id'. (so you have something to use as example)
void create_states()
{
    int i ;
    srand(time(NULL)) ;
    for ( i = 1 ; i <= SIZE ; ++i )
    {
        BOOLS[i] = (rand() % 2) ;
    } ;
} ;

// To show all bool states and numbers so to have something to compare
// beginning to end result
void show_bools()
{
    printf("======= BOOLS struct array =======\n") ;

    for ( int i = 1 ; i <= SIZE ; ++i )
    {
        printf("%d", BOOLS[i] ) ;
        if ( (i % 32) == 0 ) printf("\n") ;
    } ;

    printf("==================================\n") ;
} ;

void show_nums()
{
    int arr_n ;
    printf("====== int array converted =======\n") ;
    for (arr_n = 0 ; arr_n < ARR_SIZE ; ++arr_n)
    {
        printf("-> arr[%d] = %u -> %X\n", arr_n, NUMS[arr_n], NUMS[arr_n] );
    } ;
    printf("==================================\n") ;
} ;
