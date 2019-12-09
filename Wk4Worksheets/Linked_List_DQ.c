#include <stddef.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "Linked_List_DQ.h"

struct dlink
{
    TYPE value;
    struct dlink *next;
    struct dlink *prev;
};

struct linkedList
{
    int size;
    struct dlink *frontSentinel;
    struct dlink *backSentinel;
};

void _addBefore (struct linkedList *q, struct dlink *lnk, TYPE e);
void _removeLink (struct linkedList *q, struct dlink *lnk);
void linkedListRemoveFront (struct linkedList *q);
int linkedListIsEmpty (struct linkedList *q);

/* these functions are written for you */
void linkedListInit(struct linkedList *q)
{
    q->frontSentinel = (struct dlink *)malloc(sizeof(struct dlink));
    assert(q->frontSentinel != 0);
    q->backSentinel = (struct dlink *)malloc(sizeof(struct dlink));
    assert(q->backSentinel);
    q->frontSentinel->next = q->backSentinel;
    q->backSentinel->prev = q->frontSentinel;
    q->size = 0;
}

int linkedListIsEmpty(struct linkedList *q)
{
    return q->size == 0;
}

void _removeLink(struct linkedList *q, struct dlink *lnk)
{
    if (!linkedListIsEmpty(q))
    {
        lnk->prev->next = lnk->next;
        lnk->next->prev = lnk->prev;

        q->size--;
        free(lnk);
    }
    
}

void linkedListRemoveFront(struct linkedList *q)
{
    assert(!linkedListIsEmpty(q));
    _removeLink(q, q->frontSentinel->next);
}

void linkedListFree(struct linkedList *q)
{
    while (q->size > 0)
        linkedListRemoveFront(q);
    free(q->frontSentinel);
    free(q->backSentinel);
    q->frontSentinel = q->backSentinel = NULL;
}

/* _addLink places a new link BEFORE the provide link, lnk */
void _addLink(struct linkedList *q, struct dlink *lnk, TYPE e)
{
    //Allocate new link
    struct dlink * newLnk = (struct dlink *)malloc(sizeof(struct dlink));
    assert(newLnk != 0);

    //Point the link before lnk to newLnk
    lnk->prev->next = newLnk;

    //Set newlnk's prev & next, then set its value
    newLnk->prev = lnk->prev;
    newLnk->next = lnk;
    newLnk->value = e;

    //Point the lnk at newLnk and increase list size
    lnk->prev = newLnk;
    q->size ++;
}




void linkedListAddFront(struct linkedList *q, TYPE e)
{
    _addLink(q, q->frontSentinel->next, e);
}

void linkedListAddback(struct linkedList *q, TYPE e)
{
    _addLink(q, q->backSentinel, e);
}

void linkedListRemoveBack(struct linkedList *q)
{
    assert(!linkedListIsEmpty(q));
    _removeLink(q, q->backSentinel->prev);
}

/* write addLink and removeLink. Make sure they update the size field correctly */

TYPE linkedListFront(struct linkedList *q)
{
    if (!linkedListIsEmpty(q))
    {
        return q->frontSentinel->next->value;
    }
    return 0;
}

TYPE linkedListBack(struct linkedList *q)
{
    if (!linkedListIsEmpty(q))
    {
        return q->backSentinel->prev->value;
    }
    return 0;
}

int main(int argc, char**argv) {

    struct linkedList * l = malloc(sizeof(struct linkedList));
   linkedListInit(l);

   printf("Is linked list empty? = %i\n", linkedListIsEmpty(l));
   printf("Add 5 to the front.\n");
   linkedListAddFront(l,5);
   
   printf("Front of the list = %i\n", linkedListFront(l));
   printf("Back of the list = %i\n", linkedListBack(l));
   
   printf("Add 9 to the front.\n");
   linkedListAddFront(l,9);
   printf("Front of the list = %i\n", linkedListFront(l));
   printf("Back of the list = %i\n", linkedListBack(l));
   printf("Is linked list empty? = %i\n", linkedListIsEmpty(l));
   
   printf("Add 12 to the front.\n");
   linkedListAddFront(l,12);
   printf("Front of the list = %i\n", linkedListFront(l));
   printf("Back of the list = %i\n", linkedListBack(l));
   
   printf("Add 20 to the back.\n");
   linkedListAddback(l,20);
   printf("Front of the list = %i\n", linkedListFront(l));
   printf("Back of the list = %i\n", linkedListBack(l));
   
   printf("Remove from the back.\n");
   linkedListRemoveBack(l);
   printf("Front of the list = %i\n", linkedListFront(l));
   printf("Back of the list = %i\n", linkedListBack(l));
   
   printf("Remove from the front.\n");
   linkedListRemoveFront(l);
   printf("Front of the list = %i\n", linkedListFront(l));
   printf("Back of the list = %i\n", linkedListBack(l));

   linkedListFree(l);
   
    return 0;
}   