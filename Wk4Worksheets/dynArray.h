/****************************************************************************
 ** Author: Tom Barabasz
 ** Asignments: Assignmant 2 CS261
 ** Date:		10/21/2019
 ** Description: Contains declarations for dynamic array functions
*****************************************************************************/


/* 	dynamicArray_a1.h : Dynamic Array implementation. */
#ifndef DYNAMIC_ARRAY_INCLUDED
#define DYNAMIC_ARRAY_INCLUDED 1

#ifndef __TYPE
#define __TYPE
# define TYPE      int
# define TYPE_SIZE sizeof(int)
# endif

# ifndef LT
# define LT(A, B) ((A) < (B))
# endif

# ifndef EQ
# define EQ(A, B) ((A) == (B))
# endif

struct dynArray
{
	TYPE *data;		/* pointer to the data array */
	int size;		/* Number of elements in the array */
	int capacity;	/* capacity ofthe array */
};

typedef struct dynArray dynArray;

/* Dynamic Array Functions */
void initDynArr(dynArray *v, int capacity);	
dynArray *newDynArr(int cap);

void freeDynArr(dynArray *v);
void deleteDynArr(dynArray *v);
void dynArrSetCapacity(dynArray *v, int newCap);
int sizeDynArr(dynArray *v);

void addDynArr(dynArray *v, TYPE val);
TYPE getDynArr(dynArray *v, int pos);
void putDynArr(dynArray *v, int pos, TYPE val);
void swapDynArr(dynArray *v, int i, int  j);
void removeAtDynArr(dynArray *v, int idx);

/* Stack interface. */
int isEmptyDynArr(dynArray *v);
void pushDynArr(dynArray *v, TYPE val);
TYPE topDynArr(dynArray *v);
void popDynArr(dynArray *v);

/* Bag Interface */	
/* Note addDynArr is already declared above*/
int containsDynArr(dynArray *v, TYPE val);
void removeDynArr(dynArray *v, TYPE val);

#endif
