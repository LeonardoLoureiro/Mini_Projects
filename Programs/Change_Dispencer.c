/* This file just calculates how much change should be given for a certain
 * amount. Example:
 * 		£2.54:
 *			£2 x 1
 *			50p x 1
 *			2p x 2
 *
 * Notes: £50, £20, £10
 * Coins: £2, £1, 50p, 20p, 10p, 5p, 2p, 1p
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NUMB_OF_CHANGE_AVAILABLE 12

int diff_change[NUMB_OF_CHANGE_AVAILABLE] = {
	5000, 2000, 1000, 500,
	200, 100, 50, 20,
	10, 5, 2, 1} ;
	// ^best to work with ints to avoid problems using ints AND floats

void calc_change_needed(float total_amount) ;
int change_2_int(float num) ;
float int_2_change(int num) ;

int main(int argc, char const *argv[]) {
	float total_amount ;

	if (argv[1] == NULL)
	{
		printf("Please put number as first argument. Example:\n") ;
		printf("> ./change_dinspencer 5.55\n") ;
		return 0 ;
	} ;

	sscanf(argv[1], "%f", &total_amount) ;
	printf("Total Amount: £%.2f\n", total_amount) ;
	printf("Change:\n") ;
	calc_change_needed(total_amount) ;

	return 0;
} ;

/* The loop iterates all over the possible change amount you can give
 * in coins/notes. Then it takes away from the change still left and
 * keeps going until it iterates over all coin/note values. If the coin/notes
 * doesn't go into the change, then it just skips instead of displaying "£1 x 0"
 */
void calc_change_needed(float total_amount)
{
	int i, remaining_amount ;
	int buffer_amount, multiples_needed ;

	remaining_amount = change_2_int(total_amount) ;
	for (i = 0 ; i < NUMB_OF_CHANGE_AVAILABLE ; ++i)
	{
		multiples_needed = remaining_amount / diff_change[i] ;
		if (multiples_needed == 0) continue ;
		remaining_amount = remaining_amount - (diff_change[i] * multiples_needed) ;

		printf("  £%.2f x %d\n", int_2_change(diff_change[i]), multiples_needed ) ;
	} ;
} ;

int change_2_int(float num)
{
	num *= 100 ;
	return (int)num ;
} ;

float int_2_change(int num)
{
	float buffer ;
	buffer = (float) num ;
	return (buffer/100) ;
} ;
