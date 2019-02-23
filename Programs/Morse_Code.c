#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SUM_OF_CHARS 38 // if adding or removing from csv file, change this num.

typedef struct
{
    char letter ;
    char morse[8] ; // morse version is max len of ~7, +1 for '\0'
} morse_char ;
morse_char lookup_table[SUM_OF_CHARS] ;

void load_chars() ;

void encrypt( char *message ) ;
void decrypt( char *message ) ;
char *char2morse( char *letter ) ;
char morse2char( char *morse ) ;
void append( char *str, char letter ) ;

int main()
{
    int choice ;
    char *message ;

    load_chars() ;

    printf("Choices:\n1) Encrypt\n2) Decrypt\n> ") ;
    scanf("%d", &choice) ;

    getchar() ;

    printf("Enter message:\n>> ") ;
    scanf("%[^\n]s", message) ;

    switch (choice)
    {
        case 1: encrypt( message ) ; break ;
        case 2: decrypt( message ) ; break ;

        default: printf("Invalid choice.\n") ;
    } ;

  return 0;
} ;

void encrypt( char *message )
{
    char *plain_char ;

    printf(">> ") ;
    for ( plain_char = message ; *plain_char != '\0' ; ++plain_char )
    {
        if ( *plain_char == ' ' )
        {
            printf("/ ") ;
            continue ;
        } ;

        printf("%s ", char2morse( plain_char )) ;
    } ;
    printf("\n") ;
} ;

void decrypt( char *message )
    {
    char *morse_char, buffer[10] ;
    int last = strlen( message ) - 1 ;

    // when the loop iterates over the string, it reaches the end but does not
    // translate the last char because chars are only translated during whitespace,
    // this appending at the end of the string compensates for this. Of course
    // if the user puts a whitespace at the end, be it mistake or not, then the
    // the program will run into an error so it must check it first.
    if ( message[last] != ' ' ) append( message, ' ' ) ;

    // the point of the loop is to iterate through each dot, slash and
    // dash and append it to a char array until it encounters a whitespace,
    // then it translate the morse code into a char. When it encounters a
    // '/' then it prints a whitespace.
    printf(">> ") ;
    for ( morse_char = message ; *morse_char != '\0' ; ++morse_char )
    {
        if ( *morse_char != ' ' )
        {
            append( buffer, *morse_char ) ;
            continue ;
        } ;

        // the forward slash is used to represent whitespace
        if ( buffer[0] == '/' )
        {
            printf(" ") ;
            strcpy( buffer, "" ) ;
            continue ;
        } ;

        printf("%c", morse2char( buffer )) ;
        strcpy( buffer, "" ) ;
    } ;

    printf("\n") ;
} ;

// This function loads all the chars in the csv file into a struct array...
void load_chars()
    {
    int i = 0 ;
    char line[20] ;
    char letter, morse[8] ;

    FILE *csv_f ;

    csv_f = fopen("Morse_code.csv", "r") ;

    while ( fgets(line, 20, csv_f) )
    {
        sscanf( line, "%c %s", &letter, morse ) ;

        lookup_table[i].letter  = tolower( letter ) ;
        strcpy( lookup_table[i].morse, morse ) ;

        ++i ;
    } ;
    fclose( csv_f ) ;
} ;

char *char2morse( char *letter )
{
    int i ;
    char morse[8], buffer ;
    buffer = tolower( *letter ) ;

    for ( i = 0 ; i < SUM_OF_CHARS ; ++i )
    {
        if (lookup_table[i].letter == buffer )
        {
            return (char *) lookup_table[i].morse ;
        } ;
    } ;
} ;

char morse2char( char *morse )
{
    int i ;

    for (i = 0 ; i < SUM_OF_CHARS ; i++)
    {
        if ( strcmp( morse, lookup_table[i].morse ) == 0 )
        {
            return lookup_table[i].letter ;
        } ;
    } ;
} ;

void append( char *str, char letter )
{
    int len = strlen( str ) ;
    str[len] = letter ;
    str[len+1] = '\0' ;
} ;
