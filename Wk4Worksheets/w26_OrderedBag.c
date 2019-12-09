# ifndef TYPE

# define TYPE  int
# define TYPE_SIZE sizeof(int)
# define TYPE int
# define EQ(a, b) (a == b)

# endif 
#include "dynArray.h"
#include <assert.h>
#include <stddef.h>
#include <assert.h>
#include <stdlib.h>

/*Assume you have access to all existing dynArr functions */
/* _binarySearch is also included in dynArr.c now as an internal function! */
int _binarySearch(TYPE *data, int size, TYPE testValue);
void dyArrayAddAt(struct dynArray *da, int index, TYPE newElement);

/* These are the new functions to take advantage of the ordered dynamic array
and available to the end user , so they will be declared in the .h file */
int dyArrayBinarySearch(struct dynArray *da, TYPE testValue)
{
    return _binarySearch(da->data, da->size, testValue);
}

void orderedArrayAdd(struct dynArray *da, TYPE newElement)
{
    int index = _binarySearch(da->data, da->size, newElement);
    dyArrayAddAt(da, index, newElement); /* takes care of resize if necessary*/
}

/* you must complete the following */
int orderedArrayContains(struct dynArray *da, TYPE testElement)
{
    assert(da != 0);
    int idx = _binarySearch(da->data, da->size, testElement);
    return da->data[idx] == testElement;
}

void orderedArrayRemove(struct dynArray *da, TYPE testElement)
{
    assert(da != 0);
    int idx = _binarySearch(da->data, da->size, testElement);
    if (da->data[idx] == testElement)
    {
        removeAtDynArr(da, idx);
    }
}

int _binarySearch(TYPE *data, int size, TYPE testValue)
{
    int low = 0;
    int high = size;
    int mid;
    while (low < high)
    {
        mid = (low + high) / 2;
        if (LT(data[mid], testValue))
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

void dyArrayAddAt(struct dynArray *da, int index, TYPE newElement)
{
    int i;
    assert(index >= 0 && index <= da->size);
    if (da->size >= da->capacity)
        dynArrSetCapacity(da, da->capacity*2);

    for (int i = index; i < da->size; i++)
    {
        da->data[i + 1] = da->data[i];
    }
    da->data[index] = newElement;
}

int main() {
    return 0;
}