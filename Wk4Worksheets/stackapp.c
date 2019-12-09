/****************************************************************************
 ** Author: Tom Barabasz
 ** Asignments: Assignmant 2 CS261
 ** Date:		10/21/2019
 ** Description: Program to check if a supplied string contains balanced sets of (, [, { characters 
*****************************************************************************/

/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
			
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}
/*****************************************************************
 *  Returns boolean (encoded in an int) demonstrating whether or not char 
 * 	parameters a, b are a matching set 

	param:	char a, char b
	pre:	none
	post:	none
	ret:	1 if empty, otherwise 0

 * **************************************************************/
int charMatch(char a, char b){

	if (b == '(' && a == ')')
	{
		return 1;
	} else if ( b == '[' && a == ']')
	{
		return 1;
	} else if (b == '{' && a == '}')
	{
		return 1;
	} else
	{
		return 0;
	}
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: 	
	post:	
*/
int isBalanced(char* s)
{
	/* FIXME: You will write this function */
	if (s[0] == '\0')
		return 1;
	
	dynArray *dyn = newDynArr(50);

	char c = nextChar(s);
	char topStk = '\0';

	while (c != '\0')
	{
		if (!isEmptyDynArr(dyn))
		{
			topStk = topDynArr(dyn);
		}
		
		//If (, [, or { then push it onto the stack
		if (c == '(' || c == '[' || c =='{')
		{
			pushDynArr(dyn, c);

		} else if (c == ')' || c == ']' || c =='}')
		{
			if (isEmptyDynArr(dyn))
			{
				//No closing character to compare
				return 0;
			} else if (!charMatch(c, topStk))
			{
				return 0;
			} else if (charMatch(c, topStk))
			{
				//chars match, pop the top one and move on
				popDynArr(dyn);
			} else
			{
				return 0;
			}
			
		}
		c = nextChar(s);
	}
	if (isEmptyDynArr(dyn))
	{
		return 1;
	} 
	return 0;
}

int main(int argc, char* argv[]){
	
	char* s= argv[1];	
	int res;
	
	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}

