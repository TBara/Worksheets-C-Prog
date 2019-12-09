#include <stddef.h>
#include <assert.h>
#include <stdlib.h>

#include "Linked_List_Q.h"

struct link
{
    TYPE value;
    struct link *next;
};

struct listQueue
{
    struct link *firstLink;
    struct link *lastLink;
};

void listQueueInit(struct listQueue *q)
{
    struct link *lnk = (struct link *)malloc(sizeof(struct link));

    assert(lnk != 0); /* lnk is the sentinel */
    lnk->next = 0;
    q->firstLink = q->lastLink = lnk;
}

//Check if list is empty
int listQueueIsEmpty(struct listQueue *q)
{
    return q->firstLink == q->lastLink;
}

//Add elements to the tail of the list
void listQueueAddBack(struct listQueue *q, TYPE e)
{
    struct link * lnk = (struct link *)malloc(sizeof(struct link));
    assert(lnk != 0);

    lnk->next = 0;
    lnk->value = e;

    q->lastLink->next = lnk;
    q->lastLink = lnk;
}

//Return element in front of the list
TYPE listQueueFront(struct listQueue *q)
{   
    return q->firstLink->value;
}

//Remove elements from the front of the list
void listQueueRemoveFront(struct listQueue *q)
{
    assert(!listQueueIsEmpty(q));
    struct link * lnk = q->firstLink->next;
    
    q->firstLink->next = lnk->next;

    if (q->firstLink->next == 0)    
    {   
        q->lastLink = q->firstLink;
    }
    free(lnk);
}

int main(){

       struct listQueue * q = malloc(sizeof(struct listQueue));

   listQueueInit(q);

   printf("List Queue Front = %i\n", listQueueFront(q));
   printf("Is List Queue empty? = %i\n", listQueueIsEmpty(q));

   printf("Add 3 to the back of the list.\n");
   listQueueAddBack(q,3);

   printf("List Queue Front = %i\n", listQueueFront(q));
   printf("Is List Queue empty? = %i\n", listQueueIsEmpty(q));

   printf("Add 6 to the back of the list.\n");
   listQueueAddBack(q,6);

   printf("List Queue Front = %i\n", listQueueFront(q));
   printf("Is List Queue empty? = %i\n", listQueueIsEmpty(q));

   printf("Remove from the front.\n");
   listQueueRemoveFront(q);

   printf("List Queue Front = %i\n", listQueueFront(q));
   printf("Is List Queue empty? = %i\n", listQueueIsEmpty(q));

   free(q);

   return 0;
}