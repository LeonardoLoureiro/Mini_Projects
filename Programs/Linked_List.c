#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int number ;
	struct node *next ;
} node ;


int main()
{
	// start of linked list
	node *list_start = NULL ;

	// allocate first node
	node *n = malloc( sizeof(node) ) ;
	
	// check if variable was allocated properly
	// if not then end the program
	if (n == NULL)
	{
		 return 1 ;
	} ;

	n->number = 34 ;
	n->next = NULL ;
	// setting where the linked list starts
	list_start = n ;

	// Allocating second node
	n = malloc( sizeof(node) ) ;
	if ( n == NULL )
	{
		 return 1 ;
	} ;

	n->number = 22 ;
	n->next = NULL ;
	list_start->next = n ;

	// Printing list so far:
	for (node *tmp = list_start ; tmp != NULL ; tmp = tmp->next)
	{
		 printf("%d\n", tmp->number) ;
	} ;

	free(n) ;
	free(list_start) ;	 
	return 0 ;
} ;

