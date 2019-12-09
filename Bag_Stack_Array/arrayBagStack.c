#include "arrayBagStack.h"
#include <stddef.h>
#include <assert.h>
#include <stdlib.h>

/* Bag Implementation */
void initBag (struct arrayBagStack * b){

	/* Insert your code */
 /* You have to initialize the count variable to 0 only */
 b->count = 0;
 b->data[0] = 0;

} 
void addBag (struct arrayBagStack * b, TYPE v) {

	/* Insert your code */
/* add the value to the end of the array */
    if (b->count < MAX_SIZE)
    {
        b->data[b->count -1] = v;
        b->count++;
    }
}

int containsBag (struct arrayBagStack * b, TYPE v) {

	for (int i = 0; i < b->count; i++)
    {
        if (b->data[i] == v)
        {
            return i;
        }
    }
    return -1;
}

void removeBag (struct arrayBagStack * b, TYPE v) {

	int idx = containsBag(b, v);

    if (idx >= 0)
    {
        for (int i = idx; i < b->count -1; i++)
        {
            b->data[i] = b->data[i+1];
        }
        b->count--;
    }
} 

int sizeBag (struct arrayBagStack * b) {

	int cnt = 0;
    while (b->data[cnt] != NULL)
    {
        cnt++;
    }
    return cnt;
} 


/* Stack Implementation */
void pushStack (struct arrayBagStack * b, TYPE v) {

	/* Insert your code */
    addBag(b, v);

}
TYPE topStack (struct arrayBagStack * b) {

	/* Insert your code */
    if (b->count >0)
    {
        /* code */
        return b->data[b->count - 1];
    }
} 

void popStack (struct arrayBagStack * b) {

	/* Insert your code */
    if (b->count > 0)
    {
        /* code */
        b->data[b->count-1] = 0;
        b->count --;
    }
}


int isEmptyStack (struct arrayBagStack * b) {

	/* Insert your code */
    if (b->count > 0)
    {
        /* code */
        return 1;
    } else
    {
        return 0;
    }
} 
