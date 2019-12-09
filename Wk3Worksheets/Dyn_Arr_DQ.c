#ifndef TYPE

#define TYPE int
#define TYPE_SIZE sizeof(int)
#define TYPE int
#define EQ(a, b) (a == b)

#endif

#include <stddef.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

struct deque
{
    TYPE *data;
    int capacity;
    int size;
    int beg;
};

void _dequeSetCapacity(struct deque *d, int newCap)
{
    int i;
    /* Create a new underlying array*/
    TYPE *newData = (TYPE *)malloc(sizeof(TYPE) * newCap);
    assert(newData != 0);
    /* copy elements to it */
    int j = d->beg;
    for (i = 0; i < d->size; i++)
    {
        newData[i] = d->data[j];
        j = j + 1;
        if (j >= d->capacity)
            j = 0;
    }
    /* Delete the oldunderlying array*/
    free(d->data);
    /* update capacity and size and data*/
    d->data = newData;
    d->capacity = newCap;
    d->beg = 0;

}

void dequeFree(struct deque *d)
{
    free(d->data);
    d->size = 0;
    d->capacity = 0;
}

void dequeInit(struct deque *d, int initCapacity)
{
    d->size = d->beg = 0;
    d->capacity = initCapacity;
    assert(initCapacity > 0);
    d->data = (TYPE *)malloc(initCapacity * sizeof(TYPE));
    assert(d->data != 0);
}

int dequeSize(struct deque *d) { 
    return d->size; 
    }

void dequeAddFront(struct deque *d, TYPE newValue)
{
    if (d->size >= d->capacity)
        _dequeSetCapacity(d, 2 * d->capacity);
}

void dequeAddBack(struct deque *d, TYPE newValue)
{
    if (d->size >= d->capacity)
        _dequeSetCapacity(d, 2 * d->capacity);
}

TYPE dequeFront(struct deque *d)
{
    if (dequeSize(d) > 0)
    {       
        return d->data[d->beg];
    }
    return 0;
}

TYPE dequeBack(struct deque *d)
{
    if (dequeSize(d) > 0)
    {
        int idx = d->size + d->beg -1;
        if (idx >= d->capacity)     
        {
            idx = idx - d->capacity;
        }
        return d->data[idx];
    }
    return 0;
}

void dequeRemoveFront(struct deque *d)
{
    if (dequeSize(d) > 0)
    {
        if (d->beg == d->capacity - 1)
        {
            d->beg = 0;
        } else
        {
            d->beg++;
        }
        d->size--;
    }
}

void dequeRemoveBack(struct deque *d)
{
    if (dequeSize(d) > 0)
    {
        d->size--;
    }
}

int main(int argc, char** argv){

   struct deque * dq = malloc(sizeof(struct deque));

   dequeInit(dq,4);

   printf("Add 5 to the back.\n");
   dequeAddBack(dq,5);
   printf("Back of queue = %i\n",dequeBack(dq));
   printf("Front of queue = %i\n", dequeFront(dq));
   printf("Beginning = %i\n", dq->beg);
   
   printf("Add 6 to the front.\n");
   dequeAddFront(dq,6);
   printf("Back of queue = %i\n",dequeBack(dq));
   printf("Front of queue = %i\n", dequeFront(dq));
   printf("Beginning = %i\n", dq->beg);

   printf("Add 9 to the back.\n");
   dequeAddBack(dq,9);
   printf("Back of queue = %i\n",dequeBack(dq));
   printf("Front of queue = %i\n", dequeFront(dq));
   printf("Beginning = %i\n", dq->beg);
   
   printf("Add 13 to the front.\n");
   dequeAddFront(dq,13);
   printf("Back of queue = %i\n",dequeBack(dq));
   printf("Front of queue = %i\n", dequeFront(dq));
   printf("Beginning = %i\n", dq->beg);
   
   printf("Add 2 to the back.\n");
   dequeAddBack(dq,2);
   printf("Back of queue = %i\n",dequeBack(dq));
   printf("Front of queue = %i\n", dequeFront(dq));
   printf("Beginning = %i\n", dq->beg);

   printf("Removing from the front.\n");
   dequeRemoveFront(dq);
   printf("Back of queue = %i\n",dequeBack(dq));
   printf("Front of queue = %i\n", dequeFront(dq));
   printf("Beginning = %i\n", dq->beg);
   
   printf("Removing from the back.\n");
   dequeRemoveBack(dq);
   printf("Back of queue = %i\n",dequeBack(dq));
   printf("Front of queue = %i\n", dequeFront(dq));
   printf("Beginning = %i\n", dq->beg);

   printf("Removing from the back.\n");
   dequeRemoveBack(dq);
   printf("Back of queue = %i\n",dequeBack(dq));
   printf("Front of queue = %i\n", dequeFront(dq));
   printf("Beginning = %i\n", dq->beg);
   
   printf("Removing from the back.\n");
   dequeRemoveBack(dq);
   printf("Back of queue = %i\n",dequeBack(dq));
   printf("Front of queue = %i\n", dequeFront(dq));
   printf("Beginning = %i\n", dq->beg);
   
   printf("Removing from the back.\n");
   dequeRemoveBack(dq);
   printf("Back of queue = %i\n",dequeBack(dq));
   printf("Front of queue = %i\n", dequeFront(dq));
   printf("Beginning = %i\n", dq->beg);
   
   /*dequeFree(dq);*/
   return 0;
}