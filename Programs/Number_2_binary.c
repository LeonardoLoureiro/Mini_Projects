/* Converting numbers to binary. Limits between 0 and 4,294,967,295. */

#include <stdio.h>

int main()
{
  unsigned int num ;
  int shift, check_bit ;
  printf("Enter number to convert to Binary:\n>> ") ;
  scanf("%u", &num) ;

  for (shift = 31 ; shift >= 0 ; --shift)
  {
    check_bit = num >> shift;
    printf("%d", ( (check_bit&1) ? 1 : 0 ) );
  } ;
  printf("\n") ;

  return 0;
} ;
