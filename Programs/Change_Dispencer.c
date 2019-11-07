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

#define NUMB_OF_CHANGE_AVAILABLE 12

float diff_change[NUMB_OF_CHANGE_AVAILABLE] = {
	50, 20, 10, 5,
	2, 1, 0.5, 0.2,
	0.1, 0.05, 0.02, 0.01} ;

void calc_amount_needed(float total_amount) ;

int main(int argc, char const *argv[]) {
	float total_amount ;

	if (argv[1] == NULL)
	{
		printf("Please put number as first argument. Example:\n") ;
		printf("> ./change_dinspencer 5.55\n") ;
		return 0 ;
	} ;

	sscanf(argv[1], "%f", &total_amount) ;
	printf("Change number given: £%.2f\n", total_amount) ;
	calc_amount_needed(total_amount) ;

	return 0;
} ;

/* The loop iterates all over the possible change amount you can give
 * in coins/notes. Then it takes away from the change still left and
 * keeps going until it iterates over all coin/note values. If the coin/notes
 * doesn't go into the change, then it just skips instead of displaying "£1 x 0"
 */
void calc_amount_needed(float total_amount)
{
	int i, buffer_amount ;
	float amount_left = total_amount ;

	for (i = 0 ; i < NUMB_OF_CHANGE_AVAILABLE ; ++i)
	{
		buffer_amount = amount_left / diff_change[i] ;
		amount_left = amount_left - (diff_change[i] * buffer_amount) ;

		if (buffer_amount == 0.0) continue ;

		printf("£%.2f x %d\n", diff_change[i], buffer_amount) ;
	} ;

	if (amount_left == 0.01) printf("£0.01 x 1\n") ;
	// ^solves the fact that the last item (0.01) is skipped in last loop and
	// so it doesn't show last 1p...
} ;
