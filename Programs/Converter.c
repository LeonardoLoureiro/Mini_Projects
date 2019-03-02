/* A simple temp converter...
 * 	C -> F
 * 	F -> C
 * 	K -> F
 *  F -> K
 *  K -> C
 * 	C -> K
 */

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

struct option long_opt[] = {
	{"c2f", required_argument, NULL, 'a'},
	{"f2c", required_argument, NULL, 'b'},
	{"k2c", required_argument, NULL, 'c'},
	{"c2k", required_argument, NULL, 'd'},
	{"k2f", required_argument, NULL, 'e'},
	{"f2k", required_argument, NULL, 'f'},

	{"help", no_argument, NULL, 'h'},
	{NULL, 0, NULL, 0}
} ;

float cel2fah( float cel ) ;
float fah2cel( float fah ) ;
float kel2cel( float kel ) ;
float cel2kel( float cel ) ;
float kel2fah( float kel ) ;
float fah2kel( float cel ) ;

int main(int argc, char *argv[])
{
	int c ;

	while ( (c = getopt_long(argc, argv, "abcdef:h", long_opt, NULL)) != -1 )
	{
		switch(c)
		{
			case 'a':
				printf("%s C -> %.2f F\n", optarg, cel2fah( atof(optarg) ) ) ;
				break ;

			case 'b':
				printf("%s F -> %.2f C\n", optarg, fah2cel( atof(optarg) ) ) ;
				break ;

			case 'c':
				printf("%s K -> %.2f C\n", optarg, kel2cel( atof(optarg) ) ) ;
				break ;

			case 'd':
				printf("%s C -> %.2f K\n", optarg, cel2kel( atof(optarg) ) ) ;
				break ;

			case 'e':
				printf("%s K -> %.2f F\n", optarg, kel2fah( atof(optarg) ) ) ;
				break ;

			case 'f':
				printf("%s F -> %.2f K\n", optarg, fah2kel( atof(optarg) ) ) ;
				break ;


			case ':': case '?':
				fprintf(stderr, "Try `%s --help' for more information.\n", argv[0]);
				return(-2);

			case 'h':
				printf("Usage: %s --[OPTIONS] [ARGUMENTS] ...\n", argv[0]);
				printf("  --c2f		 Celsius -> Fahrenheit\n") ;
				printf("  --f2c		 Fahrenheit -> Celsius\n") ;
				printf("  --k2c		 Kelvin -> Celsius\n") ;
				printf("  --c2k		 Celsius -> Kelvin\n") ;
				printf("  --k2f		 Kelvin -> Fahrenheit\n") ;
				printf("  --f2k		 Fahrenheit -> Kelvin\n") ;

				printf("  --help		print this help and exit\n");
				printf("\n");
				return(0);

			default:
				fprintf(stderr, "%s: invalid option -- %c\n", argv[0], c) ;
				fprintf(stderr, "Try '%s --help' for more information.\n", argv[0]) ;
				return(-2) ;
		};
	} ;

	return 0;
} ;

// temperature functions...
float cel2fah( float cel )
{
	return ( cel * 1.8 ) + 32 ;
} ;

float fah2cel( float fah )
{
	return ( fah - 32 ) / 1.8 ;
} ;

float kel2cel( float kel )
{
	return kel - 273.15 ;
} ;

float cel2kel( float cel )
{
	return cel + 273.15 ;
} ;

float kel2fah( float kel )
{
	return ( ( ( kel - 273.15 )*1.8 ) + 32 ) ;
} ;

float fah2kel( float cel )
{
	return ( ( (cel-32) * 5/9 ) + 273.15 ) ;
} ;
