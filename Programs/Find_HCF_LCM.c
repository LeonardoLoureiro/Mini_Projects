#include <stdio.h>
int main() {
	int a, b, num1, num2, t, hcf, lcm ;
 
	printf("Enter two integers seperated by space:\n> ") ;
	scanf("%d%d", &num1, &num2) ;

	a = num1 ;
	b = num2 ;

	while (b != 0) {
		t = b ;
		b = a % b ;
		a = t ;
	} ;

	hcf = a ;
	lcm = (num1*num2) / hcf ;

	printf("Highest commone factor of %d and %d = %d\n", num1, num2, hcf) ;
	printf("Lowest common multiple of %d and %d = %d\n", num1, num2, lcm) ;

	return 0 ;
}
